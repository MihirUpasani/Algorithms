// https://leetcode.com/problems/missing-number/submissions/879185456/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int targetSum = (nums.size()+1) * nums.size() / 2;

        for(int i=0; i<nums.size(); i++){
            targetSum -= nums[i];
        }

        return targetSum;
    }
};