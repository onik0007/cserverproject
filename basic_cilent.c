//620112010(Stefan Mitchell)
//620117365(Claude Manning)
//fill in id # here(Danielle Goulbourne)
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>


#define BUF_SIZE	2048
#define	SERVER_IP	"192.168.100.69"
#define SERVER_PORT	10000

int main(int argc, char *argv[]){
    int	sender;
    struct sockaddr_in	address;
    int	x;
    char data[80],buffer[BUF_SIZE];
    int	len,bits;

        
    sender=socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sender < 0){
        printf("socket() failed\n");
        exit(0);
    }

       
    memset(&address, 0, sizeof (address)); 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = inet_addr(SERVER_IP);
    address.sin_port = htons((unsigned short)SERVER_PORT);

    x=connect(sender, (struct sockaddr *) &address, sizeof (address));
    if (x < 0){
        printf("connect() failed\n");
        exit(0);
    }

    while (1){
        printf("Data to be sent ");
        scanf("%s", data);
        if (strcmp(data,"quit") == 0)
            break;

        strcpy(buffer,data);
        len=strlen(data);
        bits=send(sender,buffer,len,0);
    }

    close(sender);
}
