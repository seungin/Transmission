#include <iostream>

#include <boost/thread.hpp>

int main(int argc, char* argv[])
{
    std::cout << "main() Start." << std::endl;
    boost::this_thread::sleep_for(boost::chrono::seconds(1));
    std::cout << "main() End." << std::endl;
    return 0;
}
