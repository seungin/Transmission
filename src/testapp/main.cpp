#include "Port.hpp"

int main(int argc, char* argv[])
{
    Port senderPort("test", 1024 * 1024);
    senderPort.Send();
    Port receiverPort("test");
    receiverPort.Receive();
    return 0;
}
