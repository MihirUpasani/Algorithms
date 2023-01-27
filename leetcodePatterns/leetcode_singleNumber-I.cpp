// https://leetcode.com/problems/single-number/description/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> hashTable;

        for (int i =0; i<nums.size(); i++){
            hashTable[nums[i]]++;
        }

        for ( const auto &myPair : hashTable ){
            if(myPair.second == 1){
                return myPair.first;
            }
        }
        return -1;
    }
};