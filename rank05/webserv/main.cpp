#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

int	main(void)
{
	/*
	http://www.google.com:80
		- http: protocol
		- www.google.com: domain name
		- 80: port number
	If I press enter, the browser will
		- connect to the server
		- send a request
		- receive a response
		- display the response
	To connect to the server, the browser needs to know the IP address of the server.
		- The browser will ask the DNS server for the IP address of the server.
		- The DNS server will respond with the IP address of the server.
		- The browser will connect to the server using the IP address.
	When do we need sockets?
		- When we want to connect to a server.
		- When we want to send a request to the server.
		- When we want to receive a response from the server.
	Then, we need to create a socket and use these information to connect to the server :
		- Protocol
		- IP address
		- Port number
	*/
	
	// a listening socket
	int	sockfd;
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd == -1)
	{
		std::cerr << "Error: socket creation failed" << std::endl;
		return (1);
	}

	// setsockopt() is used to allow the socket to be reused
	int on = 1;
	if (setsockopt(sockfd, SOL_SOCKET,  SO_REUSEADDR | SO_REUSEPORT, &on, sizeof(int)) < 0)
	{
		std::cerr << "error: setsockopt() failed" << std::endl;
		close(sockfd);
		return (1);
	}

	// sockaddr_in structure is used to specify the address of the socket
	struct sockaddr_in address;
	const int PORT = 8080; // Where the clients can reach at
	memset((char *)&address, 0, sizeof(address));
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = htonl(INADDR_ANY);
	address.sin_port = htons(PORT);
	// bind() is used to bind the socket to the address
	if ((bind(sockfd, (struct sockaddr *) &address, sizeof(address))) < 0)
	{
		std::cerr << "error: socket creation" << std::endl;
		exit(1);
	}

	// listen() is used to listen for incoming connections
	if (listen(sockfd, 3) < 0)
	{
		std::cerr << "error: listern call" << std::endl;
		exit(EXIT_FAILURE);
	}

	// accept() is used to accept a connection
	int new_socket;
	int addrlen = sizeof(address);
	if ((new_socket = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
	{
		std::cerr << "error: accept call" << std::endl;
		exit(EXIT_FAILURE);
	}

	// close the socket
	close(sockfd);
	return (0);
}

// int	main(void)
// {
// 	int	sockfd;
// 	sockfd = socket(AF_INET, SOCK_STREAM, 0);
// 	/*
// 	AF_INET:
// 		Communication domain in which the socket should be created (IPv4).
// 	SOCK_STREAM:
// 		We want to specify the virtual circuit service where messages 
// 		will sail through the network in a reliable way.
// 	0:
// 		Protocol value for Internet Protocol (IP).
// 	*/
// 	if (sockfd == -1)
// 	{
// 		std::cerr << "Error: socket creation failed" << std::endl;
// 		return (1);
// 	}
// 	/*************
// 	**************
// 	**************
// 	**************
// 	**************
// 	*************/
// 	int on = 1;
// 	if (setsockopt(sockfd, SOL_SOCKET,  SO_REUSEADDR | SO_REUSEPORT, &on, sizeof(int)) < 0)
// 	{
// 		std::cerr << "error: setsockopt() failed" << std::endl;
// 		close(sockfd);
// 		return (1);
// 	}
// 	/*************
// 	**************
// 	**************
// 	**************
// 	**************
// 	*************/
// 	struct sockaddr_in address;
// 	const int PORT = 8080; //Where the clients can reach at
// 	/* htonl converts a long integer (e.g. address) to a network representation */
// 	/* htons converts a short integer (e.g. port) to a network representation */
// 	memset((char *)&address, 0, sizeof(address));
// 	address.sin_family = AF_INET;
// 	address.sin_addr.s_addr = htonl(INADDR_ANY);
// 	address.sin_port = htons(PORT);
// 	if ((bind(sockfd, (struct sockaddr *) &address, sizeof(address))) < 0)
// 	{
// 		std::cerr << "error: socket creation" << std::endl;
// 		exit(1);
// 	}
// 	/*************
// 	**************
// 	**************
// 	**************
// 	**************
// 	*************/
// 	if (listen(sockfd, 3) < 0)
// 	{
// 	  std::cerr << "error: listern call" << std::endl;
// 		exit(EXIT_FAILURE);
// 	}
	
// 	int addrlen = sizeof(address);
// 	if ((new_socket = accept(sockfd, (struct sockaddr *)&address, (socklen_t*)addrlen)) < 0)
// 	{
// 		std::cerr << "error: accept call" << std::endl;
// 		exit(EXIT_FAILURE);
// 	}
// 	return (0);
// }
