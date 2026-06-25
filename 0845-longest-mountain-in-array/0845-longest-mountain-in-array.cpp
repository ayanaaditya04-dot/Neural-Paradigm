class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxLength = 0;
        
        // A peak cannot be at the first (0) or last (n-1) index
        for (int i = 1; i < n - 1; i++) {
            
            // Check if arr[i] is a valid peak
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                
                int left = i;
                int right = i;
                
                // Expand left (climb down the left side)
                while (left > 0 && arr[left] > arr[left - 1]) {
                    left--;
                }
                
                // Expand right (climb down the right side)
                while (right < n - 1 && arr[right] > arr[right + 1]) {
                    right++;
                }
                
                // Calculate the current mountain length
                int currentLength = right - left + 1;
                maxLength = max(maxLength, currentLength);
                
                // Optimize: Move 'i' to the end of this mountain decline
                i = right;
            }
        }
        
        return maxLength;
    }
};