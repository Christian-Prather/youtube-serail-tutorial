#include "third-party/include/serial/serial.h"
#include <iostream>
#include "thread"
int main()
{
    serial::Serial my_serial("/dev/ttyACM0", 19200, serial::Timeout::simpleTimeout(3000));

    if (my_serial.isOpen())
    {
        std::cout << "Port opened succesfully" << std::endl;
    }
    else
    {
        std::cout << "Port failed to open" << std::endl;
    }
    my_serial.flushOutput();

    std::string test_string = "hi\n";
    // for (int i = 0; i < 3; i++)
    // {
    //     size_t bytesWritten = my_serial.write(test_string);

    //     // std::string result = my_serial.read(test_string.length() + 1);
    //     std::cout << "Bytes sent: " << bytesWritten << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    // }


    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    my_serial.flushInput();
    std::string response = my_serial.read(6);
    std::cout << "Arduion: " << response << std::endl;
}