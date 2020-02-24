#pragma once

#include <string>

namespace txn
{
	class ServiceHandle
	{
	public:
		ServiceHandle(const std::string& name);
		~ServiceHandle();

	public:
		bool Run();

	private:
		std::string mName;
	};
}
