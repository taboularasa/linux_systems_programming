#include <stdio.h>
#define BSIZE 16384

void main()
{
    FILE *fin, *fout;
    char buf[BSIZE];
    int count;

    fin = fopen("data/foo", "r");
    fout = fopen("data/bar", "w");

    while ((count = fread(buf, 1, BSIZE, fin)) > 0) {
        fwrite(buf, 1, count, fout);
    }

    fclose(fin);
    fclose(fout);
}
