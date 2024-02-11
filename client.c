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
int clientfd;
struct sockaddr_in client_addr;
char* hello="hello from client";
char buffer[1024];
char command[104];
char data[10244];
printf("enter the command:");
scanf("%s",&command);
char* ip="10.0.2.15";

clientfd = socket(AF_INET,SOCK_STREAM,0);

client_addr.sin_family=AF_INET;
client_addr.sin_port=htons(PORT);
client_addr.sin_addr.s_addr=inet_addr(ip);

connect(clientfd,(struct sockaddr*)&client_addr,sizeof(client_addr));
//send(clientfd,hello,strlen(hello),0);
recv(clientfd,buffer,sizeof(buffer),0);
printf("the msg %s",buffer);
FILE * pipe=popen(command,"r");
fread(data,1,sizeof(data),pipe);
send(clientfd,data,sizeof(data),0);

}
