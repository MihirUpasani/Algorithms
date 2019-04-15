# Given a M X N matrix with your initial position at top-left cell, find the number of possible unique paths to reach the bottom right cell of the matrix from the initial position.

# Note: Possible moves can be either down or right at any point in time, i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

# Input:
# The first line contains an integer T, depicting total number of test cases.
# Then following T lines contains an two integers A and B depicting the size of the grid.

# Output:
# Print the number of unique paths to reach bottom-right cell from the top-left cell.

# Constraints:
# 1 ≤ T ≤ 30
# 1 ≤ M ≤ 15
# 1 ≤ N ≤ 15

# Example:
# Input
# 2
# 2 2
# 3 4
# Output
# 2
# 10

num_paths = {(1, 1): 0, (1, 2): 0, (2, 2): 2, (2, 3): 3}


def path_gen(rows, columns):
    global num_paths
    print(rows, columns)
    sad_tup = tuple(sorted([rows, columns]))
    try:
        print("trying to return from dictionary")
        return num_paths[sad_tup]
    except KeyError:
        print("need to calculate")
        # calculate number of paths
        if rows < 2 or columns < 2:
            return 1
        else:
            num_paths[sad_tup] = path_gen(rows -
                                          1, columns) + path_gen(rows, columns-1)
            return num_paths[sad_tup]


def runner():
    n_times = int(input())
    for _ in range(n_times):
        my_list = [int(x) for x in input().split()]
        print(path_gen(my_list[0], my_list[1]))


if __name__ == "__main__":
    print(path_gen(3, 4))
# runtime : 0.03 sec