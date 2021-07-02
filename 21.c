#include <signal.h>
#include <stdio.h>
static int a = 0;
static int flag = 1;
static int fd;

void beep(int sig){
	a++;
	write(fd, '\a', 1);
}
void leave(int sig){
	flag = 0;
}

int main(){
	fd = open("/dev/tty", O_RDWR);
	if(signal(SIGINT, beep) == SIG_ERR){
		perror("error signal");
		return 0;
	}
	if(signal(SIGQUIT, leave) == SIG_ERR){
		perror("error leave signal");
		return 0;
	}
	do{

	} while(flag);
	printf("%d", a);
}