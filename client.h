#pragma once

#include <iostream>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

class TCPClient {
public:
	TCPClient(const std::string& ipaddr, int port);
	~TCPClient();

	ssize_t send(const void* buffer, int bufsize);
	ssize_t recv(void* buffer, int bufsize);
private:
	int sockfd;
};
