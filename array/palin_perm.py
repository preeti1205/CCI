def palind_perm(input):
    tally = [0]*128
    length = len(input)
    odd_counter = 0

    for char in input:
        tally[ord(char)] += 1

    for i in range(128):
        if tally[i] % 2 != 0 odd_counter += 1
        if odd_counter > 1 return False

    return  True

if __name__ == '__main__':
    assert palind_perm("taco_cat") == True
