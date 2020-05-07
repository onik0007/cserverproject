//620112010(Stefan Mitchell)
//620117365(Claude Manning)
//fill in id # here(Danielle Goulbourne)

#include <stdio.h>
#include <sys/types.h>	/* system type defintions */
#include <sys/socket.h>	/* network system functions */
#include <netinet/in.h>	/* protocol & struct definitions */
#include <stdlib.h>	/* exit() warnings */
#include <string.h>	/* memset warnings */
#include <unistd.h>
#include <arpa/inet.h>



int listeningsock,portnum,sock_recv,addr_size;
struct sockaddr_in	host_addr,recvr_addr;
# define bufsize 2000 
char buffer[bufsize];
int x,bytes_received,grpchoice;
fd_set  readfds,active_fd_set,read_fd_set;	
int select_ret,incoming_len,recv_msg_size;



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
   
    /* get new socket to receive data on */
    addr_size=sizeof(recvr_addr);
    sock_recv=accept(listeningsock, (struct sockaddr *) &recvr_addr, &addr_size);

    if(sock_recv > 0){                                                                                                                                      
                printf("Connection established\n");  
                printf("please wait,server loading......\n"); 
                sleep(2);
                printf("Which group which would you like to join?\n");
                printf("Enter '1' for work or '2' for fun group\n");
                scanf("%d",&grpchoice);
                assign_group(grpchoice);
                    }
    
    else printf("Connection blocked\n");     

     FD_ZERO(&readfds);		// zero out socket set 
       FD_SET(sock_recv,&readfds);	// add socket to listen to 
        // listen ... 
    while (1){
        read_fd_set = active_fd_set;
        select_ret=select(sock_recv+1,&readfds,NULL,NULL,NULL);
        //select_ret=select(sock_recv+1,&readfds,NULL,NULL,&timeout);//
        if (select_ret > 0){ // anything arrive on any socket? 
            incoming_len=sizeof(recvr_addr);	 //who sent to us? 
            recv_msg_size=recvfrom(sock_recv,buffer,bufsize,0,(struct sockaddr *)&recvr_addr,&incoming_len);
            if (bufsize> 0){	  // what was sent? 
                buffer[bufsize]='\0';
                printf("From %s received: %s\n",inet_ntoa(recvr_addr.sin_addr),bufsize);
              }
            }
            
            }



        close(listeningsock);//// closes connection to listen socket
        close(sock_recv);
        sleep(1);



 }

    void assign_group(int c){

     if (c==1){

         printf("You are assigned to work group\n");
         workchat();
                }


      else if (c==2){

         printf("You are assigned to fun group\n"); 
        //funchat(); 
          }
        
         }


    void workchat(){
    printf("You are in work group chat,send a message\n");
    
        

    }

    //create a file to track the chats in each group

    




     
     void funchat(){




     }






 