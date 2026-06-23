class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Two pointer Teachnique 
        //why? Array -> Sorted -> Find sum -> target;
        int n = numbers.size();
        int left = 0, right = n-1;
        while(left<right){
            int sum = numbers[left] + numbers[right];// Track the sum
            if(sum == target){
                return {left+1 ,right +1};
            }else if(sum < target){
                left++;
            }else {
                right--;
            }
        }
        return{};
    }
};