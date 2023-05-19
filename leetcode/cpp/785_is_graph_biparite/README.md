# Problem

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

 - There are no self-edges (graph[u] does not contain u).
 - There are no parallel edges (graph[u] does not contain duplicate values).
 - If v is in graph[u], then u is in graph[v] (the graph is undirected).
 - The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.

A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

# Approach
Idea is to use DFS to traverse trough graph and assign different flag for each edge of current node. In case the edge has different flag, it means the graph is not bipartite

# Complexity
- Time complexity:
O(n^2)

- Space complexity:
O(n)

# Code
```
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // Initalize vector of size N with all zeros
        std::vector<int> bipartite(graph.size(), 0);

        // create stack of current nodes and their flags
        std::stack<std::pair<int, int>> stack;
        std::pair<int, int> current_node;

        // in case the graph is not fully connected, we must traverse trough other non-connected nodes
        for (int i = 0; i < graph.size(); i++) {
            if (bipartite[i]) {
                continue;
            }

            // push first node of graph to the stack
            stack.push({i, 1});
            // do iterative DFS
            while (!stack.empty()) {
                // pop the current node
                current_node = stack.top();
                stack.pop();

                // if the node is not visited yet, it will be 0, which means we need to assign a flag to it
                // if the node is visited, check if current flag is same, if not, return false
                if (!bipartite[current_node.first]) {
                    // assign the flag
                    bipartite[current_node.first] = current_node.second;

                    // for each of the edges, push to stack with flag reversed
                    for (int edge : graph[current_node.first]) {
                        stack.push({edge, -current_node.second});
                    }
                } else if (bipartite[current_node.first] != current_node.second){
                    return false;
                }
            }
        }

        // the graph is biparite
        return true;
    }
};
```