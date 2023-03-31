#include <iostream>
#include <stack>

/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
*/

class Solution {
public:
    bool isValid(std::string s) {
        // Create a stack of symbols
        std::stack<char> symbols;
    
        // go trough each character in string of parentheses
        for (const char& c : s) {
            switch (c) {
                // in case of (, [, { we push to stack
                case '(': 
                case '[':  
                case '{': 
                    symbols.push(c);
                    break;
                // in case of ), ], } we pop and check if its empty or there is corresponding openning
                case ')':
                    if (symbols.empty() || symbols.top() != '(') {
                        return false;
                    }  
                    symbols.pop();
                    break;
                case ']':  
                    if (symbols.empty() || symbols.top() != '[') {
                        return false;
                    }  
                    symbols.pop();
                    break;
                case '}':  
                    if (symbols.empty() || symbols.top() != '{') {
                        return false;
                    }  
                    symbols.pop();
                    break;
            }
        }

        // we return whether the stack is empty or not
        // in case it is not empty, there are leftovers and string is not valid
        return symbols.empty();
    }
};


int main () {
    return 0;
}