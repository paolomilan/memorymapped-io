#include <iostream>
#include <map>
#include <fstream>
#include <vector>

using namespace std;

void printCounts(map<char, int>);
map<char, int> populateMap();
map<char, int> countOccurrences(map<char, int>, vector<string>, int);

int main(int argc, char** argv)
{
	map<char, int> m = populateMap();
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
	int numLines(-1);
	while (!inFile.eof())
      	{
		numLines++;
		inFile.getline(buffer, 256);
        	fileText = buffer;
         	array.push_back(fileText);
      	}
	// Whole text is now in array[0]
	m = countOccurrences(m, array, numLines);
	printCounts(m);
      	inFile.close();
}

map<char, int> countOccurrences(map<char, int> m, vector<string> array, int numLines)
{
	for(int i = 0; i < numLines;i++)
		for(int j = 0; j < array[i].size();j++)
			m.find(array[i][j])->second++;
	return m;
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

