#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4445

int main(){

    char* ch;
    int clientSocket;
    struct sockaddr_in serverAddr;
    char message[1024] , server_reply[1024], *m;

    clientSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); // creating client socket
    printf("Client Socket Created Sucessfully.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr)); /* zero out structure */

    serverAddr.sin_family = AF_INET; //address family
    serverAddr.sin_port = htons(PORT);  //port #
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Machine IP

            /*Connects Client to Server*/
    connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    printf("Connected to Server.\n");


    printf("Enter message : ");
    scanf("%s" , message);
        
        //Send some data to server
    send(clientSocket , message , strlen(message) , 0);
    
        
        //Receive a reply from the server
    recv(clientSocket , server_reply , 1024 , 0);
    
        
    puts("Server reply :");
    puts(server_reply);


    //printf("[+]Data Recv: %s\n", server_reply);
    printf("Closing the connection.\n");
    //close(clientSocket);

} 
