//
// Created by Administrator on 2022/2/7.
//

#ifndef PRTPSERVER_SOCKETLINK_H
#define PRTPSERVER_SOCKETLINK_H
#include "iostream"
#include "sys/socket.h"
#include "netinet/in.h"
#include "arpa/inet.h"
#include "unistd.h"

class socketLink {
protected:
    int flag;
    int tcp_server; //socket
    int tcp_client;
    sockaddr_in serverAddress;  //服务端地址
    sockaddr_in clientAddress;    //客户端地址
    socklen_t clientAddressSize;

public:
    socketLink();
    ~socketLink();
    int send(const char buffer[]) const;    //发送数据到客户端
    int receive(char buffer[]) const;  //接收客户端数据
};


#endif //PRTPSERVER_SOCKETLINK_H
