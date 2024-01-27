#include "client.h"


TCPClient::TCPClient(const std::string& ipaddr, int port) {
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
		throw std::runtime_error("TCPClient: failed to create socket, check that you have valid permissions");
	}

	struct sockaddr_in addr;
	addr.sin_addr.s_addr = inet_addr(ipaddr.c_str());
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	if(connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
		throw std::runtime_error("TCPClient: failed to connect to remote host");
	}
}

TCPClient::~TCPClient() {
	close(sockfd);
}


ssize_t TCPClient::send(const void* buffer, int bufsize) {
	return write(sockfd, buffer, bufsize);
}

ssize_t TCPClient::recv(void* buffer, int bufsize) {
	return read(sockfd, buffer, bufsize);
}
