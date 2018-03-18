import cs50

def main():
    while(True):
        print("How much change is owed?")
        t = cs50.get_float()
        if(t > 0.009):
            break
    c = round(t * 100)
    q = 0
    while(c >= 25):
        c = c - 25
        q += 1
    d = 0
    while(c < 25 and c > 9):
        c = c - 10
        d += 1
    n = 0
    while(c < 10 and c > 4):
        c = c - 5
        n += 1
    p = 0
    while(c < 5 and c > 0):
        c = c - 1
        p += 1
    count = (q + d + n + p)
    print(count)
if __name__ == "__main__":
    main()
