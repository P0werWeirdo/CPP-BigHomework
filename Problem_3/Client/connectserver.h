#ifndef CONNECTSERVER_H
#define CONNECTSERVER_H
#include<QTcpSocket>

class ConnectServer
{
public:
    ConnectServer();

    static QTcpSocket *con;//与服务端建立连接

};

#endif // CONNECTSERVER_H
