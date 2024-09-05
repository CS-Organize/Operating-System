#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>
#include <sys/stat.h>

const char* FIFO_NAME = "my_fifo";
const int BUFFER_SIZE = 256;

int main() {
    // FIFO에 읽기 위한 파일 디스크립터 열기
    int fd = open(FIFO_NAME, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buf[BUFFER_SIZE];
    memset(buf, 0, BUFFER_SIZE);

    ssize_t bytesRead = read(fd, buf, BUFFER_SIZE);
    if (bytesRead == -1) {
        perror("read");
    } else {
        std::cout << "Received message: " << buf << std::endl;
    }

    // 파일 디스크립터 닫기
    close(fd);

    // FIFO 파일 삭제
    if (unlink(FIFO_NAME) == -1) {
        perror("unlink");
    }

    return 0;
}
