class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Reverse the entire string
        reverse(s.begin(), s.end());
        
        int n = s.length();
        int writeIdx = 0; // Tracks where we are writing clean words
        
        // Step 2: Fix spaces and reverse individual words
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') { // Found the start of a word!
                
                // If this isn't the first word we are writing, append a single space spacer
                if (writeIdx != 0) {
                    s[writeIdx] = ' ';
                    writeIdx++;
                }
                
                // Find the end of the current word
                int start = writeIdx;
                while (i < n && s[i] != ' ') {
                    s[writeIdx] = s[i];
                    writeIdx++;
                    i++;
                }
                
                // Reverse the individual word back to its correct reading order
                int left = start;
                int right = writeIdx - 1;
                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
            }
        }
        
        // Resize the string to chop off any trailing leftover junk space
        s.resize(writeIdx);
        return s;
    }
};