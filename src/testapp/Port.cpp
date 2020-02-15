#include <iostream>

#include "Port.hpp"

SharedMemory::SharedMemory(const std::string& name)
	: mName(name)
	, mModeOption(eModeOption::OPEN)
	, mManagedSharedMemoryPtr()
{
	mManagedSharedMemoryPtr = std::make_shared<ManagedSharedMemory>
		(boost::interprocess::open_only, name.c_str());
}

SharedMemory::SharedMemory(const std::string& name, std::size_t bufferSize)
	: mName(name)
	, mModeOption(eModeOption::CREATE)
	, mManagedSharedMemoryPtr()
{
	boost::interprocess::shared_memory_object::remove(mName.c_str());

	mManagedSharedMemoryPtr = std::make_shared<ManagedSharedMemory>
		(boost::interprocess::create_only, name.c_str(), bufferSize);
}

SharedMemory::~SharedMemory()
{
	if (mModeOption == eModeOption::CREATE)
	{
		boost::interprocess::shared_memory_object::remove(mName.c_str());
	}
}

std::shared_ptr<ManagedSharedMemory> SharedMemory::Ptr()
{
	return mManagedSharedMemoryPtr;
}

Port::Port(const std::string& name)
	: mSharedMemory(name)
{
}

Port::Port(const std::string& name, std::size_t bufferSize)
	: mSharedMemory(name, bufferSize)
{
}

Port::~Port()
{
}

void Port::Send()
{
	int* writtenDataPtr = mSharedMemory.Ptr()->construct<int>("Integer")(20200216);
	std::cout << "writtenData: " << *writtenDataPtr << '\n';
}

void Port::Receive()
{
	std::pair<int*, std::size_t> foundDataPair = mSharedMemory.Ptr()->find<int>("Integer");
	int* foundDataPtr = foundDataPair.first;

	if (foundDataPtr)
	{
		std::cout << "foundData: " << *foundDataPtr << '\n';
	}
}
