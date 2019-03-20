#include <iostream>
#include <iterator>
#include <vector>
#include <map>
// #include <gmpxx.h>


using namespace std;

vector<  long long int > win(vector<  long long int > balls, map<vector<  long long int >, vector<  long long int >> &memo);

vector<  long long int > win(vector<  long long int > balls, map<vector<  long long int >, vector<  long long int >> &memo)
{

    // cout << "inside balls" << endl;
    vector<  long long int > tup1 = vector<  long long int >{0, 0};
    vector<  long long int > tup2 = vector<  long long int >{0, 0};

    if (memo.find(balls) == memo.end())
    {
        // cout << "calculating" << endl;
        // cout << balls.at(0) << "," << balls.at(1) << endl;
        // key nahi hai bhaiya
        if (balls[0] == 0)
        {
            if (balls[1] % 2 == 0)
            {
                memo.insert({balls, vector<  long long int >{1, 0}});
                return vector<  long long int >{1, 0};
            }
            else
            {
                memo.insert({balls, vector<  long long int >{0, 1}});
                return vector<  long long int >{0, 1};
            }
        }
        else if (balls[1] == 0)
        {
            memo.insert({balls, vector<  long long int >{1, 0}});
            return vector<  long long int >{1, 0};
        }
        else
        {
            tup1 = win(vector<  long long int >{balls[0] - 1, balls[1]}, memo);
            tup2 = win(vector<  long long int >{balls[0], balls[1] - 1}, memo);
            // cout << "balls " << balls[0]-1<< ", " << balls[1] << endl;
            // cout << tup1[0] << ", " << tup1[1] << endl;
            // cout << "balls " << balls[0]<< ", " << balls[1]-1 << endl ;
            // cout << tup2[0] << ", " << tup2[1] << endl;
            memo.insert({balls, vector<  long long int >{tup1[0] + tup2[0], tup1[1] + tup2[1]}});
            return memo[balls];
        }
    }
    else
    {
        // cout << "found key" << endl;
        // cout << balls.at(0) << "," << balls.at(1) << endl;
        return memo[balls];
    }
}

int main()
{
    map<vector<  long long int >, vector<  long long int >> memo;

    memo.insert({vector<  long long int >{0, 0}, vector<  long long int >{1, 0}});
    memo.insert({vector<  long long int >{0, 1}, vector<  long long int >{1, 0}});
    memo.insert({vector<  long long int >{1, 0}, vector<  long long int >{1, 0}});
    memo.insert({vector<  long long int >{1, 1}, vector<  long long int >{1, 1}});
    memo.insert({vector<  long long int >{2, 0}, vector<  long long int >{1, 0}});

    int n_times, red_balls, green_balls;
    cin >> n_times;

    for (int i=0;i<=n_times;i++){
        cin >> red_balls >> green_balls;
        vector<  long long int > result = vector<  long long int >{0, 0};
        result = win(vector<  long long int >{red_balls, green_balls}, memo);
        double s_wins_probab = double(result.at(0))/double(result.at(0) + result.at(1));
        cout << s_wins_probab << endl;
    }

    // vector<  long long int > result = vector<  long long int >{0, 0};
    // cout << "Starting" << endl;
    // result = win(vector<  long long int >{10, 10}, memo);
    // cout << "print something" << endl;
    // cout << "this is it bhai " << result.at(0) << ", " << result.at(1) << endl;
    // cout << result.at(0) / (result.at(0) + result.at(1));
}
