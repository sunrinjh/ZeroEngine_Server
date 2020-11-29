#pragma once
#include <Zero.h>

#define Socket SocketClient::instance()
class SocketClient
{
private:

    WSAData wsaData;
    SOCKET hSocket;
    SOCKADDR_IN tAddr = {};
    ZeroVec* playerPos[4] = { new ZeroVec(0,0), new ZeroVec(0,0) ,new ZeroVec(0,0) ,new ZeroVec(0,0)};
    int playerNumber;
    char cBuffer[1024] = {};

public:
    static SocketClient* instance() {
        static SocketClient* instance = new SocketClient();
        return instance;
    }


    SocketClient();
    ~SocketClient();
    void Init();
    void Init(string ip);
    void SetIp(string ip);
    void JoinServer();
    int GetPlayerNumber();
    int GetCurrentPlayerNumber();
    void SendPlayerPos(ZeroVec* zeroVec);
    void GetPlayerPos();
    ZeroVec* GetPlayer1Pos();
    ZeroVec* GetPlayer2Pos();
    ZeroVec* GetPlayer3Pos();
    ZeroVec* GetPlayer4Pos();
    //Debug
    void CoutServerMessage();
};

