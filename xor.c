#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

	if(argc < 3){
		printf("Too few arguments\narguments: \"message\" \"key_symbol\"\n");
		exit(1);
	}
	if(strlen(argv[2]) != 1){
		printf("Key len != 1\n");
		exit(2);
	}

	FILE* fd=fopen("boot", "rb+");
	if(fd == NULL){
		printf("Cannot open file\n");
		exit(3);
	}
	
	int i = 0, f_bytes = 0, flag = 0, sym; 
	while(1){
	
		sym = fgetc(fd);

		if (sym == EOF){
			if (feof (fd) != 0){  
				printf("\nend of file\n");
				break; 
			} else {
				printf("\nfile reading error\n");
				break;
			}
		}
		
		(sym == 255) ? (flag++) : (flag = 0); 
		
		f_bytes++;
		if(flag == 2){
			//printf("ff_bytes position: %d\n", f_bytes);
			break;
		}
	}	

	if (fseek(fd, f_bytes - 2, SEEK_SET) != 0){
		perror("fseek error");
		return __LINE__;
	}

	while(argv[1][i]){
		char sym = argv[1][i] ^ argv[2][0];
		fputc(sym, fd);
		i++;
	} 
	fputc('\n' ^ argv[2][0] , fd);

	fclose(fd);

	return 0;
}
