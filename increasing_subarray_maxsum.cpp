#include <iostream>
#include <cmath>
using namespace std;
int maxsum_dp(int arrayptr[], int array_length);

int maxsum_dp(int arrayptr[], int array_length)
{
    // declare array
    int memo [array_length];
    for(int i = 0; i < array_length; i++)
        memo[i] = arrayptr[i];

    for(int i = 0; i < array_length; i++)
        for(int j = 0; j < i; j++)
        {
            if(arrayptr[i] > arrayptr[j] and memo[i] < memo[j] + arrayptr[i])
            {
                memo[i] = memo[j] + arrayptr[i];
            }
        }
    int supermax = 0;
    for(int i = 0; i <array_length; i++)
        supermax = max(memo[i], supermax);
    for(int i = 0; i < array_length; i++)
        cout << memo[i] << endl;
    return supermax;
}

int main()
{
    int ref_array [7] = {1, 101, 2, 3, 100, 4, 5};
    cout << "Max is : " << maxsum_dp(ref_array, 7) << endl;
    // maxsum_dp({1, 7, 4, 3, 100}, 5);
    return 0;
}
