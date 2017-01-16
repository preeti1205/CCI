def compressor(input):
    length = len(input)
    counter = 0
    result = ""
    for i in range(length):
        counter += 1
        if  (i + 1 == length) or ( input[i] != input[i + 1] ):
            result += input[i] + str(counter)
            counter = 0

    if (len(result) >= length):
        return input

    return result

if __name__ == '__main__':
    assert compressor("hello") == "hello"
    assert compressor("aaaa") == "a4"
    assert compressor("a") == "a"
    print "Done"
