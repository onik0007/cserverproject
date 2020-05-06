#include <stdio.h>
#include <sys/types.h>	/* system type defintions */
#include <sys/socket.h>	/* network system functions */
#include <netinet/in.h>	/* protocol & struct definitions */
#include <stdlib.h>	/* exit() warnings */
#include <string.h>	/* memset warnings */
#include <unistd.h>

int listeningsock,portnum;
struct sockaddr_in	host_addr;
char buffer[300];
int x;


int main(int argc, char *argv[]){

//creating listening socket//


listeningsock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP); //socket(domain,type of input,IP)

if(listeningsock<0){

printf("socket creation failed\n");
exit(0);
        }

else printf("Socket sucessfully created\n");

portnum=atoi(argv[1]);//converts user input portnum string to int

    //creating an address to bind to
memset(&host_addr, 0, sizeof (host_addr));	/* zero out structure */
   

    host_addr.sin_family = AF_INET;	/* address family */
    host_addr.sin_addr.s_addr = htonl(INADDR_ANY);  /*host machine IP */
    host_addr.sin_port = htons(portnum);



        /* bind socket to the local address */
    x=bind(listeningsock, (struct sockaddr *) &host_addr, sizeof (host_addr));
  
 
    if (x < 0){
        printf("binding failed\n");
        exit(0);
    }
    else  printf("binding sucessful\n");

  x=listen(listeningsock, 5);
    if (x < 0){
        printf("listen() failed\n");
        exit(0);
    }

else printf("Waiting for connection requests....\n");
   


close(listeningsock);//// closes connection to listen socket


}


