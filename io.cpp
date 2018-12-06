#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include "timer.cpp"

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
    
    // First timestamp
    timestamp_t t0 = get_timestamp();
    
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
	
    // put timestamp t1 before printing since printing take a long time
    timestamp_t t1 = get_timestamp();

    printCounts(m);
    
    // Printing out execution time
    double secs = (t1 - t0) / 1000000.0L;
    cout << "Execution time for regular file i/o: " << secs << " seconds" 
        << endl;
   
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
        cout << "Printing Occurrences..." << endl;
        map<char,int>::iterator it = m.begin();
        for(it = m.begin(); it!=m.end();++it)
                cout << it->first << " => " << it->second << '\n';
}

map<char, int> populateMap()
{
        map<char, int> m;
	for(int i = 32; i < 127; i++)
                m.insert(pair<char, int>(static_cast<char>(i),0));
        return m;
}

