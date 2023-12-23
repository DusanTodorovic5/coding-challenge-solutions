# Problem

Given a string `s`, return the longest `palindromic substring` in `s`.

# Approach

The idea is to use shifting window, basically take longest possible string for first character and find its palindrome. Do that for the rest.

# Code
```cs
public class Solution {
    public string LongestPalindrome(string s) {
        // There is no need to go trough process if
        // string is already palindrome
        if (IsPalindrome(s))
        {
            return s;
        }

        // Iterate trough string, for each character
        // Create window for each, and lower it until it hits 0
        string longest_palindrome = "";
        for (int i = 0; i < s.Length; i++) 
        {
            for (int j = i; j < s.Length || s.Length - j - i > longest_palindrome.Length; j++)
            {
                string substring = s.Substring(i, s.Length - j);
                if (substring.Length > longest_palindrome.Length && IsPalindrome(substring))
                {
                    longest_palindrome = substring;
                    break;
                }
            }
        }

        return longest_palindrome;
    }

    private bool IsPalindrome(string s) 
    {
        for (int i = 0; i < s.Length; i++) {
            if (s[i] != s[s.Length - 1 - i]) {
                return false;
            }
        }

        return true;
    }
}
```