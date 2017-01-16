def main():
    dict = {}
    str = raw_input("enter the string: ")
    for char in str:
        if char in dict:
            print False
            return False
        dict[char] = 1
    print True
    return True
if __name__ == "__main__":
    main()
