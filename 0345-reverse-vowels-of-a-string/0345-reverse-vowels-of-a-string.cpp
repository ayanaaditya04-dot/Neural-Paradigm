class Solution {
private:
    // Helper function to check if a character is a vowel
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // 1. Move the left pointer until it hits a vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            
            // 2. Move the right pointer until it hits a vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            
            // 3. Swap the two vowels
            swap(s[left], s[right]);
            
            // 4. Move both pointers inward to continue scanning
            left++;
            right--;
        }
        
        return s;
    }
};