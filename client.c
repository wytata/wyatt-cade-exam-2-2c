#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in server_address;
    struct sockaddr_in hints;
    struct hostent *server;
    char buffer[256];

    if (argc < 3)
    {
        fprintf(stderr, "usage %s hostname port\n", argv[0]);
        exit(0);
    }
    
    /*
     Read the server port number
    */
    // TODO
    portno = atoi(argv[2]);

    /*
     Create a socket
    */ 
    // TODO
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Could not open socket.");
    }

    /*
    Read the server hostname
    */   
    // TODO
    server = gethostbyname(argv[1]);

    /*
    The function bzero() sets all values in a buffer to zero.
    */
    bzero((char *)&server_address, sizeof(server_address));

    /*
    The variable server_address is a structure of type struct sockaddr_in. This structure has four fields.
    Configure the server_address struct accordingly.
    */
    // TODO
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(portno);
    server_address.sin_addr.s_addr = INADDR_ANY;
    

    /*
    Establish a connection to the server using the socket and the server_address configured above.
    */
    // TODO
    int connectResult = connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));
    if (connectResult < 0) {
        error("connection unsuccessful");
    }
    /*
    Prompt the user to enter a message, use fgets to read the message from stdin.
    */
    printf("Please enter the message: ");
    bzero(buffer, 256);
    fgets(buffer, 255, stdin);

    /*
    Write the message above to the socket.
    */
    // TODO
    int writeResult = write(sockfd, buffer, sizeof(buffer));
    if (writeResult < 0) {
        error("Write to socket failed.");
    }

    /*
    Read the reply from the socket.
    */
    // TODO
    bzero(buffer, 256);
    n = read(sockfd, buffer, 256);
    if (n < 0) {
        error("Read from socket failed.");
    }

    /*
     Print the server response and close the socket
    */
    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}