#include <stdlib.h>
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <stdlib.h>
using namespace std;

void printCounts(map<char, int>);
map<char, int> populateMap();

int main(int argc, char** argv)
{

	map<char, int> m = populateMap();
	printCounts(m);

   	ifstream inFile;
	ofstream outFile;

	string fileText ="";
     	// Read file name from command line
  	inFile.open(argv[1]);
	// File not found
     	if (!inFile){
        	cerr << "Unable to open file";
        	exit(1);
      	}
    	char buffer[256];
      	vector<string> array;
	while (!inFile.eof())
      	{
		inFile.getline(buffer, 256);
        	fileText = buffer;
         	array.push_back(fileText);
      	}
	// Whole text is now in array[0]

      	inFile.close();
}

void printCounts(map<char, int> m)
{
        cout << "Printing Counts..." << endl;
        map<char,int>::iterator it = m.begin();
        for(it = m.begin(); it!=m.end();++it)
                cout << it->first << " => " << it->second << '\n';
}

map<char, int> populateMap()
{
        map<char, int> m;
        for(int i = 97; i < 123; i++)
                m.insert(pair<char, int>(static_cast<char>(i),0));
        return m;
}

