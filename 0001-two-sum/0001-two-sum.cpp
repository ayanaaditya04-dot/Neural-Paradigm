class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Input ->  unsorted array - Two pointer (sorting )changes the index possition;
        // Hash map is the most optimal solution
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            // look in hashmap does any pair of complement exist?
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i; // store the value of current "i"
        }

        return {}; // No solution found
    }
};


Time Complexity: O(n) — You only traverse the array exactly once, and hash map lookups take O(1) on average.
Space Complexity: O(n) — In the worst-case scenario (e.g., the matching pair is at the very end), you store n−1 elements in the map.
