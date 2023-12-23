using System.Data.SqlTypes;
using System.Diagnostics.SymbolStore;
using System.Globalization;

public class Solution {
    public string LongestPalindrome(string s) {
        if (IsPalindrome(ref s, 0, s.Length))
        {
            return s;
        }

        int start = 0, end = 0;
        for (int i = 0; i < s.Length; i++) 
        {
            for (int j = i; j < s.Length || s.Length - j - i < end - start; j++)
            {
                if (s.Length - j - i > end - start && IsPalindrome(ref s, i, s.Length - j))
                {   
                    end = s.Length - j;
                    start = i;
                    break;
                }
            }
        }

        return s.Substring(start, end);
    }

    private bool IsPalindrome(ref string s, int start, int end) 
    {
        for (int i = start; i < end; i++) {
            if (s[i] != s[end - 1 - i]) {
                return false;
            }
        }

        return true;
    }

    public static void Main(string[] args) {
        Solution s = new();

        Console.WriteLine(s.LongestPalindrome("cbbd"));
    }
}