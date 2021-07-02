#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
struct termios orig_termios;
static int fd;
void disableRawMode(){
	int set_check = 0;
	set_check = tcsetattr(fd, TCSAFLUSH, &orig_termios);
	if(set_check == -1){
		perror("Error setting flags");
            return 0;
	}
}
void enableRawMode() {
	int set_check = 0;
	int get_check = 0;
  	get_check = tcgetattr(fd, &orig_termios);
  	if(get_check == -1){
  		perror("Error getting attributes");
        return 0;
  	}
  	struct termios raw = orig_termios;
  	raw.c_lflag &= ~(ISIG | ICANON);
  	raw.c_cc[VMIN] = 1;
  	set_check = tcsetattr(fd, TCSAFLUSH, &raw);
  	if(set_check == -1){
  		perror("Error setting attributes");
            return 0;
  	}
}

int main(){
	fd = open("/dev/tty", O_RDWR);
	enableRawMode();
	int a = 0;
	printf("2*2=");
	int scan_check = 0;
	scan_check = read
	if(scan_check == NULL)
        {
            perror("Error reading");
            return 0;
        }
	disableRawMode();
}