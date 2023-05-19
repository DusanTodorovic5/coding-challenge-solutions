#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    bool isBipartite(std::vector<std::vector<int>>& graph) {
        // Initalize vector of size N with all zeros
        std::vector<int> bipartite(graph.size(), 0);
        std::stack<std::pair<int, int>> stack;
        std::pair<int, int> current_node;
        
        //for (int i = graph.size();i > 0; stack.push({--i, 1}));

        stack.push({0,1});
       
        while (!stack.empty()) {
            current_node = stack.top();
            stack.pop();

            if (!bipartite[current_node.first]) {
                bipartite[current_node.first] = current_node.second;

                for (int edge : graph[current_node.first]) {
                    stack.push({edge, -current_node.second});
                }
                // for (int i = 0;i < graph[current_node.first].size(); stack.push({graph[current_node.first][i++], -current_node.second}));
                continue;
            }
            
            if (bipartite[current_node.first] != current_node.second){
                return false;
            }
        }

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
