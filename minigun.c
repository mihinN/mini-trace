#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>

int do_child(int argc, char** argv);
int do_trace(pid_t child);

int main(int argc , char** argv) {

        if (argc < 2) {
                fprintf(stderr, "use %s arguments \n", argv[0]);
                exit(1);
        }

        pid_t child = fork();
                if (child == 0) {
                        return do_child(argc -1, argv + 1);
                }else {
                        do_trace(child);
                }

        return 0;
}