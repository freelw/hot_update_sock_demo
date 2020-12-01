# hot_update_sock_demo

## demo的意思

    server.cpp --> server
    update.cpp --> update

    两个cpp文件分别生成两个程序
    server接受一个tcp连接，并在接收一定的数据后启动update程序，并将连接交给update程序
    update可以在客户端不重启的前提下继续接收客户端发送的数据

    make 直接编译

## 运行效果

    服务端
    [root@VM-0-11-centos test]# ./server
    i'm [server].
    1234

    program updated.
    updated recv: 1234
    
    updated recv: 1234

    客户端使用nc
    [root@VM-0-11-centos ~]# nc 127.0.0.1 1234
    1234
    1234
    1234