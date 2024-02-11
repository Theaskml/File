#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/wait.h>
#include<string.h>
#define PORT 8080 
int main(){
int sockfd , new_socket;
struct sockaddr_in server_addr , client_addr;
char* hello = "hello from server";
//char* ip = "192.168.69";
char buffer[1024];
int addrlen = sizeof(client_addr);
sockfd=socket(AF_INET , SOCK_STREAM , 0);
 
server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(PORT);
server_addr.sin_addr.s_addr=INADDR_ANY;

bind(sockfd,(struct sockaddr*)&server_addr , sizeof(server_addr));
listen(sockfd,5);
new_socket=accept(sockfd,(struct sockaddr*)&client_addr,&addrlen);
send(new_socket,hello,strlen(hello),0);
recv(new_socket,buffer,sizeof(buffer),0);
printf("the msg %s",buffer);


}
