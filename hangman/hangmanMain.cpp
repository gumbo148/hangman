#include "hangman.h"
const int MAX_GUESSES = 20;
int main(){
	cout << "Hello! Welcome to Jeremy's Hangman game!" << endl;
	hangMan hang;
	hang.getWordsFromFile();
	hang.introduction();
	
	return 0;
}

hangMan::hangMan(){

}

void hangMan::play(){

	int i = 0, b = 0;
	char temp;
	bool guessed = false;
	//clears letterHolder of any letters
	for (int j = 0; j < ABC; j++)
	{
		letterHolder[j] = NULL;
	}
	while (i < MAX_GUESSES)
	{
		temp = letterGuess();
		letterHolder[i] = temp;
		hangManPic();
		i++;
		if (wordCompare == word){
			cout << "You got it! You win!" << endl;
			break;
		}
		if (i == 5)
		{
			wordGuess();

		}

	}

}
void hangMan::introduction(){
	int i = 0;
	char input, keepGoing = 'Y';
	cout << "[S]tart Game [R]ules [Q]uit" << endl;
	cin >> input;
	input = toupper(input);
	switch (input)
	{
	case 'S':
		word = wordPick();
		wordCompare = word;
		while (i < wordCompare.length()){
			wordCompare[i] = '_';
			i++;
		}
		cout << "Here we go..." << endl;
		cout << wordCompare << endl;
		play();
		cout << "The Word was " << word << endl;
		introduction();
		break;
	case 'R':
		cout << "The rules are simple, guess a letter \nand if it's in the word it shows up." << endl;
		cout << "You get 10 guesses before you lose." << endl;
		cout << "After you guess a letter, you will \nnget a chance to guess the word." << endl;
		cout << "if you get the word right, you win!" << endl;
		introduction();
		break;
	case 'Q':
		break;

	default:
		break;
	}


}


void hangMan::getWordsFromFile(){
	int wordSet = 0;
	string line;
	ifstream wordFileReader;
	wordFileReader.open("wordfile.txt");
	while (getline(wordFileReader, line))
	{
		for (int i = 0; i < line.length(); i++){
			line[i] = tolower(line[i]);
		}
		wordList[wordSet] = line;
		wordSet++;
	}


}
string hangMan::wordPick(){
	srand(time(NULL));
	//picks a random word from a list
	int randomWord = rand() % 100;
	return wordList[randomWord];



}

void hangMan::hangManPic(){

	cout << "Letter's guessed: ";
	for (int i = 0; i < letterHolder[i] != '\0'; i++)
	{
		cout << letterHolder[i];
	}
	
	cout << endl;
	cout << wordCompare << endl;
}
char hangMan::letterGuess(){
	int i = 0;
	char letter;
	cout << "Guess a letter: ";
	cin >> letter; cin.ignore(100, '\n');
	for (int j = 0; j < ABC; j++){

		 if(letterHolder[j] == letter)
		{
			cout << "Already guessed: pick another letter" << endl;
			while (letterHolder[j] == letter)
			{
				cin.clear();

				cin >> letter; cin.ignore(100, '\n');
			}
		}
		
	}
	while (i < word.length())
	{
		if (word[i] == letter){
			wordCompare[i] = letter;
		}
		i++;
	
	}
	return letter;
}













bool hangMan::wordGuess(){
	char guess;
	string bestGuess;
	cout << "Guess the word? Y/N" << endl;
	cin >> guess; cin.ignore(100, '\n');
	guess = toupper(guess);
	if (guess == 'Y')
	{
		cout << "what's your guess?: ";
		getline(cin, bestGuess);
		for (int i = 0; i < bestGuess.length(); i++)
		{
			bestGuess[i] = tolower(bestGuess[i]);
		}
		if (bestGuess == word)
		{
			return true;
		}
	}
	else return false;

}
