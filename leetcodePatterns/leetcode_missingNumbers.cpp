// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/

#include <iostream>
#include <vector>
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> missingNumbers(nums.size()+1);
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++){
            missingNumbers[nums[i]]++;
        }

        for(int i=1; i<missingNumbers.size(); i++){
            if(missingNumbers[i] == 0){
                result.push_back(i);
            }
        }

        return result;
    }
};