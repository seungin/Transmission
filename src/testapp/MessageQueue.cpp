#include <iostream>

#include "MessageQueue.hpp"

MessageQueue::MessageQueue(const std::string& name)
	: mName(name)
	, mModeOption(eModeOption::OPEN)
	, mSharedMemoryPool()
{
	mSharedMemoryPool = std::make_shared<ManagedSharedMemory>
		(boost::interprocess::open_only, name.c_str());
}

MessageQueue::MessageQueue(const std::string& name, std::size_t bufferSize)
	: mName(name)
	, mModeOption(eModeOption::CREATE)
	, mSharedMemoryPool()
{
	boost::interprocess::shared_memory_object::remove(mName.c_str());

	mSharedMemoryPool = std::make_shared<ManagedSharedMemory>
		(boost::interprocess::create_only, name.c_str(), bufferSize);

	boost::ulong_long_type bytesFree = mSharedMemoryPool->get_free_memory();

	void* address = mSharedMemoryPool->allocate(bytesFree / 2);

	boost::interprocess::managed_shared_memory::handle_t handle =
		mSharedMemoryPool->get_handle_from_address(address);

	std::cout << "bytesFree: " << bytesFree << std::endl;
	std::cout << "address: " << address << std::endl;
	std::cout << "handle: " << handle << std::endl;
}

MessageQueue::~MessageQueue()
{
	if (mModeOption == eModeOption::CREATE)
	{
		boost::interprocess::shared_memory_object::remove(mName.c_str());
	}
}

int32_t MessageQueue::Send(const void* buffer, std::size_t bufferSize)
{
	return 0;
}

int32_t MessageQueue::Receive(void* buffer, std::size_t bufferSize)
{
	return 0;
}
