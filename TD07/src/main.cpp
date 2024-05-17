#include "graph.hpp"
#include <vector>

int main()
{
    // EX1 Q5 - Comparaison des graphes

    // Version 1 : avec build_from_adjacency_matrix
    const std::vector<std::vector<float>> & test_adjacency_matrix
    {
        {0, 1, 0, 0, 2},
        {0, 0, 2, 4, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0},
    };

    Graph::WeightedGraph builded_graph = Graph::build_from_adjacency_matrix(test_adjacency_matrix);
    builded_graph.print_DFS(0);

    // Version 2 : avec build_from_adjacency_matrix
    Graph::WeightedGraph other_graph;

    other_graph.add_vertex(1);
    other_graph.add_vertex(2);
    other_graph.add_vertex(3);
    other_graph.add_vertex(4);

    other_graph.add_directed_edge(0, 1, 1);
    other_graph.add_directed_edge(0, 4, 2);

    other_graph.add_directed_edge(1, 2, 2);
    other_graph.add_directed_edge(1, 3, 4);

    other_graph.add_directed_edge(2, 3, 1);
    
    other_graph.add_directed_edge(3, 4, 6);

    other_graph.print_DFS(0);

    // TODO : test other functions

    return 0;
}