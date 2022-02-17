//
// Created by Administrator on 2022/2/7.
//

#include "socketLink.h"

socketLink::socketLink() {
    tcp_server = socket(AF_INET,SOCK_STREAM,0);    //初始化socket
    serverAddress.sin_family = AF_INET;   //Ipv4
    serverAddress.sin_addr.s_addr = inet_addr("0.0.0.0"); //设置IP
    serverAddress.sin_port = htons(62610); //设置端口
    flag = bind(tcp_server,(const struct sockaddr*)&serverAddress,sizeof (serverAddress)); //绑定
    if(flag != 0){
        std::cout<<"端口绑定失败"<<std::endl;
        exit(1);
    }
    listen(tcp_server, SOMAXCONN); //开始监听
    std::cout<<"INFO:等待客户端"<<std::endl;

    clientAddressSize = sizeof(clientAddress);
    tcp_client = accept(tcp_server,(struct sockaddr*)&clientAddress,&clientAddressSize);    //存储接入的客户端信息
    std::cout<<"客户端接入："<<clientAddress.sin_addr.s_addr<<":"<<clientAddress.sin_port<<std::endl;

}

socketLink::~socketLink() {
    close(tcp_client);  //关闭与客户端的连接
    close(tcp_server);  //关闭服务端监听
}

int socketLink::send(const char *buffer) const {
    write(tcp_client,buffer,1500);
    return 0;
}

int socketLink::receive(char *buffer) const {
    read(tcp_client,buffer,1500);
    return 0;
}
