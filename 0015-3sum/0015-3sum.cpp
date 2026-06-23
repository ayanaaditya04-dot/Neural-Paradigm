class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Given -> Array
        // return -> return all the triplets [nums[i], nums[j], nums[k]] such
        // that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0
        // No Duplicates required
        // STEP 1 -> RESULT ARRAY & SORT THE GIVEN ARRAY
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            // check for duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            // place the two pointer to traverse the array
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    // if sum == 0 -> res.push back index
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;

                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return res;
    }
};