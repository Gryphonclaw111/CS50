import cs50
def main():
    while(True):
        print("How many stories tall do you want your pyramid to be?")
        height = cs50.get_int()
        if(height > 0 and height < 24):
            break
    h = 0
    for i in range(height):
        print(" " * (height - h), end="")
        print("#", end ="")
        print("#" * h, end ="   ")
        print("#", end = "")
        print("#" * h)
        h += 1
if __name__ == "__main__":
    main()
