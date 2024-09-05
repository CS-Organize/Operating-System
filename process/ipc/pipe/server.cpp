#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>

const char* FIFO_NAME = "my_fifo";

int main() {
    // FIFO(파이프) 생성
    if (mkfifo(FIFO_NAME, 0666) == -1) {
        perror("mkfifo");
        return 1;
    }

    // FIFO에 쓰기 위한 파일 디스크립터 열기
    int fd = open(FIFO_NAME, O_WRONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    const char* msg = "Hello, Named Pipe!";
    ssize_t bytesWritten = write(fd, msg, strlen(msg));
    if (bytesWritten == -1) {
        perror("write");
    } else {
        std::cout << "bytesWritten: " << bytesWritten << std::endl;
    }

    // 파일 디스크립터 닫기
    close(fd);

    return 0;
}
