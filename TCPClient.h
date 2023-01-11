#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>

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
