from __future__ import division
import sys
import time


sys.setrecursionlimit(20000)
result_storing = {'(0, 0)': [1, 0], '(0, 1)': [1, 0], '(1, 0)': [
    1, 0], '(1, 1)': [1, 1], '(2, 0)': [1, 0]}


def foo(balls):
    global result_storing    # print('balls : {}'.format(str(balls)))
    if str(balls) in result_storing.keys():
        return result_storing[str(balls)]
    if balls[0] == 0:
        # print('No red balls')
        if balls[1] % 2 == 0:
            result_storing[str(balls)] = 1.0
            return 1.0
        else:
            result_storing[str(balls)] = 0.0
            return 0.0
    elif balls[1] == 0:
        # print('No green balls')
        result_storing[str(balls)] = 1.0
        return 1.0
    else:
        # calc += 1
        # print('trying to find : {}'.format(balls))
        # tuple1 = foo((balls[0] - 1, balls[1]))
        # tuple2 = foo((balls[0], balls[1] - 1))
        # result_storing[str(balls)] = (
        #     tuple1[0] + tuple2[0], tuple1[1] + tuple2[1])
        # return result_storing[str(balls)]
        res = float(balls[0])/float(sum(balls)) + float(balls[1])/float(sum(balls))*float(balls[1]-1)/float(sum(balls)-1)*foo((balls[0], balls[1]-2))
        result_storing[str(balls)] = res
        return res

res = foo((345, 56))
print(res)
# print('%.6f' % (float(res[0])/float(sum(res))))
# 11306330530781662592, 13619554349494431424
# for _ in range(int(input())):
#     ins = tuple([int(x) for x in input().split()])
#     res = foo(ins)
#     print('%.6f'%(float(res[0])/float(sum(res))))
