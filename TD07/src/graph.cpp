#include "graph.hpp"
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>
#define FAR_AWAY 999

void Graph::WeightedGraph::add_vertex(int id)
{
   auto it = adjacency_list.find (id);

    if (it == adjacency_list.end())
        adjacency_list[id];
    else
        std::cout << id << " is already in the graph" << std::endl;
}

void Graph::WeightedGraph::add_directed_edge(int from, int to, float weight)
{
    add_vertex(to);
    adjacency_list[from].push_back({to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight)
{
    add_directed_edge(from, to, 1.0F);
    add_directed_edge(to, from, 1.0F);
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(const std::vector<std::vector<float>> &adjacency_matrix)
{
    Graph::WeightedGraph output_graph{};

    for (int x = 0; x < adjacency_matrix.size(); x++)
    {
        for (int y = 0; y < adjacency_matrix.size(); y++)
        {
            if (adjacency_matrix[x][y] != 0)
            {
                output_graph.add_directed_edge(x, y, adjacency_matrix[x][y]);
            }
        }
    }
    return output_graph;
}

void Graph::WeightedGraph::print_DFS(int const start) const
{
    // TODO : translate comments

    std::stack<int> stack;
    int current_node{};
    std::vector<int>visited_edges{};
    stack.push(start);

    while (!(stack.empty()))
    {
        // ajouter la node à la liste des sommets visités
        visited_edges.push_back(stack.top());

        // Garder en mémoire la node
        current_node = stack.top();

        // retirer le dernier élt de la pile
        stack.pop();

        // trouver la node dans la adjacency_list
        auto it = adjacency_list.find (current_node);

        // trouver les nodes liées
        auto adjacencies = (*it).second;

        // Ajouter les nodes liées dans la pile
        for (int i = 0; i < adjacencies.size(); i++)
        {
            stack.push(adjacencies[i].to);
        }
    }

    for (int visited_edge : visited_edges)
    {
        std::cout << visited_edge << std::endl;
    }
}

void Graph::WeightedGraph::print_BFS(int const start) const
{
    std::queue<int> queue;
    queue.push(start);

    int current_node{};
    std::vector<int>visited_edges{};

    while (!(queue.empty()))
    {
        // Garder en mémoire la node
        current_node = queue.front();

        // ajouter la node à la liste des sommets visités
        visited_edges.push_back(current_node);

        // retirer le premier élt de la file
        queue.pop();

        // trouver la node dans la adjacency_list
        auto it = adjacency_list.find (current_node);

        // trouver les nodes liées
        auto adjacencies = (*it).second;

        // Ajouter les nodes liées dans la pile
        for (int i = 0; i < adjacencies.size(); i++)
        {
            queue.push(adjacencies[i].to);
        }
    }

    for (int visited_edge : visited_edges)
    {
        std::cout << visited_edge << std::endl;
    }
}

std::unordered_map<int, std::pair<float, int>> Graph::dijkstra(Graph::WeightedGraph const& graph, int const& start, int const end)
{
    int current_node{};

    // On crée un tableau associatif pour stocker les distances les plus courtes connues pour aller du sommet de départ à chaque sommet visité
    // La clé est l'identifiant du sommet et la valeur est un pair (distance, sommet précédent)
    std::unordered_map<int, std::pair<float, int>> distances {};

    // On crée une file de priorité pour stocker les sommets à visiter
    // la pair contient la distance pour aller jusqu'au sommet et l'identifiant du sommet
    // Ce type compliqué permet d'indiquer que l'on souhaite trier les éléments par ordre croissant (std::greater) et donc les éléments les plus petits seront au début de la file (top) (Min heap)
    std::priority_queue<std::pair<float, int>, std::vector<std::pair<float, int>>, std::greater<std::pair<float, int>>> to_visit {};

    // 1. On ajoute le sommet de départ à la liste des sommets à visiter avec une distance de 0 (on est déjà sur le sommet de départ)
    to_visit.push(std::make_pair(0, start));

    // ajouter la node à la liste des sommets visités
    distances.insert(std::make_pair(start, std::make_pair(0, start))); 

    // Tant qu'il reste des sommets à visiter
    while (!(to_visit.empty()))
    {
        // 2. On récupère le sommet le plus proche du sommet de départ dans la liste de priorité to_visit
        current_node = to_visit.top().second;

        // 3.Si on atteins le point d'arrivé, on s'arrête
        if (current_node == end)
        {
            return distances;
        }

        // 3. On parcourt la liste des voisins (grâce à la liste d'adjacence) du nœud courant
        for (Graph::WeightedGraphEdge edge : graph.adjacency_list.find(current_node)->second) 
        {
            // 4. on regarde si le nœud existe dans le tableau associatif (si oui il a déjà été visité)
            auto find_node {distances.find(edge.to)};
            bool visited{};

            if (find_node == distances.end())
            {
                visited = 0;
            }
            else
            {
                visited = 1;
            }

            if (!visited)
            {
                // 5. Si le nœud n'a pas été visité, on l'ajoute au tableau associatif en calculant la distance pour aller jusqu'à ce nœud
                // la distance actuelle + le point de l'arrête)
                distances.insert(std::make_pair(edge.to, std::make_pair(distances.find(current_node)->second.first + edge.weight, current_node)));
                
                // 6. On ajout également le nœud de destination à la liste des nœud à visiter (avec la distance également pour prioriser les nœuds les plus proches)
                to_visit.push(std::make_pair(edge.weight, edge.to));
            }
            else
            {
                // 7. Si il a déjà été visité, On teste si la distance dans le tableau associatif est plus grande
                // Si c'est le cas on à trouvé un plus court chemin, on met à jour le tableau associatif et on ajoute de nouveau le sommet de destination dans la liste "à visiter"
                if (distances.find(current_node)->second.first + edge.weight < distances.find(edge.to)->second.first)
                {
                    distances.find(edge.to)->second.first = distances.find(current_node)->second.first + edge.weight;
                    distances.find(edge.to)->second.second = current_node;
                }
            } 
        }
    }

    return distances;
}