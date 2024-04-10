#include<stdlib.h>
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#define PORT 5000
#define MAXLINE 1000
int main(){
        char buffer[100];
        char *message = "Hello client";
        int server_fd,len;
        struct sockaddr_in servaddr,cliaddr;

        server_fd=socket(AF_INET,SOCK_DGRAM,0);
        servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
        servaddr.sin_port=htons(PORT);
        servaddr.sin_family=AF_INET;

        bind(server_fd,(struct sockaddr*)&servaddr,sizeof(servaddr));

        len=sizeof(cliaddr);
        int n = recvfrom(server_fd,buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,&len);
        buffer[n]='\0';
        puts(buffer);

        sendto(server_fd,message,MAXLINE,0,(struct sockaddr*)&cliaddr,sizeof(cliaddr));
}
