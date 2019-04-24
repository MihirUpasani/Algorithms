# Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.

# Input:
# The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N(the size of array). The second line of each test case contains array elements.

# Output:
# For each test case print the required answer in new line.

# Constraints:
# 1 ≤ T ≤ 100
# 1 ≤ N ≤ 106
# 1 ≤ Ai ≤ 106

# Example:
# Input:
# 2
# 7
# 1 101 2 3 100 4 5
# 4
# 10 5 4 3

# Output:
# 106
# 10

def maxxsum(array):

    max_sum = array[0]
    curr_array = [array[0]]
    for items in array[1:]:
        # for curr_array in _arrays:
            while (curr_array and curr_array[-1] > items):
                curr_array.pop()
            curr_array.append(items)
            max_sum = max(max_sum, sum(curr_array))
            print(curr_array, max_sum)

    return max_sum

def maxxsum_v2(array):
    _arrays = [[array[0]]]

    for elements in array[1:]:
        for _element in _arrays:
            if _element[-1] < elements:
                _arrays.append(_element + [elements])
            else:
                pass
            _arrays.append([elements])
    print(len(_arrays))
    return max([sum(x) for x in _arrays])

def maxxdp(array):

    memo = array.copy()

    for index in range(len(array)):
        for x in range(0, index):
            print("x : {}".format(x))
            print("index : {}".format(index))
            print("memo[x] : {}, array[index] : {}".format(memo[x], array[index]))
            print("Memo entire")
            print(memo)
            if array[index] > array[x] and memo[index] < memo[x] + array[index]:
                # if array[index] greater than array[x] and memorized[index] is less than sum of memorized[x] and array[index]
                print("before")
                print("memo[index] : {}".format(memo[index]))
                memo[index] = memo[x] + array[index]
                print("after")
                print("memo[index] : {}".format(memo[index]))
                print("\n\n")
                # memorized[index] = memorized[x] + array[index]
            else:
                print("no good\n\n")
    return(max(memo))

def thinkbro(array):
    # This works but its just too slow
    _arrays = [[array[0]]]

    for item in array[1:]:
        for stuff in _arrays:
            if item > stuff[-1]:
                stuff.append(item)
            elif item < stuff[-1]:
                new_stuff = list(stuff)
                while(new_stuff and new_stuff[-1] > item):
                    new_stuff.pop()
                new_stuff.append(item)
                _arrays.append(new_stuff)

    return max([sum(x) for x in _arrays])
    
if __name__ == "__main__":
    # print(maxxsum([9, 8, 10, 4, 3]))
    # print(maxxdp([9, 8, 10, 4, 3]))
    maxxdp([1, 7, 4, 3, 100])
    great = [int(x) for x in "468 335 501 170 725 479 359 963 465 706 146 282 828 962 492 996 943 828 437 392 605 903 154 293 383 422 717 719 896 448 727 772 539 870 913 668 300 36 895 704 812 323".split()]
    # maxxdp(great)
    # print(maxxsum_v2(great))
    # print(maxxsum_v2([1, 101, 2, 3, 100, 4, 5]))
    # print(thinkbro([1, 101, 2, 3, 100, 4, 5]))    
    # print(maxxsum([100, 2, 10, 3, 101, 4, 5]))
    # maxxdp([100, 2, 10, 3, 101, 4, 5])
    # print(maxxdp([9, 8, 10, 4, 3]))