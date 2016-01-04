#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <limits> // for numeric_limits
#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>

typedef int vertex_t;
typedef double weight_t;

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t;


class ShortestPath
{
public:
    ShortestPath(){
        max_weight = std::numeric_limits<double>::infinity();
    }
    void DijkstraComputePaths(vertex_t source,
                              const adjacency_list_t &adjacency_list,
                              std::vector<weight_t> &min_distance,
                              std::vector<vertex_t> &previous);
    std::list<vertex_t> DijkstraGetShortestPathTo(
            vertex_t vertex, const std::vector<vertex_t> &previous);

    void addEdge(adjacency_list_t &adjacency_list,int v1, int v2, int weight);
private:
    weight_t max_weight;
};

#endif // SHORTESTPATH_H
