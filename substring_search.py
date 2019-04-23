# Given two strings S and T, find count of distinct occurrences of T in S as a sub-sequence. Your task is to complete the function subsequenceCount which takes two strings as argument S and T and returns the count of the sub-sequences.

# Input:
# The first line of input contains an integer t denoting the no of test cases . Then t test cases follow. The first line of each test case contains 2 strings S and T.

# Output:
# For each test case in a new line print the count of distinct occurrences of T in S as a sub-sequence.

# Constraints:
# 1<=t<=100
# 1<=length of (S,T)<=100

# Example(To be used only for expected output):
# Input
# 2
# banana ban
# geeksforgeeks ge

# Output
# 3
# 6


def searcher(search, sequence):

    count = 0
    index = 0
    print('Search is {}'.format(search))
    print('Sequence is {}'.format(sequence))

    if len(search) == 1:
        print('Search is now one')
        for letter in sequence:
            if search[0] == letter:
                count += 1
        return count

    search_sequence = sequence

    while index < len(search_sequence):
        while(search_sequence[index] != search[0]):
            print(search_sequence[index])
            index += 1

        # now I'm at a place where sequence and search begin with the same letter
        # now what do?
        new_sequence = sequence[index+1:]
        new_search = search[1:]

        # search with these two now
        count += searcher(new_search, new_sequence)
        search_sequence = sequence[1:]

    return count


def search_dyn(search_string, sequence_string):

    refrence_matrix = [[0]*len(sequence_string) for x in range(len(search_string))]

    sparse_tuples = []

    for column_index in range(len(search_string)):
        for row_index in range(len(sequence_string)):
            if search_string[column_index] == sequence_string[row_index]:
                sparse_tuples.append((column_index, row_index))
                # refrence_matrix[column_index][row_index] = 1

    print(sparse_tuples)

    # current_elem = 0
    # found = False
    # for tuples in sparse_tuples:
    # for rows in range(len(search_string)):
    #     if sum(refrence_matrix[rows]) == 0:
    #         return 0
    #     else:
    #         for cols in range(len(sequence_string)):
    #             if refrence_matrix[rows][cols]:
    #                 found = True
    #                 break
    #     if found:
    #         break



    paths = 0
    # if 0 not in sparse_tuples[0]:
    #     return 0
    # for tuples in sparse_tuples:
    #     if len(search_string) - 1 not in tuples:
    #         for sec_tuple in sparse_tuples[sparse_tuples.index(tuples):]:
    #             if tuples[0] + 1 in sec_tuple and sec_tuple[1] > tuples[1]:
    #                 if sec_tuple[0] == (len(search_string) - 1):
    #                     print(tuples, sec_tuple)
    #                     paths += 1
    #             else:
    #                 pass
    #                 print("Dunno if a path exists")
    #                 print(tuples, sec_tuple)

    potential_paths = []
    for tuples in sparse_tuples:
        if tuples[0] == 0:
            potential_paths.append([tuples])
        else:
            for stuff in potential_paths:
                if stuff[-1][0] < tuples[0] and stuff[-1][1] < tuples[1]:
                    # print(stuff[-1], tuples)
                    potential_paths.append(stuff + [tuples])

    for stuff in potential_paths:
        if len(stuff) == len(search_string):
            # print(stuff)
            paths += 1

    return paths

if __name__ == "__main__":
    # print(search_dyn('ban', 'banana'))
    # print(search_dyn('ge', 'geeksforgeeks'))
    print(search_dyn('yeet', 'kanyeetmyftfordts'))
    print(search_dyn('teet', 'kanyeetmyfeetfordeets'))