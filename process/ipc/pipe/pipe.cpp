#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const int READ_END = 0;
const int WRITE_END = 1;
const int BUFFER_SIZE = 16;

int main(void)
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("pipe");
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }

    if (pid == 0)
    {
        const char* msg = "Hello, Pipe!";
        close(fd[READ_END]);
        ssize_t bytesWritten = write(fd[WRITE_END], msg, strlen(msg));
        printf("bytesWritten: %ld\n", bytesWritten);
        return 0;
    }
    waitpid(pid, NULL, 0);
    close(fd[WRITE_END]);

    char buf[BUFFER_SIZE];
    memset(buf, 0, BUFFER_SIZE);

    ssize_t bytesRead = read(fd[READ_END], buf, BUFFER_SIZE);
    printf("%s, %ld\n", buf, bytesRead);
    return 0;
}
