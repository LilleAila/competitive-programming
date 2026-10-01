n = input()
m = input()

lg_m = len(m) - 1
lg_n = len(n) - 1

if lg_n > lg_m:
    a = n[:-lg_m]
    b = n[-lg_m:].rstrip("0")

    if len(b) > 0:
        print(f"{a}.{b}")
    else:
        print(a)
else:
    d = lg_m - lg_n
    leading = "".join(["0"] * (d - 1))
    print(f"0.{leading}{n}")
