class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1;
        int right = -2; // Initialized so that if already sorted, (right - left + 1) = 0

        int max_val = nums[0];
        int min_val = nums[n - 1];

        // Single loop to scan from both ends
        for (int i = 0; i < n; i++) {
            // 1. Scan from Left to Right to find 'right' boundary
            if (nums[i] < max_val) {
                right = i; // 'i' is out of order because it's smaller than the
                           // max seen so far
            } else {
                max_val = nums[i];
            }

            // 2. Scan from Right to Left to find 'left' boundary
            int j = n - 1 - i;
            if (nums[j] > min_val) {
                left = j; // 'j' is out of order because it's larger than the
                          // min seen so far
            } else {
                min_val = nums[j];
            }
        }

        return right - left + 1;
    }
};