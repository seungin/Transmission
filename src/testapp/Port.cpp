#include <iostream>

#include "Port.hpp"
#include "MessageQueue.hpp"

Port::Port(const std::string& name)
	: mMessageQueue(std::make_shared<MessageQueue>(name))
{
}

Port::Port(const std::string& name, std::size_t bufferSize)
	: mMessageQueue(std::make_shared<MessageQueue>(name, bufferSize))
{
}

Port::~Port()
{
}

int32_t Port::Send()
{
	std::string message = "Hello";
	int32_t bytesWritten = mMessageQueue->Send(message.data(), message.length() + 1);
	std::cout << "bytesWritten: " << bytesWritten << '\n';
	return bytesWritten;
}

int32_t Port::Receive()
{
	std::vector<char> buffer(1024);
	int32_t bytesRead = mMessageQueue->Receive(buffer.data(), buffer.size());
	std::cout << "bytesRead: " << bytesRead << ", bufferData: " << buffer.data() << '\n';
	return bytesRead;
}
