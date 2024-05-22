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

// void Graph::Dijkstra_algorithm(int start, int end, int nbr_of_nodes)
// {
//     std::queue<int>nodes_to_visit;
//     std::priority_queue<int>pq;
//     std::unordered_map<int, int>association_table;
//     int current_node{};
//     std::vector<int>visited_edges{};

//     nodes_to_visit.push(start);

//     while (!(nodes_to_visit.empty()))
//     {
//         // Garder en mémoire la node
//         current_node = nodes_to_visit.front();

//         // ajouter la node à la liste des sommets visités
//         visited_edges.push_back(current_node);

//         // retirer le premier élt de la file
//         nodes_to_visit.pop();

//         // trouver la node dans la adjacency_list
//         auto it = adjacency_list.find (current_node);

//         // trouver les nodes liées
//         auto adjacencies = (*it).second;

//         // Ajouter les nodes liées dans la pile
//         for (int i = 0; i < adjacencies.size(); i++)
//         {
//             nodes_to_visit.push(adjacencies[i].to);
//         }
//     }
// }

// void Graph::Dijkstra_algorithm(int start, int end, int nbr_of_nodes)
// {
//     // Initialize all distances
//     for (int i = 0; i < nbr_of_nodes; i++)
//     {
//         /* code */
//     }

//     // Output
//     for (int visited_edge : visited_edges)
//     {
//         std::cout << "The minimum distance from " << start << " to " << end << " = " << distance << std::endl;
//     }
// }

void Graph::Dijkstra_algorithm(int start, int end, int nbr_of_nodes)
{
    std::unordered_map<int, std::pair<int, int>>distances{};
    std::priority_queue<std::pair<int, int>>to_visit{};
    int current_node{};

    to_visit.push(std::make_pair(0, start));

    while (!(to_visit.empty()))
    {
        // Garder en mémoire la node
        current_node = to_visit.top().second;

        // ajouter la node à la liste des sommets visités
        distances.insert(std::make_pair(start, std::make_pair(0, start))); 

        // retirer le premier élt de la file
        to_visit.pop();

        // trouver la node dans la adjacency_list
        auto it = adjacency_list.find (current_node);

        // trouver les nodes liées
        auto adjacencies = (*it).second;

        // Ajouter les nodes liées dans la pile
        for (int i = 0; i < adjacencies.size(); i++)
        {
            nodes_to_visit.push(adjacencies[i].to);
        }
    }

    // TODO: end algorithm - trouver les nodes voisines dans adjacency_list puis appliquer le traitement selon si elles ont été visitées ou non
}