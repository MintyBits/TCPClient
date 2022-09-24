#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "includes.h"

enum TCPConnectionErrors {
	S_SUCESS = 0,

	E_WSOCK_CREATE = -1,
	E_SOCK_CREATE = -2,
	E_SOCK_CONNECT = -3,
	E_SOCK_WRITE = -4,
	E_SOCK_READ = -5,
	E_WSOCK_STARTUP = -6,
};

class TCPClient {
private:
	SOCKET Conn;
	struct sockaddr_in ConnInformation;
public:
	TCPClient(char* ipAddr, int port);
	~TCPClient();

	int Connect();

	int Read(char* buffer, int len);
	int Write(char* buffer, int len);
};