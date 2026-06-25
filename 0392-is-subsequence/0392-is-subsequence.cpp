class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0; // Pointer for s
        int j = 0; // Pointer for t
        
        // Scan through both strings
        while (i < s.length() && j < t.length()) {
            // If characters match, move the pointer for s forward
            if (s[i] == t[j]) {
                i++;
            }
            // Always move the pointer for t forward
            j++;
        }
        
        // If i reached the end of s, then s is a valid subsequence of t
        return i == s.length();
    }
};