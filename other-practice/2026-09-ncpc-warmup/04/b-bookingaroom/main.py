r, n = map(int, input().split())

rooms = set(range(1, r+1))
for i in range(n):
    room = int(input())
    rooms.remove(room)

if len(rooms) == 0:
    print("too late")
else:
    print(next(iter(rooms)))
