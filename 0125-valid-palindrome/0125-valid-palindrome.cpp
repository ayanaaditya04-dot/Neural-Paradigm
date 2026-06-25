class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        // Master loop to scan the entire string
        while (left < right) {
            
            // 1. Skip 'kachra' from the left side
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // 2. Skip 'kachra' from the right side
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // 3. Compare the valid characters
            if (tolower(s[left]) != tolower(s[right])) {
                return false; // Mismatch found! It's not a palindrome.
            }
            
            // 4. Move pointers inward if they matched to check the next pair
            left++;
            right--;
        }
        
        // If the loop finished without returning false, it IS a palindrome!
        return true; 
    }
};