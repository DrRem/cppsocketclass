#include "lib/socketLink.h"

int main() {
    socketLink SendPackets; //数据包发送器
    SendPackets.send("1145141919810");
    return 0;
}
