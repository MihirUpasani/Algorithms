#include <iostream>
#include <cmath>
using namespace std;
int maxsum_dp(int arrayptr[], int array_length);

int maxsum_dp(int arrayptr[], int array_length)
{
    // declare array
    int memo [array_length];
    int mem_ [array_length];
    for(int i = 0; i < array_length; i++)
        {
            memo[i] = arrayptr[i];
            mem_[i] = 1;
        }

    for(int i = 0; i < array_length; i++)
        for(int j = 0; j < i; j++)
        {
            if(arrayptr[i] > arrayptr[j] and memo[i] < memo[j] + arrayptr[i])
            {
                memo[i] = memo[j] + arrayptr[i];
                mem_[i] += 1;
            }
        }
    int supermax = 0;
    for(int i = 0; i <array_length; i++)
        supermax = max(memo[i], supermax);
    for(int i = 0; i < array_length; i++)
        cout << mem_[i] << endl;
    return supermax;
}

int main()
{
    int ref_array [8] = {1, 4, 2, 3, 6, 9, 10, 8};
    cout << maxsum_dp(ref_array, 8) << endl;
    // maxsum_dp({1, 7, 4, 3, 100}, 5);
    return 0;
}
