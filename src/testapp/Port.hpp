#pragma once

#include <memory>
#include <string>

#include <boost/interprocess/managed_shared_memory.hpp>

using ManagedSharedMemory = boost::interprocess::managed_shared_memory;

class SharedMemory
{
	enum class eModeOption
	{
		CREATE = 0,
		OPEN = 1,
	};

public:
	SharedMemory(const std::string& name);
	SharedMemory(const std::string& name, std::size_t bufferSize);
	~SharedMemory();

public:
	std::shared_ptr<ManagedSharedMemory> Ptr();

private:
	std::string mName;
	eModeOption mModeOption;
	std::shared_ptr<ManagedSharedMemory> mManagedSharedMemoryPtr;
};

class Port
{
public:
	Port(const std::string& name);
	Port(const std::string& name, std::size_t bufferSize);
	~Port();

public:
	void Send();
	void Receive();

private:
	SharedMemory mSharedMemory;
};
