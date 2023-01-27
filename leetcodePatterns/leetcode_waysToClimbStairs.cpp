// https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {

        if(n < 3){
            return n;
        }

        vector<int> memTable(n+1);

        memTable[0] = 0;
        memTable[1] = 1;
        memTable[2] = 2;

        for (int i=3; i<n+1; i++){
            memTable[i] = memTable[i-1] + memTable[i-2];
        }

        return memTable[n];
    }
};