#include "TCPClient.h"

TCPClient::TCPClient(char* ipAddr, int port)
{
	// Define Server Information
	this->ConnInformation.sin_family = AF_INET;
	this->ConnInformation.sin_port = htons(port);
	this->ConnInformation.sin_addr.s_addr = inet_addr(ipAddr);
}

TCPClient::~TCPClient()
{
	WSACleanup();
	closesocket(Conn);
}

int TCPClient::Connect()
{
	// Initalize WSA
	WSADATA wsa;

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return -1;

	// Create the Socket
	this->Conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (this->Conn == INVALID_SOCKET)
		return -2;

	// Connect
	if (connect(this->Conn, (struct sockaddr*)&this->ConnInformation, sizeof(this->ConnInformation)) < 0)
		return -3;

	return 0;
}

int TCPClient::Read(char* buffer, int len)
{
	if (recv(this->Conn, buffer, len, 0) < 0)
		return -4;
	return 0;
}

int TCPClient::Write(char* buffer, int len)
{
	if (send(this->Conn, buffer, len, 0) < 0)
		return -5;
	return 0;
}
