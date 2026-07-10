#ifndef APPLICATION_HPP
#define APPLICATION_HPP

class Application
{
public:

    void run();

private:

    void initialize();

    void scanDevices();

    void showDeviceHealth();

    void shutdown();
};

#endif