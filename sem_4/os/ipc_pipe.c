#include<stdio.h>

#define READ 0
#define WRITE 1

int main {

    char *wc_args[] = {"wc", NULL};
    char *grep_args[] = {"grep", "--binary-files=text", "-i", "hai", NULL};
    char *cat_args[] = {"cat", "file.txt", NULL};

    int pid, pfd1[2], pfd2[2];
    
    if (pipe(pfd1) == -1) {
        perror("pipe failed");
        exit(1);
    }

    if (pipe(pfd2) == -1) {
        perror("pipe failed");
        exit(2);
    }

    if (pid = fork() < 0) {
        perror("fork failed");
        exit(3);
    }

    if (pid == 0) {
        close(pfd1[READ]);
        dup2(pfd1[WRITE], WRITE);
        close(pfd1[WRITE]);
        execvp(*cat_args, cat_args)
    }

    else {
        wait(NULL)
        char buffer[100];
        read(pfd1[0], buffer, 99)
        
        if (pid = fork() < 0) {
            perror("fork failed");
            exit(4);
        }

        if (pid == 0) {
            close(pfd1[WRITE]);
            dup2(pfd1[READ], READ);
            close(pfd1[READ]);

            close(pfd2[READ]);
            dup2(pfd2[WRITE], WRITE);
            close(pdf2[WRITE]);

            execvp(*grep_args, grep_args);
        }

        else {
            close(pfd2[WRITE]);
            dup2(pfd2[READ], READ);
            close(pdf2[READ]);

            write(pfd1[1], )

            wait(NULL);

            execvp(*wc_args, wc_args);
        }

    }
}