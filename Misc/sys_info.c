#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){
	if(argc < 2)
		fprintf(stderr, "Too few aruments\n");
	else if(argc > 2)
		fprintf(stderr, "Too many arguments\n");
	else{
		int pid;
		int fd[2];
		char buffer[100];
		pipe(fd);
		
		pid = fork();

		if(pid == -1){
			fprintf(stderr, "Failed to create a child process\n");
		}
		else if(0 == pid){
			printf("Child PID: %d\n", pid);
			char path[100]; 
			strcpy(path, "/bin/");
			char echo[] = "echo";
			char hello[] = "Hello World!";
			close(fd[1]);
			int readBytes = read(fd[0], buffer, sizeof(buffer));		
			strcat(path, buffer);
			if((strcmp(echo, buffer)) == 0){
				execl(path, buffer, hello, NULL);
			}
			else{
				
				execl(path, buffer, NULL);
			
			}
			exit(0);
		}
		else{
			printf("Parent PID: %d\n", pid);
			close(fd[0]);
			write(fd[1], argv[1], (strlen(argv[1])+1));
			waitpid(pid, NULL, 0);
		}
	}
	return 0;
}
