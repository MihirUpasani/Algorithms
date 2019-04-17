# Given a number n, we can divide it in only three parts n/2, n/3 and n/4 (we will consider only integer part). The task is to find the maximum sum we can make by dividing number in three parts recursively and summing up them together.
# Note: Sometimes, the maximum sum can be obtained by not dividing n.

# Input:
# The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. The first line of each test case contains the integer n.

# Output:
# For each testcase, in a new line, print the maximum sum possible.

# Constraints:
# 1<= T <=100
# 1<= n <=105

# Example:
# Input:
# 2
# 12 
# 24

# Output:
# 13 
# 27

memo = {}

def maxsum(number):
    
    global memo

    if number <= 11:
        return number

    try:
        return memo[number]
    except:
        memo[number] = max(number, maxsum(number//2) + maxsum(number//3) + maxsum(number//4))
    
    return memo[number]

if __name__ == "__main__":
    print(maxsum(24))