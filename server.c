#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUF_SIZE 10

int main(){
    //创建套接字
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int bind_suceess = 0;

    //将套接字和IP、端口绑定
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    serv_addr.sin_port = htons(1234);  //端口
    bind_suceess = bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    if (bind_suceess == -1) {
        printf("bind failed\n");
        return 0;
    }

    //进入监听状态，等待用户发起请求
    listen(serv_sock, 20);

    //接收客户端请求
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

    //向客户端发送数据
    char buffer[BUF_SIZE];
    int strLen = recv(clnt_sock, buffer, BUF_SIZE, 0);
    int success_flag;
    success_flag = send(clnt_sock, buffer, strLen, 0);
    printf("success_flag: %d\n", success_flag);

    printf("shutdown read\n");
    shutdown(clnt_sock, SHUT_RD);
    sleep(10);

    printf("shutdown write\n");
    shutdown(clnt_sock, SHUT_WR);
    sleep(10);

    //关闭套接字
    printf("shutdown write\n");
    close(clnt_sock);
    sleep(10);
    close(serv_sock);

    return 0;
}
