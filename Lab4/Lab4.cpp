
#include <iostream>
#include "List.h"
#include "IMessage.h"
#include "Logger.h"
#include "ILoggerChannel.h"
#include <fstream>

int main()
{
    std::cout << "mylogs.txt should contain: Warn bbbb for tests to work" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "TestLoggerLogFileUnrestricted:" << std::endl;
    ILogger a1(new ILoggerChannelFile(Error, None, "mylogs.txt"));
    std::string b1 = a1.log(0);
    std::cout << "Test output: " << (b1 == "Warn bbbb") << std::endl;
    std::cout << "Log saved: " << b1 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "TestLoggerLogFileRestricted:" << std::endl;
    ILogger a2(new ILoggerChannelFile(Trace, None, "mylogs.txt"));
    std::string b2 = a2.log(0);
    std::cout << "Test output: " << (b2 == "") << std::endl;
    std::cout << "Log saved: " << b2 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "TestLoggerLogFileSecondChannel:" << std::endl;
    ILogger a3(new ILoggerChannelFile(Trace, None, "mylogs.txt"));
    a3.add_channel(new ILoggerChannelFile(Error, Info, "mylogs.txt"));
    std::string b3 = a3.log(1);
    std::cout << "Test output: " << (b3 == "Warn bbbb") << std::endl;
    std::cout << "Log saved: " << b3 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "TestLoggerLogFileRemovedChannel:" << std::endl;
    ILogger a4(new ILoggerChannelFile(Trace, None, "mylogs.txt"));
    a4.add_channel(new ILoggerChannelFile(Error, Info, "mylogs.txt"));
    a4.remove_channel();
    std::string b4 = a4.log(1);
    std::cout << "Test output: " << (b4 == "") << std::endl;
    std::cout << "Log saved: " << b4 << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "TestLoggerLogConsole:" << std::endl;
    ILogger a5(new ILoggerChannelConsole(Trace, None));
    std::string b5 = a5.log(0);
    std::cout << "Log saved: " << b5 << std::endl;
}
