#include "Port.hpp"
#include "NodeHandle.hpp"

int main(int argc, char* argv[])
{
    txn::NodeHandle nodeHandle;
    txn::ServiceHandle serviceHandle = nodeHandle.RegisterService("service");
    nodeHandle.AdvertiseTopic(serviceHandle, "topic");
    serviceHandle.Run();

    Port senderPort("test", 1024 * 1024);
    senderPort.Send();
    Port receiverPort("test");
    receiverPort.Receive();
    return 0;
}
