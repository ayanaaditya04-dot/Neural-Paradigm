class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();

        // Quadruplet is impossible with less than 4 elements
        if (n < 4)
            return res;

        // STEP 1: Sort the array to utilize the two-pointer technique
        sort(nums.begin(), nums.end());

        // STEP 2: First fixed element pointer (i)
        for (int i = 0; i < n - 3; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // STEP 3: Second fixed element pointer (j)
            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicates for the second element
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int left = j + 1;
                int right = n - 1;

                // STEP 4: Two-pointer framework for the remaining two elements
                while (left < right) {
                    // Casting the first element to long long prevents integer
                    // overflow during addition
                    long long sum =
                        (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        // Push the actual quadruplet elements, not their sum
                        res.push_back(
                            {nums[i], nums[j], nums[left], nums[right]});

                        // Move pointers past the current valid combination
                        left++;
                        right--;

                        // Skip duplicate values to avoid duplicate quadruplets
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;

                    } else if (sum < target) {
                        left++; // Sum is too small, move left pointer rightward
                    } else {
                        right--; // Sum is too big, move right pointer leftward
                    }
                }
            }
        }

        return res;
    }
};