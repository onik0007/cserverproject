#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 4445
# define NUM_RANGE 9
# define SIZE 26

char * grid[NUM_RANGE][NUM_RANGE];

void getNewGrid(){
    //creates a brand new blank board. Returns a pointer to the array 
    int j,k;
    //char * grid[NUM_RANGE][NUM_RANGE];
    for (j = 0; j < NUM_RANGE; j++){
        for (k = 0; k < NUM_RANGE; k++)
        {
            grid[k][j]="   ";
        }//Endfor
    }//Endfor
    return;
}//EndFunction getNewBoard
void drawGrid(){
    int j,k;
    //This function prints out the board that was passed. Returns void
    char * const NLINE = "    A    B    C    D    E    F    G    H    I";
    char * const HLINE = "  +----+----+----+----+----+----+----+----+----+";
    char * const VLINE = "  |    |    |    |    |    |    |    |    |    |";

    printf("%s\n",NLINE);
    printf("%s\n",HLINE);
    for (j = 0; j < NUM_RANGE; j++)
    {  
        printf("%s\n",VLINE);
        printf("%d ",j+1);
        for (k = 0; k < NUM_RANGE; k++)
        {  if(strcmp(grid[k][j],"   ")==0){
                printf("| %s",grid[k][j]);
            }else{
                printf("| %s  ",grid[k][j]);
            }
        }
        printf("%s","|");
        printf("\n");
        printf("%s\n",VLINE);
        printf("%s\n",HLINE);
    }
    return;
}//EndFunction drawBoard
void makePlay(int x, int y, char* c){
    //Arrays are zero indexed but our grid starts at index 1
    grid[x-1][y-1]=c;
    
    return;
}//EndFunction makePlay
void startBoard(int *num, char*l){
    //struct startPlays p1;
    for (int i = 0;i<11;i++)
    {
        printf("%d %d %c \n",*(num +i),*(num +i+11),*(l+i));
        //makePlay(*(num +i),*(num +i+10),strcat(*(l+i),"");
    }
//create fun to generate ran num 1-9, add to array(compare to previous to prevent duplicates)
}//EndFunction startBoard



int Average(int num1, int num2)
{
	return 0;
}
int Sum(int num1, int num2)
{
	return 0;
}
int Range(int num1, int num2)
{
	return 0;
}

void saveWorksheet()
{

}

int main(){

	int listeningsock,x;
	struct sockaddr_in host_addr;

	int newSocket;
	struct sockaddr_in newAddr;

	socklen_t addr_size;
	char buffer[1024]; //toSend data
	char client_message[1024]; //toRec data

	listeningsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //creating socket on server side ..socket(domain,type of input,IP)
	printf("Server Socket Created Sucessfully.\n");
	    //creating an address to bind to
	memset(&host_addr, '\0', sizeof(host_addr)); 	/* zero out structure */

	host_addr.sin_family = AF_INET;		//address family 
	host_addr.sin_port = htons(PORT);
	host_addr.sin_addr.s_addr = inet_addr("127.0.0.1");	//host machine IP 	*port #

		/* bind socket to the local address */
	x = bind(listeningsock, (struct sockaddr*)&host_addr, sizeof(host_addr));

	if (x < 0){
		printf("binding failed\n");
        exit(0);
	}

	else printf("binding sucessful\n");

	x = listen(listeningsock, 5);
	if (x < 0){
        printf("listen() failed\n");
        exit(0);
    }

	else printf("Waiting for connection requests....\n");

	newSocket = accept(listeningsock, (struct sockaddr*)&newAddr, &addr_size);

	recv(newSocket, client_message , 1024 , 0); //rec from client.
	puts("Client message :");
    puts(client_message);

	strcpy(buffer, "Got it!");// send grid 
	send(newSocket, buffer, strlen(buffer), 0); // sends to client

	printf("Closing the connection.\n");
	//close(listeningsock);
	// closes connection to listen socket




}
