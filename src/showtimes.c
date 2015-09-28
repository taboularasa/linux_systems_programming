#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

void main()
{
    struct stat sb;

    stat("/home/vagrant/data/foo", &sb);

    printf("last accessed %s", ctime(&sb.st_atime));
    printf("last modified %s", ctime(&sb.st_mtime));
    printf("last change   %s", ctime(&sb.st_ctime));

    exit(0);
}
