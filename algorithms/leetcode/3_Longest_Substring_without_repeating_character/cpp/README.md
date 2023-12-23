# Problem

Given a string s, find the length of the longest substring without repeating characters.

# Approach
The way this is solved is by using sliding window technique. 
Basically, what we do is have 2 indexes, of last non duplicate and current character. We also store frequencies of each character inside the map.
If we find duplicate(map size is smaller than difference between current index and last non duplicate index), we remove each element until only unique are left, otherwise, we are certain that is current substring with all unique characters, so we can save it.

# Code
```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       // if the length is 0, we can just return 0 as longest substring
        if(s.length() == 0) {
            return 0;
        } 

        // So for this problem, we are using sliding windows
        // Inside this map, we store the frequncies of each character found
        std::unordered_map<char,int> frequencies;

        // we also need index for elements
        int element_index = 0;

        // longest substring length
        int max_length = 0; 

        // Now we go trough each character in string
        for (int i = 0;i < s.length(); i++) {
            // Increase the frequency
            frequencies[s[i]]++;

            // If the size of map is same as number of elements since last duplicate, we can be
            // sure that size of map is length of substring without repeating characters
            if (frequencies.size() == i - element_index + 1 && frequencies.size() > max_length) {
                max_length = frequencies.size();
                continue;
            }

            // Otherwise, we remove duplicates from map
            // This starts from last element, so basically it deletes all elements until the duplicate, including it
            while (frequencies.size() < i - element_index + 1) {
                frequencies[s[element_index]]--;
                // if the size is 0, we can also delete the element from the map
                if(frequencies[s[element_index]] == 0) {
                    frequencies.erase(s[element_index]);
                }

                element_index++;
            }
        }

        // at the end, return the maximum length of substring
        return max_length;
    }
};
```