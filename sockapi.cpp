
#include "sockapi.h"

CSockApi::CSockApi():
    m_nSock(0),
    m_nPort(0),
    m_nStatus(0),
    m_nReadTimeOut(0),
    m_nWriteTimeOut(0)
{

}

CSockApi(int sock)
{

}
CSockApi::~CSockApi()
{

}

int CSockApi::get_peer(char* szPeer)
{
  struct sockaddr_in peerAddr;
  socklen_t nLen = sizeof(peerAddr);
  if(getpeername(m_nSock, (struct sockaddr_in*)&peerAddr,(socklen_t*)&nLen ) == 0)
  {
    strcpy(szPeer, inet_ntoa(peerAddr.sin_addr);
    return ntohs(peerAddr.sin_port);
  }
  return -1;
}

int CSockApi::get_local(char* szLocal)
{
  struct sockaddr_in localAddr;
  socklen_t nLen = sizeof(localAddr);
  if(getsockname(m_nSock, (struct sockaddr_in*)&localAddr, (socklen_t*)&nLen) == 0)
  {
    strcpy(szLocal, inet_ntoa(localAddr.sin_addr));
    return ntohs(localAddr.sin_port);
  }
  return -1;
}

int CSockApi::readN(char* pBuf, int nLen)
{
  int nLeft = nLen;
  int nRead = 0;
  while(nLeft > 0)
  {
    nRead = read(m_nSock, pBuf, nLeft);
    if(nRead < 0)
    {
      if(errno == EINTR)
      {
          continue;
      }
      else if (errno == EAGAIN)
      {
          continue;
      }
      return nRead;
    }
    else if (nRead == 0)
    {
      break;
    }
    nLeft -= nRead;
    pBuf += nRead;
  }
  return (nLen - nLeft);
}

int CSockApi::readNT(char* pBuf, int nLen)
{

}

int CSockApi::writeN(char* pBuf, int nLen)
{
    int nLeft = nLen;
    int nWrite = 0;
    while(nLeft > 0)
    {
      nWrite = write(m_nSock, pBuf, nLeft);
      if(nWrite <= 0)
      {
        if(errnor == EINTR)
          continue;

        return nWrite;
      }
      nLeft -= nWrite;
      pBuf += nWrite;
    }
    return(nLen - nWrite);
}

  int CServerSock::listen()
  {
    if(m_nPort == 0)
      return 0;

    int sock = sock(AF_INET, SOCK_STREAM, 0);
    if(sock == -1)
    {
      printf("%s", strerror(errno));
      return 0;
    }

    // level, optname, optval, optlen
    int nOpt = 1;
    if(setsockopt(sock, SOL_SOCK, SO_REUSEADDR, (const char*)&nOpt, sizeof(nOpt)) < 0)
    {
      ::close(sock);
      return 0;
    }

    char bBind = 0;

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADR_ANY);
    addr.sin_port = htons(m_nPort);

    if(bind(sock, (struct sockaddr_in*)&addr, sizeof(addr)) < 0)
    {
      close(sock);
      return 0;
    }

    listen(sock, BACK_LOG_NUM);
    m_nSock = sock;
    m_nStatus = STS_OK
    return sock;

  }
  int CServerSock::accept()
  {
    struct sockaddr_in clientAddr;
    socklen_t nClientLen = 1;
    int nClientSock;

    nClientSock = accept(m_nSock, (struct sockaddr_in*)&clientAddr, (socklen_t*)&nClientLen);

    if(nClientSock == -1)
    {
      m_nStatus = STS_ER;
      return -1;
    }
    return nClientSock;
  }
  void CServerSock::shutdown()
  {

  }