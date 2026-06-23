class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // STEP 1: Sort the array. The two-pointer technique relies
        // entirely on the elements being in ascending order.
        sort(nums.begin(), nums.end());

        // Initialize 'closest' with the sum of the first three elements.
        int closest = nums[0] + nums[1] + nums[2];
        int n = nums.size();

        // STEP 2: Iterate through the array, fixing one element at a time.
        // We stop at n - 2 because we need at least 3 elements for a triplet.
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            // STEP 3: Use two pointers to find the closest pair for the fixed
            // nums[i]
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];

                // If we find an exact match to the target, return immediately.
                if (currentSum == target) {
                    return currentSum;
                }

                // If the current sum is closer to the target than our
                // previously recorded 'closest' sum, update it.
                if (abs(currentSum - target) < abs(closest - target)) {
                    closest = currentSum;
                }

                // STEP 4: Adjust pointers based on the sum comparison.
                // If the sum is less than the target, we need a larger sum ->
                // move left pointer right. If the sum is greater than the
                // target, we need a smaller sum -> move right pointer left.
                if (currentSum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        // Return the best triplet sum found
        return closest;
    }
};