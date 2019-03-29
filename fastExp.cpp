// fast exp
#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

long int mfer(long int number, long int power, long int quotient);
int bin(long int power);

int bin(long int power)
{
    // array to store binary number
    int binaryNum[100];

    // counter for binary array
    int i = 0;
    while (power > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = power % 2;
        power = power / 2;
        i++;
    }
    return binaryNum;
}

long int mfer(long int number, long int power, long int quotient)
{
    map<long int, long int> memo;
    memo.insert({1, number});
    long int start_with = 1;
    long int new_insert = 1;
    while (start_with <= power)
    {
        new_insert = memo.at(start_with);
        new_insert = (new_insert * new_insert) % quotient;
        start_with = start_with * 2;
    }
    int bin_rep[100] = bin(power)
}