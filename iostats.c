#include <stdio.h>
#include <stdlib.h>

#define DISK_NAME "mmcblk0"

int main(){
	FILE* diskstats_file;
	char line[256];
	char disk_name[32];
	unsigned long sectors_read =0, sectors_written = 0, sectors_discard = 0;

	diskstats_file = fopen("/proc/diskstats", "r");
	if (diskstats_file == NULL){
		perror("Failed to open /proc/diskstats");
		exit(-1);
	}

	while(fgets(line, sizeof(line), diskstats_file)) {
			
		unsigned long temp_sectors_read, temp_sectors_written, temp_sectors_discard;
		
		//형식에 맞게 문자열을 파싱.		
		sscanf(line, "%*d %*d %s %*d %*d %lu %*d %*d %*d %lu %*d %*d %*d %*d %lu",
			disk_name, &temp_sectors_read, &temp_sectors_written, &temp_sectors_discard);

		if (strcmp(disk_name, DISK_NAME) == 0){
			sectors_read = temp_sectors_read;
			sectors_written = temp_sectors_written;
			sectors_discard = temp_sectors_discard;
			break;
		}
	}

	fclose(diskstats_file);

	printf("Sectors read (KB): %lu\n", sectors_read/2);
	printf("Sectors written (KB): %lu\n", sectors_written/2);
	printf("Sectors discard (KB): %lu\n", sectors_discard/2);

	return 0;
}
			
		


	
