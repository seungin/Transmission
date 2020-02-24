#pragma once

#include <string>

#include "ServiceHandle.hpp"

namespace txn
{
	class NodeHandle
	{
	public:
		NodeHandle();
		~NodeHandle();

	public:
		ServiceHandle RegisterService(const std::string& serviceName);
		bool AdvertiseTopic(const ServiceHandle& serviceHandle, const std::string& topicName);
	};
}
