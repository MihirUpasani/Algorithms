// fast exp
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

unsigned long int mfer(unsigned long int number, unsigned long int power, unsigned long int quotient);

unsigned long int mfer(unsigned long int number, unsigned long int power, unsigned long int quotient)
{
    cout << "Called" << endl;

    map<unsigned long int, unsigned long int> memo;
    memo.insert({1, number});
    unsigned long int start_with = 1;
    unsigned long int new_insert = 1;
    unsigned long int remainder = 1;
    int bin_rep[100], bin_len, i;

    cout << "Decalrations done" << endl;

    while (start_with <= power)
    {
        cout << "start_with : " << start_with << endl;
        new_insert = memo.at(start_with);
        new_insert = (new_insert * new_insert) % quotient;
        start_with = start_with * 2;
        // mfer, you forgot to insert
        memo.insert({start_with, new_insert});
    }

    cout << "MemTable calculated" << endl;

    bin_len, i = 0;
    while (power > 0)
    {
        bin_rep[i] = power % 2;
        power = power / 2;
        i++;
        bin_len++;
    }

    cout << "Power binary rep done" << endl;

    for (i = bin_len; i >= 0; i--)
    {
        if (bin_rep[i] == 1)
        {
            remainder = remainder * memo.at(pow(2, i));
        }
    }
    return (remainder % quotient);
}

int main()
{
    cout << mfer(24, 34, 215) << endl;
}
