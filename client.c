#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 20

int main() {
    int connect_suceess = 0;
    //创建套接字
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    //向服务器（特定的IP和端口）发起请求
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    connect_suceess = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    if (connect_suceess == -1) {
        printf("connect failed\n");
        return 0;
    }

    //获取用户输入的字符串并发送给服务器
    char bufSend[BUF_SIZE] = {0};
    printf("Input a string: ");
    scanf("%s", bufSend);
    send(sock, bufSend, strlen(bufSend), 0);

    //读取服务器传回的数据
    char buffer[BUF_SIZE];
    read(sock, buffer, sizeof(buffer)-1);

    printf("Message form server: %s\n", buffer);

    printf("shutdown read\n");
    shutdown(sock, SHUT_RD);
    sleep(5);

    printf("shutdown write\n");
    shutdown(sock, SHUT_WR);

    sleep(20);

    //关闭套接字
    close(sock);
    return 0;
}
