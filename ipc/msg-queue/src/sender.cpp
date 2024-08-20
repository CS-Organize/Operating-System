#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    mqd_t mq;
    struct mq_attr attr;
    char *msg = "Hello, Process 2!";

    // 메시지 큐 속성 설정
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 256;
    attr.mq_curmsgs = 0;

    // 메시지 큐 생성 및 열기
    mq = mq_open("/myqueue", O_CREAT | O_WRONLY, 0644, &attr);
    if (mq == -1)
    {
        perror("mq_open");
        exit(1);
    }

    // 메시지 보내기
    if (mq_send(mq, msg, strlen(msg) + 1, 0) == -1)
    {
        perror("mq_send");
        exit(1);
    }

    printf("Message sent: %s\n", msg);

    // 메시지 큐 닫기
    mq_close(mq);
    return 0;
}
