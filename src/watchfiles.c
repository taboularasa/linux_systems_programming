#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <limits.h>

#define BUFSIZE (100 * (sizeof(struct inotify_event) + NAME_MAX + 1))

void main()
{
    FILE *fconfig;
    FILE *fout;
    char watchname[PATH_MAX];
    struct stat sb;
    int notifyfd, watchfd;
    char eventbuf[BUFSIZE];
    int n;
    char *p;
    struct inotify_event *event;

    char watchednames[100][NAME_MAX + 1];

    notifyfd = inotify_init();

    if ((fconfig = fopen("monitor.conf", "r")) != NULL) {
        watchname[strlen(watchname) - 1] = '\0';

        if (stat(watchname, &sb) < 0) {
            printf("Cannot stat %s, ignored\n", watchname);
            continue;
        }

        if (S_ISREG(sb.st_mode)) {
            int added_watch =
            watchfd = inotify_add_watch(
                notifyfd,
                watchname,
                IN_MODIFY | IN_DELETE_SELF
            )
            if (watchfd < 0) {
                printf("error adding watch for %s\n", watchname);
            } else {
                printf(
                    "added %s to watchlist on descriptor %d\n",
                    watchname,
                    watchfd
                );
            }
        }
    }
}
