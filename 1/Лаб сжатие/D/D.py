fin = open('lzw.in', 'r')
fout = open('lzw.out', 'w')

def compress(uncompressed):

    dict_size = 256
    dictionary = {chr(i): i for i in range(dict_size)}

    w = ""
    result = []
    for c in uncompressed:
        wc = w + c
        if wc in dictionary:
            w = wc
        else:
            if dictionary[w] == 256 :
                result.append(26)
            else :
                result.append(dictionary[w]-97)
            dictionary[wc] = dict_size
            dict_size += 1
            w = c

    if w:
        if dictionary[w] == 256 :
            result.append(26)
        else :
            result.append(dictionary[w]-97)
    return result

s = fin.readline()
compressed = compress(s)
for i in compressed :
    print(i, end=" ", file=fout)
fout.close()
