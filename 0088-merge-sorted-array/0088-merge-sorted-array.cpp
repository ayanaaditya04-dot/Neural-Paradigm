class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left = m - 1;       // Tracks valid elements in nums1 (moving right-to-left)
        int right = n - 1;      // Tracks elements in nums2 (moving right-to-left)
        int write = m + n - 1;  // Positional writer at the absolute back of nums1
        
        // Walk backwards as long as both arrays have elements left to compare
        while (left >= 0 && right >= 0) {
            if (nums1[left] > nums2[right]) {
                nums1[write] = nums1[left];
                left--; // Move left pointer backward
            } else {
                nums1[write] = nums2[right];
                right--; // Move right pointer backward
            }
            write--; // Move the write slot backward
        }
        
        // Cleanup: If nums2 (right) still has elements left, copy them over.
        // If nums1 (left) has elements left, they are already in the correct spot!
        while (right >= 0) {
            nums1[write] = nums2[right];
            right--;
            write--;
        }
    }
};