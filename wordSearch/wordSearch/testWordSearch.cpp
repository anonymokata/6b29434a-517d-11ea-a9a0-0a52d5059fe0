// Used for testing of wordSearch.cpp
//
#include "wordSearch.h"
#include <algorithm>

const string testText =
R"(BONES,KHAN,KIRK,SCOTTY,SPOCK,SULU,UHURA
U,M,K,H,U,L,K,I,N,V,J,O,C,W,E
L,L,S,H,K,Z,Z,W,Z,C,G,J,U,Y,G
H,S,U,P,J,P,R,J,D,H,S,B,X,T,G
B,R,J,S,O,E,Q,E,T,I,K,K,G,L,E
A,Y,O,A,G,C,I,R,D,Q,H,R,T,C,D
S,C,O,T,T,Y,K,Z,R,E,P,P,X,P,F
B,L,Q,S,L,N,E,E,E,V,U,L,F,M,Z
O,K,R,I,K,A,M,M,R,M,F,B,A,P,P
N,U,I,I,Y,H,Q,M,E,M,Q,R,Y,F,S
E,Y,Z,Y,G,K,Q,J,P,C,Q,W,Y,A,K
S,J,F,Z,M,Q,I,B,D,B,E,M,K,W,D
T,G,L,B,H,C,B,E,C,H,T,O,Y,I,K
O,J,Y,E,U,L,N,C,C,L,Y,B,Z,U,H
W,Z,M,I,S,U,K,U,R,B,I,D,U,X,S
K,Y,L,B,Q,Q,P,M,D,F,C,K,E,A,B)";

const string textGrid =
R"(U,M,K,H,U,L,K,I,N,V,J,O,C,W,E
L,L,S,H,K,Z,Z,W,Z,C,G,J,U,Y,G
H,S,U,P,J,P,R,J,D,H,S,B,X,T,G
B,R,J,S,O,E,Q,E,T,I,K,K,G,L,E
A,Y,O,A,G,C,I,R,D,Q,H,R,T,C,D
S,C,O,T,T,Y,K,Z,R,E,P,P,X,P,F
B,L,Q,S,L,N,E,E,E,V,U,L,F,M,Z
O,K,R,I,K,A,M,M,R,M,F,B,A,P,P
N,U,I,I,Y,H,Q,M,E,M,Q,R,Y,F,S
E,Y,Z,Y,G,K,Q,J,P,C,Q,W,Y,A,K
S,J,F,Z,M,Q,I,B,D,B,E,M,K,W,D
T,G,L,B,H,C,B,E,C,H,T,O,Y,I,K
O,J,Y,E,U,L,N,C,C,L,Y,B,Z,U,H
W,Z,M,I,S,U,K,U,R,B,I,D,U,X,S
K,Y,L,B,Q,Q,P,M,D,F,C,K,E,A,B)";

const string testVectorText =
R"(U,M,K
H,U,L
K,I,N)";

const string findWord = "KIN";

//Expected corrdinates left to right
const vector<vector<char> >expVectorCharLR = {
{'U','H','K'},
{'M','U','I'},
{'K','L','N'} };
const vector<vector<int>>expCorrLR = { {0, 2},{1, 2}, {2, 2} };

//Expected corrdinates right to left
const vector<vector<char> >expVectorCharRL = {
{'U','H','N'},
{'M','U','I'},
{'K','L','K'} };
const vector<vector<int>>expCorrRL = { {2, 2},{1, 2}, {0, 2} };

//Expected corrdinates up to down
const vector<vector<char> >expVectorCharUD = {
{'K','I','N'},
{'M','U','U'},
{'K','L','K'} };
const vector<vector<int>>expCorrUD = { {0, 0},{0, 1}, {0, 2} };

//Expected corrdinates down to up
const vector<vector<char> >expVectorCharDU = {
{'N','I','K'},
{'M','U','U'},
{'K','L','K'} };
const vector<vector<int>>expCorrDU = { {0, 2},{0, 1}, {0, 0} };

//Expected corrdinates top left to bottom right
const vector<vector<char> >expVectorCharLRD = {
{'K','I','K'},
{'M','I','U'},
{'K','L','N'} };
const vector<vector<int>>expCorrLRD = { {0, 0},{1, 1}, {2, 2} };

//Expected corrdinates from bottom right to top left
const vector<vector<char> >expVectorCharRLU = {
{'N','A','A'},
{'A','I','A'},
{'A','A','K'} };
const vector<vector<int>>expCorrRLU = { {2, 2},{1, 1}, {0, 0} };

//Expected corrdinates bottom left to top right
const vector<vector<char> >expVectorCharLRU = {
{'A','A','K'},
{'A','I','A'},
{'N','A','A'} };
const vector<vector<int>>expCorrLRU = { {0, 2},{1, 1}, {2, 0} };

//Expected corrdinates from top right to bottom left
const vector<vector<char> >expVectorCharRLD = {
{'A','A','N'},
{'A','I','A'},
{'K','A','A'} };
const vector<vector<int>>expCorrRLD = { {2, 0},{1, 1}, {0, 2} };

const string testFile = "test.txt";
const string testFirstLine = "BONES,KHAN,KIRK,SCOTTY,SPOCK,SULU,UHURA";
const vector<string> testVectorWords = { "BONES", "KHAN", "KIRK", "SCOTTY", "SPOCK", "SULU", "UHURA" };

map <string, vector<vector<int > >> expMap = {
	{"BONES", {{0,6},{0,7},{0,8},{0,9},{0,10}}},
	{"KHAN", {{5,9},{5,8},{5,7},{5,6}}},
	{"KIRK", {{4,7},{3,7},{2,7},{1,7}}},
	{"SCOTTY", {{0,5},{1,5},{2,5},{3,5},{4,5},{5,5}}},
	{"SPOCK", {{2,1},{3,2},{4,3},{5,4},{6,5}}},
	{"SULU", {{3,3},{2,2},{1,1},{0,0}}},
	{"UHURA", {{4,0},{3,1},{2,2},{1,3},{0,4}}}
};

//Functions for testing
void testReadFile();
void testGetFirstLine();
void testProcessWords();
void testCharGridVector();
void testFindWordCorrLR();
void testFindWordCorrRL();
void testFindWordCorrUD();
void testFindWordCorrDU();
void testFindWordCorrLRD();
void testFindWordCorrLRU();
void testFindWordCorrRLU();
void testFindWordCorrRLD();
void testFullNoRead();
void testFull();

//Utility Functions
void stringCompareTest(string expected, string actual, string testName);
void intCompare(int exp, int auct, string testName);
int minCompare(int exp, int act, string testName);

//Runs the tests for wordSearch.cpp
int main()
{
	cout << "Tests for wordSearch.cpp\n";
	testReadFile();
	testGetFirstLine();
	testProcessWords();
	testCharGridVector();

	//Find Direction word tests
	testFindWordCorrLR();
	testFindWordCorrRL();
	testFindWordCorrUD();
	testFindWordCorrDU();
	testFindWordCorrLRD();
	testFindWordCorrLRU();
	testFindWordCorrRLU();
	testFindWordCorrRLD();

	//Test on test string (no reading file)
	testFullNoRead();

	//Full test
	testFull();

}

//Tests function readFile from wordSearch.cpp
//Parameters: None
//Return: None
void testReadFile()
{
	stringCompareTest(testText, readFile(testFile), "Read File Test");
}

//An assert for compare strings
//Parameters: expected string, actual string, and the name of the test.
//Return: None
void stringCompareTest(string expected, string actual, string testName)
{
	cout << "\n" << testName << "\n";
	if ((actual.compare(expected)) == 0)
	{
		cout << "Success: String matches\n";
	}
	else
	{
		cout << "Failure: String doesn't match\n";
		cout << "String Expected:\n" << expected;
		cout << "\nString results:\n" << actual;
	}
}


//Test for parse the a string to return first line of a string and get the words.
//Parameters: None
//Return: None
void testGetFirstLine()
{
	stringCompareTest(testFirstLine, getFirstLine(testText), "Get First Line from String");
}

//Test for parse a string to return the words to find in a vector.
//Parameters: None
//Return: None
void testProcessWords()
{
	cout << "\nGet words from text and in a vector\n";
	vector<string> vectorWords = getWords(testText);
	
	//Get size of the vectors.
	int minSize = minCompare((int)testVectorWords.size(), (int)vectorWords.size(), "Word Vector Size");

	//Go through the strings in the vector and compare them
	for (int i = 0; i < minSize; i++)
	{
		string testName = "Vector String Test at index " + to_string(i);
		stringCompareTest(vectorWords.at(i), testVectorWords.at(i), testName);
	}
}

//Returns the min between 2 intgers and does compare between them
//Parameters: intergers for expected (exp) and acttual (act) along with string for test name
//Returns: Minimum between the 2 integers
int minCompare(int exp, int act, string testName)
{
	intCompare(exp, act, testName);
	return min(exp, act);
}

//Compares integers and prints out success or failure
//Parameters: 2 integers along with name of test as string
//Return: None
void intCompare(int exp, int act, string testName)
{
	cout << "\n" << testName << "\n";
	if (exp != act)
	{
		cout << "Failure: Values does not match\n";
		cout << "Expected Value: " << exp << "\n";
		cout << "Actual Value: " << act << "\n";
	}
	else
	{
		cout << "Success: Integers matches\n";
	}
}

//Prints the characters from a 2-d vector
//Parameters: 2-d vector of chracters
//Return: None
void printCharVector(vector<vector<char>>input)
{
	cout << "{ ";
	for (int i = 0; i < input.size(); i++)
	{
		cout << "{ ";
		cout << input[0][i];
		for (int j = 1; j < input[i].size(); j++)
		{
			cout << ", " << input[i][j];
		}
		cout << "},\n";
	}
	cout << "}";
}

//Test for change the grid of characters into a 2-D vector
void testCharGridVector()
{
	cout << "\nTest: Convert character grid to vector\n";
	vector<vector<char> > actVector = getVectorCharGrid(testVectorText);
	if (actVector == expVectorCharLR)
	{
		cout << "Success: Character grid vectors match\n";
	}
	else
	{
		cout << "Failure: Character grid don't vectors match\n";
		cout << "Expected vector\n";
		printCharVector(expVectorCharLR);
		cout << "Expected vector\n";
		printCharVector(actVector);
	}
}

//Prints the integers from a 2-d vector
//Parameters: 2-d vector of integers
//Return: None
void printIntVector(vector<vector<int>>input)
{
	cout << "{ ";
	for (int i = 0; i < input.size(); i++)
	{
		cout << "{ ";
		cout << input[i][0];
		for (int j = 1; j < input[i].size(); j++)
		{
			cout << ", " << to_string(input[i][j]);
		}
		cout << "},\n";
	}
	cout << "}";
}

//Test for find the coordinates of a word in a 2-d character vector in left to right order
void testFindWordCorrLR()
{
	cout << "\nTest: Find word in vector in left to right\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharLR);
	if (expCorrLR == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrLR);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test for find the coordinates of a word in a 2-d character vector in right to left order
void testFindWordCorrRL()
{
	cout << "\nTest: Find word in vector in right to left\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharRL);
	if (expCorrRL == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrRL);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test for find the coordinates of a word in a 2-d character vector in up to down order
void testFindWordCorrUD()
{
	cout << "\nTest: Find word in vector in up to down direction\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharUD);
	if (expCorrUD == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrUD);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test for find the coordinates of a word in a 2-d character vector in down to up order
void testFindWordCorrDU()
{
	cout << "\nTest: Find word in vector in down to up direction\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharDU);
	if (expCorrDU == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrDU);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test diagonally descendingfor find the coordinates of a word in a 2-d character vector in top left to bottom right
void testFindWordCorrLRD()
{
	cout << "\nTest: Find word in vector in top left to bottom right direction\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharLRD);
	if (expCorrLRD == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrLRD);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test diagonally descendingfor find the coordinates of a word in a 2-d character vector in bottom left to top right
void testFindWordCorrLRU()
{
	cout << "\nTest: Find word in vector in bottom left to top right direction\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharLRU);
	if (expCorrLRU == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrLRU);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test diagonally descendingfor find the coordinates of a word in a 2-d character vector in bottom right to top left
void testFindWordCorrRLU()
{
	cout << "\nTest: Find word in vector in bottom right to top left direction\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharRLU);
	if (expCorrRLU == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrRLU);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test diagonally descending for find t of a word in a 2-d character vector in top right to bottom left
void testFindWordCorrRLD()
{
	cout << "\nTest: Find word in vector in top right to bottom left direction\n";
	vector<vector<int> > actCorr = findCorr(findWord, expVectorCharRLD);
	if (expCorrRLD == actCorr)
	{
		cout << "Success: Coordinates do match\n";
	}
	else
	{
		cout << "Failure: Coordinates do not match\n";
		cout << "Expected coordinates:\n";
		printIntVector(expCorrRLD);
		cout << "Actual Vector:\n";
		printIntVector(actCorr);
	}
}

//Test find words character grid without reading a file.
void testFullNoRead()
{
	cout << "\nTest: Find words in string character  \n";
	const vector<vector<char> >gridTextVector = getVectorCharGrid(textGrid);
	map <string, vector<vector<int > >> actMap = findAllWords(testVectorWords, gridTextVector);
	if (actMap == expMap)
	{
		cout << "Success: Results maps do match\n";
	}
	else
	{
		cout << "Failure: Results maps do not match\n";
		cout << "Expected map:\n";
		printMap(expMap);
		cout << "Actual map:\n";
		printMap(actMap);
	}
}

//Full test run where function is called to open file, read it, and find the words and their coordinates
void testFull()
{
	cout << "\nTest: Read file complete a word search\n";
	map <string, vector<vector<int > >> actMap = wordSearch(testFile);
	cout << "Actual map:\n";
	printMap(actMap);
	if (actMap == expMap)
	{
		cout << "Success: Result maps do match\n";
	}
	else
	{
		cout << "Failure: Result maps do not match\n";
		cout << "Expected map:\n";
		printMap(expMap);
	}
}
