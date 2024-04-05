#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <sys/ptrace.h>
#include <sys/reg.h>
#include <sys/wait.h>
#include <sys/types.h>

int do_child(int argc, char** argv) {
        char* args[argc + 1];
        memcpy(args, argv, argc * sizeof(char*));
        args[argc] = NULL;

        ptrace(PTRACE_TRACEME);

        kill(getpid(), SIGSTOP);
        return execvp(args[0], args);
}

int wait_for_syscall(pid_t child);

int do_trace(pid_t child) {
        int status, syscall, retval;
        waitpid(child , &status, 0);
        ptrace(PTRACE_SETOPTIONS, child, 0 , PTRACE_O_TRACESYSGOOD);

                while(1) {
                        
                        if (wait_for_syscall(child) != 0);
                        syscall = ptrace(PTRACE_PEEKUSER, child, sizeof(long)* ORIG_RAX);
                        fprintf(stderr, "syscall(%d) = ", syscall);
                        if (wait_for_syscall(child) != 0) break;
                        retval = ptrace((PTRACE_PEEKUSER), child, sizeof(long)*RAX);
                        fprintf(stderr, "%d\n", retval);
                }

                return 0;
        
}

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