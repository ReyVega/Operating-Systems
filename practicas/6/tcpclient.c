#include<netdb.h>
#include<stdio.h>
#include<sys/socket.h>
#include<strings.h>
#include<string.h>
#include<unistd.h>
#include<netinet/in.h>

extern int h_errno;

int main(int argc, char **argv) {
    char *hostName = argv[1];
    char *message = "GET / HTTP/1.0\r\n\r\n";
    char c;

    struct sockaddr_in serverAddress;
    struct hostent *serverInfo = gethostbyname(hostName);
    bzero(&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(2727);
    //serverAddress.sin_addr = serverInfo -> h_addr_list[0];
    bcopy((char *)serverInfo->h_addr, (char *)&serverAddress.sin_addr.s_addr,serverInfo->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(sockfd, (struct sockaddr *)&serverAddress , sizeof(serverAddress));
    
    write(sockfd, message, strlen(message));
    while(read(sockfd, &c, 1)) {
        printf("%c",c);
    }
    close(sockfd);
    printf("\n");
    return 0;
}