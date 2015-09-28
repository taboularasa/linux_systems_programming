with open('data/foo', 'rb') as fin:
    with open('data/bar', 'wb') as fout:
        fout.write(fin.read())
