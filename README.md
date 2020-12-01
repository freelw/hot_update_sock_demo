# hot_update_sock_demo

## demo的意思

    server.cpp --> server
    update.cpp --> update

    两个cpp文件分别生成两个程序
    server接受一个tcp连接，并在接收一定的数据后启动update程序，并将连接交给update程序

    update可以在客户端不重启的前提下继续接收客户端发送的数据