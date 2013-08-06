#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, const char *argv[]) 
{
	const char *src, *dest;
	char buf[10];
	int fd_src, fd_dest, n;

	/* check input */
	if (argc < 3) {
		puts("Please input ./a.out <src file> <dest file>");
		exit(1);
	}
	src = argv[1];
	dest = argv[2];

	/* open file src */
	fd_src = open(src, O_RDONLY);
	if (fd_src < 0) {
		printf("Open %s failed!\n", src);
		exit(1);	
	}
	/* open file dest */
	fd_dest = open(dest, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd_dest < 0) {
		printf("Open %s failed!\n", dest);
		close(fd_src);
		exit(1);	
	}
	/* copy */
	while ((n = read(fd_src, buf, 10)) > 0) {
		write(fd_dest, buf, n);
	}
	/* close */
	close(fd_src);
	close(fd_dest);
	
	return 0;
}
