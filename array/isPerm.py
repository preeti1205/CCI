def isPerm(input1, input2):
    if input1 == input2:
        return True
    len1 = len(input1)
    len2 = len(input2)
    if len1 != len2:
        return False
    tally = [0]*128         #################
    for i in range(len1):
        tally[ord(input1[i])] += 1   ##########
        tally[ord(input2[i])] -= 1

    for i in range(128):
        if tally[i] != 0:
            return False

    return True;

if __name__ == "__main__":
    assert isPerm("lene", "eeln") == True
    assert isPerm("", "") == True
    assert isPerm("lene", "eebc") == False

    print("Done")
