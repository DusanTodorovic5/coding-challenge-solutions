# Problem

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

# Approach
The idea is just to push openning symbols to stack and to pop closing symbols from stack. When popping, if the poped value is not of same but openning type, we just return false. We also return false in case we want to pop but stack is empty.
At the end, we return true if the stack is empty, or false in case there are leftovers.

# Complexity
This is O(n), as we go trough each character once.

# Code
```cpp
class Solution {
public:
    bool isValid(string s) {
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
```