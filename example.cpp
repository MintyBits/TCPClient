#include "client.h"
#include <string.h>

int main() {
	TCPClient client("127.0.0.1", 2000);
	char buffer[512] = "Hello, World!\n";
	client.send(buffer, strlen(buffer));
	return 0;
}
