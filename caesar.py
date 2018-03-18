import cs50
import sys

def main():
    k = int(sys.argv[1])
    print("Message to be encoded: ", end="")
    p = cs50.get_string()
    print("Encoded message: ", end="")
    for i in p:
        if(i.isalpha()):
            if(i.isupper()):
                alpha = ord(i) - 65
                c = (alpha + k) % 26
                print(chr(c + 65), end="")
            elif(i.islower()):
                beta = ord(i) - 97
                d = (beta + k) % 26
                print(chr(d + 97), end="")
        else:
            print(i, end="")
    print(" ")
if __name__ == "__main__":
    main()
