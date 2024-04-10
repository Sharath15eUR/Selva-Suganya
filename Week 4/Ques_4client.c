#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
#define PORT 8080

int main(int argc, char const* argv[])
{
int status,valread,client_fd;
struct sockaddr_in serv_addr;
char* hello="Hello from client";
char buffer[1024]={0};
client_fd=socket(AF_INET,SOCK_STREAM,0);
if(client_fd<0){
printf("No socket created\n");
}
else{
printf("Socket created successfully\n");
}
serv_addr.sin_family=AF_INET;
serv_addr.sin_port=htons(PORT);
if(inet_pton(AF_INET,"127.0.0.1",&serv_addr.sin_addr)<=0)
{
printf("Invalid Ip address\n");
}
else{
printf("IP of the server is assigned/n");
}
status=connect(client_fd,(struct sockaddr*)&serv_addr,sizeof(se>if(status<0)
{
printf("Connection failed\n");
}
else{
printf("Connected with server\n");
}
send(client_fd,hello,strlen(hello),0);
printf("Hello message is sent\n");
valread=read(client_fd,buffer,1024-1);
printf("%s\n",buffer);
close(client_fd);
return 0;
}
