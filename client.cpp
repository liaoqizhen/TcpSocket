#include "commen.h"
#include "Socket.h"
#include "SocketException.h"

int main()
{
    signal(SIGPIPE, SIG_IGN);
    try
    {
        TCPClient client(8001, "127.0.0.1");
        std::string msg;
        while (getline(cin, msg))
        {
            client.send(msg);
            msg.clear();
            client.receive(msg);
            cout << msg << endl;
            msg.clear();
        }
    }
    catch (const SocketException &e)
    {
        cerr << e.what() << endl;
    }
}
