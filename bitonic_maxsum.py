def sum_ret(numbers):
    inc, dec = (False, False)
    prev = numbers[0]
    max_sum = numbers[0]
    curr_sum = numbers[0]
    for number in numbers[1:]:
        curr = number
        print("\nprev:{}, curr:{}".format(prev, curr))
        if prev < curr:
            # increasing seq
            # 2 poss : 1. keeps increasing 2. might decrease
            if dec:
                # print("resetting")
                curr_sum = curr + prev
                inc, dec = (False, False)
            else:
                # print("increasing subseq")
                if not inc:
                    inc = True
                curr_sum += curr
        elif prev > curr:
            # decreasing seq
            # 2 poss: 1. keeps decreasing 2. might increase
            # print("decreasing subseq")
            if not dec:
                dec = True
            curr_sum += curr
        else:
            curr_sum = curr
            inc, dec = (False, False)
        max_sum = max(curr_sum, max_sum)
        prev = curr
    return max_sum

if __name__ == "__main__":
    print(sum_ret([5,3,9,2,7,6,4]))
    print(sum_ret([5, 4, 3, 2, 1, 10, 6]))
    print(sum_ret([3,2,2,4]))
    print(sum_ret([617]))
    print(sum_ret([80, 60, 30, 40, 20, 10]))
    print(sum_ret([1, 15, 51, 45, 33, 100, 12, 18, 9]))
# run time : 0.22 sec