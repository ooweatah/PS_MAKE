#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DISK_NAME "netstat"
#define STATE_LENGTH 10
	

int main(){
	FILE* netstat; // 
	char line[256];
	char state[STATE_LENGTH];
	unsigned int  local_address = 0, port = 0 ;

	netstat = fopen("/proc/net/tcp", "r");
	if (netstat == NULL){
		perror("Failed to open /proc/net/tcp");
		exit(-1);
	}

	while(fgets(line, sizeof(line), netstat)) {
			
		unsigned int  temp_local_address, temp_port;
		char temp_state[STATE_LENGTH];
		
		//형식에 맞게 문자열을 파싱.		
		sscanf(line, "%*d: %x:%hx %*x:%*hx %s IGNORE",
			 &temp_local_address, &temp_port, &temp_state);

		//if (strcmp(disk_name, DISK_NAME) == 0){
			local_address = temp_local_address;
			port = temp_port;
			strncpy(state, temp_state, STATE_LENGTH);
			state[STATE_LENGTH -1] = '\0'; // 값을 초과하지 않도록 보장
		//	break
		//	;
		//}
		//	
			printf("Local Address: %x   ",local_address );
			printf("Port:%hx   ",port );
			printf("State: %s\n ",state );
	}

	fclose(netstat);

	//printf("Local Address: %x ",local_address );
	//printf("Port:%hx ",port );
	//printf("State: %s ",state );

	return 0;
}
			
		



