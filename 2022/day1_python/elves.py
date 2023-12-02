f = open("data.txt", "r")
# string = f.read()
maximum = 0
x = 0
list = [0, 0, 0]
for line in f:
    if line == "\n":
        list.append(x)
        if x > maximum:
            maximum = x
        x = 0
    else:
        x += int(line.strip())

max1 = list.pop(list.index(max(list)))
max2 = list.pop(list.index(max(list)))
max3 = list.pop(list.index(max(list)))

print(max1, max2, max3)

