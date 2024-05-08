#include "graph.hpp"
#include <unordered_map>
#include <iostream>

void WeightedGraph::add_vertex(int const id)
{
    std::unordered_map<int, std::vector<WeightedGraphEdge>>::const_iterator got = adjacency_list.find (id);

    if ( got == adjacency_list.end() )
        adjacency_list[id];
    else
        std::cout << id << " is already in the graph" << std::endl;
}

void WeightedGraph::add_directed_edge(int const from, int const to, float const weight = 1.0f)
{
     
}