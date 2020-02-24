#include "ServiceHandle.hpp"

namespace txn
{
	ServiceHandle::ServiceHandle(const std::string& name)
		: mName(name)
	{
	}

	ServiceHandle::~ServiceHandle()
	{
	}

	bool ServiceHandle::Run()
	{
		return false;
	}
}
