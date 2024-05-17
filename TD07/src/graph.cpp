#include "graph.hpp"
#include <unordered_map>
#include <iostream>

void Graph::WeightedGraph::add_vertex(int id)
{
   auto it = adjacency_list.find (id);

    if (it == adjacency_list.end())
        adjacency_list[id];
    else
        std::cout << id << " is already in the graph" << std::endl;
}

void Graph::WeightedGraph::add_directed_edge(int from, int to, float weight = 1.0F)
{
    add_vertex(to);
    adjacency_list[from].push_back({to, weight});
}

void Graph::WeightedGraph::add_undirected_edge(int const from, int const to, float const weight = 1.0f)
{
    add_directed_edge(from, to, 1.0F);
    add_directed_edge(to, from, 1.0F);
}

Graph::WeightedGraph Graph::build_from_adjacency_matrix(const std::vector<std::vector<float>> &adjacency_matrix)
{
    // PROTOCOL
    // On parcourt la matrice d'adjacence donnée
    // On convertit les nombres en nombres dans une liste d'adjacence
    // Une fois la liste faite, on parcourt la liste pour créer un graphe

    // TODO : trouver comment insérer la valeur dans la unordered map. Ne pas oublier de créer une node à chaque fois

    std::unordered_map<int, std::vector<WeightedGraphEdge>> adjacency_list{};

    for (int x = 0; x < adjacency_matrix.size(); x++)
    {
        for (int y = 0; y < adjacency_matrix[x].size(); y++)
        {
            if (adjacency_matrix[x][y] != 0)
            {
                auto it = adjacency_list.find(x-1);

                if (it == adjacency_list.end())
                    adjacency_list[x-1];

                adjacency_list[x-1].push_back({y-1, adjacency_matrix[x][y]});
            }
        }
    }
}