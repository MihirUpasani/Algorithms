

// Complete Solution:

//     After creating DP array, for an element arr[i],  iterate the original array for all arr[j], such that j<i.
//     if arr[j] is smaller than arr[i] and dp[i] is less than dp[j] + 1, then store dp[i] = dp[j] + 1
//     Print the max of dp[i].


#include <iostream>
#include <cmath>
using namespace std;
int maxsum_dp(int arrayptr[], int array_length);

int maxsum_dp(int arrayptr[], int array_length)
{
    // declare array
    int mem_ [array_length];
    for(int i = 0; i < array_length; i++)
        {
            mem_[i] = 1;
        }

    for(int outer_index = 0; outer_index < array_length; outer_index++)
        for(int inner_index = outer_index-1; inner_index >= 0; inner_index--)
        {
            if(arrayptr[outer_index] > arrayptr[inner_index])
            {
                mem_[outer_index] = max(mem_[outer_index], mem_[inner_index] + 1);
            }
        }
    int supermax = 0;
    for(int i = 0; i <array_length; i++)
        supermax = max(mem_[i], supermax);
    return supermax;
}

int main()
{
    int ref_array [8] = {1, 4, 2, 3, 6, 9, 10, 8};
    int arr[16] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int consider[7] = {1, 101, 2, 3, 100, 4, 5};
    cout << maxsum_dp(ref_array, 8) << endl;
    cout << maxsum_dp(arr, 16) << endl;
    cout << maxsum_dp(consider, 7) << endl;
    // maxsum_dp({1, 7, 4, 3, 100}, 5);
    return 0;
}
