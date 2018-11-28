#include <iostream>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main(int argc, char** argv)
{
	int fd = open(argv[1], O_RDONLY);
	struct stat sb;

	if(fstat(fd, &sb) == -1)
		perror("couldn't get file size");

	char *file_in_memory = (char*)mmap(NULL, sb.st_size, PROT_READ,MAP_SHARED,fd,0);
	cout << file_in_memory << endl;
	close(fd);
	return 0;
}
