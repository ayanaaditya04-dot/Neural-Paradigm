class Solution {
private:
    // Helper function to check if a specific substring is a pure palindrome
    bool isPalindromeRange(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            if (s[left] != s[right]) {
                // Mismatch found! We try both deletion options:
                // Option 1: Skip s[left] -> check range (left + 1 to right)
                // Option 2: Skip s[right] -> check range (left to right - 1)
                return isPalindromeRange(s, left + 1, right) || 
                       isPalindromeRange(s, left, right - 1);
            }
            left++;
            right--;
        }
        
        // If no mismatch was found at all, it's already a perfect palindrome
        return true;
    }
};