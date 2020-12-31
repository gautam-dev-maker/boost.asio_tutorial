/* program to set timer for 5 sec synchronously */

#include <iostream>
// All of the asio classes can be used by simply including the "asio.hpp" header file.
#include <boost/asio.hpp>

int main()
{
    // All programs that use asio need to have at least one I/O execution context, we can also use thread pool
    boost::asio::io_context io;

    // set a timer to expire in 5 secs
    boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));

    //It will not return until the timer has expired, 5 seconds after it was created
    t.wait();

    std::cout << "Hello, world!" << std::endl;
    return 0;
}