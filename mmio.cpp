#include <iostream>
#include <sys/mman.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <map>
#include "timer.cpp"

using namespace std;

void printCounts(map<char, int>);
map<char, int> populateMap();
map<char, int> countOccurrences(map<char, int>, char *);


int main(int argc, char** argv)
{
	int fd = open(argv[1], O_RDONLY);
	struct stat sb;

	if(fstat(fd, &sb) == -1)
		perror("couldn't get file size");
    
    // First timestamp for timing execution time
    timestamp_t t0 = get_timestamp();

	char *file_in_memory = (char*)mmap(NULL, sb.st_size, PROT_READ,MAP_SHARED,fd,0);
	map<char, int> m = populateMap();
	m = countOccurrences(m, file_in_memory);
    
    // Second timestamp before printing since printing can alter time
    timestamp_t t1 = get_timestamp();

  	printCounts(m);

    double secs = (t1 - t0) / 1000000.0L;
    cout << "Execution time for memory mapped file i/o: " 
        << secs << " seconds" << endl;
    close(fd);
    return 0;
}
map<char, int> countOccurrences(map<char, int> m, char *array)
{
	for(int i = 0; array[i] != '\0'; i++)
		m.find(array[i])->second++;
        return m;
}

void printCounts(map<char, int> m)
{
        cout << "Printing Occurrences..." << endl;
        map<char,int>::iterator it = m.begin();
        for(it = m.begin(); it!=m.end();++it)
                cout << it->first << " => " << it->second << '\n';
}

map<char, int> populateMap()
{
        map<char, int> m;
	// Lowercase Letters
        for(int i = 97; i < 123; i++)
                m.insert(pair<char, int>(static_cast<char>(i),0));
	// Capital Letters
	for(int i = 65; i < 91; i++)
		m.insert(pair<char, int>(static_cast<char>(i),0));
        return m;
}

