#include <iostream>
#include <vector>

/*
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.s
*/


class Solution {
public:
    std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges) {
        // create vector of all visited nodes
        std::vector<bool> visited(n);
        std::vector<int> vertices;

        // we check all the nodes that can be visited, this way we find the unreachable nodes
        // those nodes must be in set of vertices
        for (std::vector<int>& edge : edges) {
            visited[edge[1]] = true;
        }

        // add all unreachable nodes to set of verticies
        for (int i =0;i<n;i++) {
            if (!visited[i]) {
                vertices.push_back(i);
            }
        }

        // return vertices
        return vertices;
    }
};


int main() {
    return 0;
}