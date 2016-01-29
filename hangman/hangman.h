#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
using namespace std;
const int MAX_LIST = 100;
const int ABC = 27;
class hangMan{
public:
	void getWordsFromFile();
	void hangManPic();
	void play();
	char letterGuess();
	void alreadyGuessed();
	bool wordGuess();
	void introduction();
	string wordPick();
	hangMan();
	string word;
	string wordCompare;
	string wordList[MAX_LIST];
	char letterHolder[ABC];
	char letterPicked;
	
	
private:

};