import hashlib
counter = 0;
string_counter = bytes(str(counter), 'ascii')
print(type(string_counter))
print(type(b"hello bytes"))
print(type(b"hello bytes"))
while(True):
    m = hashlib.md5()
    m.update(b"bgvyzdsv")
    m.update(bytes(str(counter), 'ascii'))
    x = int(m.hexdigest(), 16)
    print(m.hexdigest())
    print(hex(x))
    x = x & (0xffffff << 26*4)
    if x == 0:
        print(counter)
        break
    counter += 1


    

