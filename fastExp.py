# fast exp
import time

def mfer(number, power, quotient):
    remainder = 1
    power_dict = {1: number%quotient}
    start_with = 1

    while start_with <= power:
        # print(power_dict[sorted(list(power_dict.keys()))[-1]])
        new_insert = (power_dict[sorted(list(power_dict.keys()))[-1]] ** 2) % quotient
        start_with *= 2
        print(start_with, new_insert)
        power_dict[start_with] = new_insert

    bin_rep = bin(power)[2:][::-1]
    for x in range(len(bin_rep)):
        if bin_rep[x] == '1':
            print(2**x)
            remainder *= power_dict[2**x]

    return remainder % quotient

if __name__ == "__main__":
    x0 = time.time()
    print(mfer(24, 34, 215))
    print(time.time() - x0)