#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int dist(char stuff[], string maal, int stuff_len, int maal_len)
{
    int stuff_index = 0;
    int memo [stuff_len+1][maal_len+1];
    cout << stuff_len << " " << maal_len << endl;


    for(int stuff_index=0; stuff_index <= stuff_len; stuff_index++)
    {
        for(int maal_index=0; maal_index <= maal_len; maal_index++)
        {
            // cout << "For memo[" << stuff_index << "][" << maal_index << "]" << endl;
            if (stuff_index == 0 || maal_index == 0)
                memo[stuff_index][maal_index] = max(stuff_index, maal_index);
            else
            {
                if (stuff[stuff_index-1] == maal[maal_index-1])
                {
                    // edit distance doesn't change
                    memo[stuff_index][maal_index] = memo[stuff_index-1][maal_index-1];
                }
                else
                {
                    memo[stuff_index][maal_index] = 1 + min(min(memo[stuff_index-1][maal_index], memo[stuff_index-1][maal_index-1]), memo[stuff_index][maal_index-1]);
                }
            }
        }
    }
    char out = 'x';
    for(int stuff_index=0; stuff_index <= stuff_len; stuff_index++)
    {
        for(int maal_index=0; maal_index <= maal_len; maal_index++)
        {
            if (maal_index == 0 && stuff_index==0)
                out = '#';
            else if (maal_index == 0)
                out = stuff[stuff_index-1];
            else if (stuff_index == 0)
                out = maal[maal_index-1];
            else
                out = char(memo[stuff_index][maal_index]);
            if (int(out) > 30)
                cout << out << " ";
            else
                cout << int(out) << " ";
        }
        cout << endl;
    }
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
        string maal;
        char stuff[stuff_len];
        cin >> stuff;
        cin >> maal;
        cout << dist(stuff, maal, stuff_len, maal_len) << endl;
	}


	return 0;

}