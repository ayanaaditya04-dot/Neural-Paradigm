class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // If the array has 2 or fewer elements, it's already valid.
        if (nums.size() <= 2) return nums.size();
        
        int k = 2; // 'k' is our writer pointer. The first two elements are safely kept.
        
        // 'i' is our reader pointer, exploring the rest of the array.
        for (int i = 2; i < nums.size(); i++) {
            // Check if the current element matches the element 2 positions behind 'k'
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i]; // Write the valid element
                k++;               // Move the writer pointer forward
            }
        }
        
        return k; // 'k' represents the length of the modified array
    }
};