#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
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

int main(int, char**) {
    Solution sol;

    std::vector<std::vector<int>> graph = {
      {1, 3},
      {0, 2},
      {1, 3},
      {0, 2}  
    };

    std::cout << sol.isBipartite(graph) << std::endl;
    return 0;
}
