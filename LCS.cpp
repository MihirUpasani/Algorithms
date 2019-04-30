#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int LCS(char stuff[], string maal, int stuff_len, int maal_len)
{
    int stuff_index = 0;
    int memo [stuff_len+1][maal_len+1];
    cout << stuff_len << " " << maal_len << endl;

    cout << stuff[0] << endl;

    for(int stuff_index=0; stuff_index <= stuff_len; stuff_index++)
    {
        for(int maal_index=0; maal_index <= maal_len; maal_index++)
        {
            if (stuff_index == 0 || maal_index == 0)
                memo[stuff_index][maal_index] = 0;
            else
            {
                if (stuff[stuff_index-1] == maal[maal_index-1])
                {
                    memo[stuff_index][maal_index] = memo[stuff_index-1][maal_index-1] + 1;
                }
                else
                {
                    memo[stuff_index][maal_index] = max(memo[stuff_index-1][maal_index], memo[stuff_index][maal_index-1]);
                }
            }
        }
    }
    // for(int stuff_index=0; stuff_index <= stuff_len; stuff_index++)
    // {
    //     for(int maal_index=0; maal_index <= maal_len; maal_index++)
    //         cout << memo[stuff_index][maal_index] << " ";
    //     cout << endl;
    // }
    return memo[stuff_len][maal_len];
}

int main()
{
    // char stuff[6] = {'a', 'b', 'c', 'd', 'g', 'h'};
    // char maal[6] = {'a', 'e', 'd', 'f', 'h','r'};
    // cout << LCS(maal, stuff, 6, 6) << endl;
	int n_times;
	cin >> n_times;
	for (int times=0;times<n_times;times++)
	{
        int stuff_len; cin >> stuff_len;
        int maal_len; cin >> maal_len;
        cout << stuff_len << ' ' << maal_len << endl;
        string maal;
        char stuff[stuff_len];
        cin >> stuff;
        cin >> maal;
        cout << LCS(stuff, maal, stuff_len, maal_len) << endl;
	}


	return 0;

}