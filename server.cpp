#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
int readed(int fd, char* read_buffer, int length)
{
    int recv_len = 0;
    while (recv_len < length) {
        int read_size = read(fd, read_buffer + recv_len, length - recv_len);
        if (read_size <= 0) {
            break;
        }
        recv_len += read_size;
    }
    return recv_len;
}
int written(int fd, char* write_buffer, int length)
{
    int send_len = 0;
    while (send_len < length) {
        int write_size = write(fd, write_buffer + send_len, length - send_len);
        if (write_size <= 0) {
            break;
        }
        send_len += write_size;
    }
    return send_len;
}
int main(){
    int serv_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;  //使用IPv4地址
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(1234);
    bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    listen(serv_sock, 20);
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    printf("litening 1234\n");
    int clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
    printf("clnt_sock  : %d\n", clnt_sock);
    while(1) {
    char req[5] = {0};
    readed(clnt_sock, req, 5);
    printf("req : %s\n", req);
    char * argv[] = {"update", (char*)0};
    int ret = execv("update", argv);
    printf("err :%d\n", errno);
    printf("exec ret %d\n", ret);
    }
    close(clnt_sock);
    close(serv_sock);
    return 0;
}
