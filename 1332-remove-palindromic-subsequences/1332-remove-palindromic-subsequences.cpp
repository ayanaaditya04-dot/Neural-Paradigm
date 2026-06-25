class Solution {
public:
    int removePalindromeSub(string s) {
        if (s.empty()) return 0;
        
        int left = 0;
        int right = s.length() - 1;
        
        // Check if the entire string is a palindrome
        while (left < right) {
            if (s[left] != s[right]) {
                // If it's not a palindrome, we can always clear it in 2 steps
                // (Step 1: Remove all 'a's, Step 2: Remove all 'b's)
                return 2;
            }
            left++;
            right--;
        }
        
        // If the loop completes, the whole string is a palindrome
        return 1;
    }
};