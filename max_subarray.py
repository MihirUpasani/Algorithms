
# Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.

def max_subarray(array):
    # This is a dumb approach, dont even pursue it. n**2 time complexity
    base_list = array[:]

    max_ret = array[0]

    for number in range(len(array)):
        print("adding {}".format(array[number]))
        for x in range(number):
            print("adding to {}".format(base_list[x]))
            base_list[x] = base_list[x] + array[number]
        max_ret = max(max(base_list), max_ret)
        print("max ret is : {}".format(max_ret))
    return max_ret


def linear_max(array):
    max_sum = array[0]
    curr_sum = array[0]

    for number in array[1:]:
        curr_sum = max(curr_sum+number, number)
        if max_sum < curr_sum:
            max_sum = curr_sum
    return max_sum
    # run in 0.38 sec

if __name__ == "__main__":
    print(linear_max([-2, -3, 4, -1, -2, 1, 5, -3]))
    print(linear_max([1, 2, 3, -2, 5]))