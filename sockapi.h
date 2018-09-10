#ifndef __SOCK_API__
#define __SOCK_API__

#include <stdio.h>

#define		BACK_LOG_NUM			256

class CSockApi
{
public:
    CSockApi();
    CSockApi(int sock);

    virtual ~CSockApi();

    int get_status();
    int get_sock();
    int get_peer(char* szPeer);
    int get_local(char* szLocal);
    void set_port(int nPort);
    void set_readTimeOut(int nSec);
    void set_writeTimeOut(int nSec);

    int readN(char* pBuf, int nLen);
    int readNT(char* pBuf, int nLen);
    int writeN(char* pBuf, int nLen);
protected:
    int m_nSock;
    int m_nPort;
    int m_nStatus;
    int m_nReadTimeOut;
    int m_nWriteTimeOut;
};

class CServerSock : public CSockApi
{ 
public:
    int listen();
    int accept();
    void shutdown();
};

class CClientSock : public CSockApi
{
public:
    CClientSock(int nPort, char* szHostName);
    int connect();
    int reconnect(int num);
private:
    char m_szHostName[256];
};

#endif

