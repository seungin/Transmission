#include "NodeHandle.hpp"

namespace txn
{
	NodeHandle::NodeHandle()
	{
	}

	NodeHandle::~NodeHandle()
	{
	}

	ServiceHandle NodeHandle::RegisterService(const std::string& serviceName)
	{
		return ServiceHandle(serviceName);
	}

	bool NodeHandle::AdvertiseTopic(const ServiceHandle& serviceHandle, const std::string& topicName)
	{
		return false;
	}
}
