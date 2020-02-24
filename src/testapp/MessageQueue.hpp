#pragma once

#include <memory>
#include <string>

#include <boost/interprocess/managed_shared_memory.hpp>

using ManagedSharedMemory = boost::interprocess::managed_shared_memory;

class MessageQueue
{
	enum class eModeOption
	{
		CREATE = 0,
		OPEN = 1,
	};

	static constexpr std::size_t ALIGNMENT = 65536;

public:
	MessageQueue(const std::string& name);
	MessageQueue(const std::string& name, std::size_t bufferSize);
	~MessageQueue();

public:
	int32_t Send(const void* buffer, std::size_t bufferSize);
	int32_t Receive(void* buffer, std::size_t bufferSize);

private:
	std::string mName;
	eModeOption mModeOption;
	std::shared_ptr<ManagedSharedMemory> mSharedMemoryPool;
};
