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

    /*
     Create a socket
    */ 
    // TODO

    /*
    Read the server hostname
    */   
    // TODO

    /*
    The function bzero() sets all values in a buffer to zero.
    */
    bzero((char *)&server_address, sizeof(server_address));

    /*
    The variable server_address is a structure of type struct sockaddr_in. This structure has four fields.
    Configure the server_address struct accordingly.
    */
    // TODO

    /*
    Establish a connection to the server using the socket and the server_address configured above.
    */
    // TODO
    
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

    /*
    Read the reply from the socket.
    */
    // TODO

    /*
     Print the server response and close the socket
    */
    printf("%s\n", buffer);
    close(sockfd);
    return 0;
}