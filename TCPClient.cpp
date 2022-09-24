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
		return TCPConnectionErrors::E_WSOCK_STARTUP;

	// Create the Socket
	this->Conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (this->Conn == INVALID_SOCKET)
		return TCPConnectionErrors::E_SOCK_CREATE;

	// Connect
	if (connect(this->Conn, (struct sockaddr*)&this->ConnInformation, sizeof(this->ConnInformation)) < 0)
		return TCPConnectionErrors::E_SOCK_CONNECT;

	return TCPConnectionErrors::S_SUCESS;
}

int TCPClient::Read(char* buffer, int len)
{
	if (recv(this->Conn, buffer, len, 0) < 0)
		return TCPConnectionErrors::E_SOCK_WRITE;
	return TCPConnectionErrors::S_SUCESS;
}

int TCPClient::Write(char* buffer, int len)
{
	if (send(this->Conn, buffer, len, 0) < 0)
		return TCPConnectionErrors::E_SOCK_WRITE;
	return TCPConnectionErrors::S_SUCESS;
}
