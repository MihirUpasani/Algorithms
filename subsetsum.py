# code
# code


def subset_sum(currentarray, findsum):
    # Covering corner cases
    if sum(currentarray) < findsum:
        return -1
    if findsum in currentarray:
        ind = currentarray.index(findsum) + 1
        return (ind, ind)

    # Now the realest nibba
    # Currsum needs to be updated when you break while
    # This shit is still slow as fuck nibba
    currsum, startwith = 0, 0
    endwith = 0
    for startwith in range(len(currentarray)):
        while(currsum < findsum):
            endwith += 1
            currsum = sum(currentarray[startwith:endwith])
            if endwith > len(currentarray):
                return -1
        if currsum == findsum:
            return(startwith+1, endwith)
        currsum -= currentarray[startwith]



# times = int(input())
# for x in range(times):
#     fdsum = int(input().split()[1])
#     curarr = [int(x) for x in input().split()]
#     ans = subset_sum(curarr, fdsum)
#     if type(ans) != int:
#         print(ans[0], ans[1])
#     else:
#         print(ans)

if __name__ == "__main__":
    print(subset_sum([21, 9, 4, 13, 1, 6], 36))
