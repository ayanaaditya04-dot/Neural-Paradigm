class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n); // Create a result array of the same size
        
        int left = 0;
        int right = n - 1;
        
        // We will fill the result array from the back (largest to smallest)
        for (int i = n - 1; i >= 0; i--) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            // Compare which square is larger
            if (leftSquare > rightSquare) {
                res[i] = leftSquare;
                left++; // Move the left pointer inward
            } else {
                res[i] = rightSquare;
                right--; // Move the right pointer inward
            }
        }
        
        return res;
    }
};