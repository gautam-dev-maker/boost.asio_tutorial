/* how to use asio's asynchronous callback functionality 
by modifying the program from using_time_sync to perform an
asynchronous wait on the timer */

#include<iostream>
#include<boost/asio.hpp>


/*Using asio's asynchronous functionality means having a 
callback function that will be called when an asynchronous operation completes */
void print(const boost::system::error_code& /*e*/){
    std::cout<<"hello, world"<<std::endl;
}

int main(){

    boost::asio::io_service io;
    boost::asio::steady_timer t(io,boost::asio::chrono::seconds(5));

    // this function perfoms the asynchronous wait and we pass print as function callback
    t.async_wait(&print);

    io.run();

    return 0;

}