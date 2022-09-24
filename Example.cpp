#include "TCPClient.h"

int main()
{
	// Create the Class and cast as char because cpp
	TCPClient Client((char*)"127.0.0.1", 2000);

	// Connect to remote host
	if (Client.Connect() < 0)
		return -1;

	// Send "Hello, World!" Message
	char buffer[24] = "Hello, World!";
	if (Client.Write(buffer, strlen(buffer)) < 0)
		return -2;

	// Clear the buffer
	memset(buffer, 0, sizeof(buffer));

	// Receive a message
	if (Client.Read(buffer, sizeof(buffer)) < 0)
		return -3;

	std::cout << buffer;

	return 0;
}