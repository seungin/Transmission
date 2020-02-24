#pragma once

#include <cstdint>
#include <memory>
#include <string>

class MessageQueue;

class Port
{
public:
	Port(const std::string& name);
	Port(const std::string& name, std::size_t bufferSize);
	~Port();

public:
	int32_t Send();
	int32_t Receive();

private:
	std::shared_ptr<MessageQueue> mMessageQueue;
};
