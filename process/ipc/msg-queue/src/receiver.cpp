#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

const char* FILENAME = "/myqueue";

int main()
{
    mqd_t mq;
    char buffer[256];

    // 메시지 큐 열기
    mq = mq_open(FILENAME, O_RDONLY);
    if (mq == -1)
    {
        perror("mq_open");
        exit(1);
    }

    // 메시지 받기
    if (mq_receive(mq, buffer, 256, NULL) == -1)
    {
        perror("mq_receive");
        exit(1);
    }

    printf("Message received: %s\n", buffer);

    // 메시지 큐 닫기 및 삭제
    mq_close(mq);
    mq_unlink(FILENAME);
    return 0;
}
