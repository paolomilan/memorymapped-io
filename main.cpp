#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
   	ifstream inFile;
	ofstream outFile;
	char word;
	string fileText ="";
     	string toLookFor=argv[1];
     	//Open file
  	inFile.open(argv[1]);
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
      	cout << array[0] << endl;
      	inFile.close();
}
