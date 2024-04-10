#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#define PORT 8080
int main(int argc, char const* argv[])

{
int server_fd=socket(AF_INET,SOCK_STREAM,0),new_socket;
struct sockaddr_in address;
int opt=1;
ssize_t valread;
char buffer[1024]={0};
char buffer1;
char* hello ="Hello from server";
socklen_t addrlen =sizeof(address);
if(server_fd<0)
{
printf("No socket ");
}

else{
printf("Socket present \n");
printf("The fd of the socket is %d\n",server_fd);
}
if((setsockopt(server_fd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&>{
printf("Reuse port is not enabled");
}

else{
printf("Reuse port| address is enabled\n");
}

address.sin_family=AF_INET;
address.sin_addr.s_addr=INADDR_ANY;
address.sin_port=htons(PORT);

if(bind(server_fd,(struct sockaddr*)&address,sizeof(address))<0){
printf("Bind failed\n");
}

else{
printf("Binded to the local port successfully\n");
}

if(listen(server_fd,3)<0){
printf("Listening failed");
}

else{
printf("Listening on the local port is successfull\n");
}

if((new_socket=accept(server_fd,(struct sockaddr*)&address,&add>printf("Not accepted");
}
else{
printf("Accepted from the client \n");
}
valread = read(new_socket,buffer,1024-1);
printf("%s\n",buffer);
int j=strlen(buffer);
int flag=0;
for(int i=0;i<strlen(buffer)/2;i++)
{
//printf("Inside for   value of i : %d , value\n");
if(buffer[i]==buffer[j-1])
{
j--;
flag=0;
}
else{
//printf("The given message is  not a palindrome\n");
hello="Not  a palindrome";
flag=1;
break;
}
}
if(flag==0){
//printf("The given message is a palindrome\n");
hello="The given string is palindrome";
}
send(new_socket,hello,strlen(hello),0);
printf("Message sent to client\n");
close(new_socket);
close(server_fd);
return 0;
}
