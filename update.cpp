#include <stdio.h>
#include <unistd.h>

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

int main(){
    printf("program updated.\n");
    while(1) {
        char req[5] = {0};
        readed(4, req, 5);
        printf("updated recv: %s\n", req);
    }
    return 0;
}
