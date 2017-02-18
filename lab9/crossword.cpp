// Juan Pablo Borrero & Jorge Nazario
// CSE 20311
// Lab 9
//
// Main driver

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "board.h"
#include <unistd.h>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

void insertword (vector<string> &, string); // Funtion (1): To insert words into the vector mywords (list f words). Sorts the words according to length
void readvector (vector<string> &); // Funtion (2): To display the list of words inserted
bool checkcharacters(string); // Funtion (3): To check if the words entered are alphabetical
void fileinserted(vector<string> &, string &, bool &, int &, ifstream &); // Function (4): To read the file that is provided
void generatecrossword(vector<string> &, vector<string> &, Board &, Board &); // Function (5): To generate crossword
void displaycrossword(vector<string>, vector<string>, Board, Board &); // Function (6): To display crossword
void displayclues (vector<string>, vector<string>); // Function (7): To display clues, called from displaycrossword() function
void savefile (string, vector<string>, vector<string>, Board, Board); // Function (8): To save the crossword in a file with the name provided by user

int main (int argc, char *argv[]){
	Board a1, b1;	
	vector<string> mywords; // Vector that contains the words inserted
	vector<string> myclues; // Vector that contains the clues
	string strObject;
	bool checkchars = false;
	int wr = 1; //Counts the words inserted
	ifstream ifs;
	
	// Interactive mode
	// ******************
	if (argc==1){
		cout << "CROSSWORD PUZZLE GENERATOR" << endl;
		cout << "--------------------------" << endl;
		cout << "Enter the list of words followed by '.' (15 characters max per word/20 words max):" << endl;
        
		cin >> strObject;
		transform(strObject.begin(), strObject.end(), strObject.begin(), ::toupper); // Change all characters to uppercase letters
		checkchars = checkcharacters(strObject); // Function(3)
		if (strObject.size()<=15 && checkchars == true && strObject != " ")  // If word is less than 15 characters and is alphabetical
			mywords.push_back(strObject); 
		else
			cout << "Word " << wr << " does not satisfy the criteria. Enter new word:" << endl;
		
		while(strObject != "."){ // Enter words to vector (mywords)
			cin >> strObject;
			wr++; // How many words inserted
			transform(strObject.begin(), strObject.end(), strObject.begin(), ::toupper);
			checkchars = checkcharacters(strObject); // Function (3)
	
			if (strObject != "."){	
				if(strObject.size()<=15 && checkchars == true && strObject != " ")		
					insertword(mywords, strObject);	// Function (1)
				else{
					cout << "Word " << wr << " inserted does not satisfy criteria. Enter next word:" << endl;
					wr = wr - 1;
				}
			}

			if (wr == 20) { // To check how many words the vector contains
				cout << "The list of words has already reached the maximum of 20 words. No further words can be added. " << endl;
				strObject = ".";
			}
		}	

		readvector(mywords); // Function (2)
		generatecrossword(mywords, myclues, a1, b1); // Function (5)
		displaycrossword(mywords, myclues, a1, b1); // Function (6)
	}

	// Batch mode. When a file with a list of words is provided
	// **************
	else if (argc == 2) {
		ifs.open(argv[1]);
		if (!ifs){
			cout << "Error opening file"<<endl;
			return 2;
		}
		fileinserted(mywords, strObject, checkchars, wr, ifs); // Function (4)
		generatecrossword(mywords, myclues, a1, b1); // Function (5)
		displaycrossword(mywords, myclues, a1, b1); // Function (6)
	}			
	
	// If three arguments are provided, so program saves the puzzle
	// **************
	else if (argc == 3){
		string filename = argv[2];
		ifs.open(argv[1]);
		if (!ifs){
			cout << "Error opening file" << endl;
			return 2;
		}
		fileinserted(mywords, strObject, checkchars, wr, ifs); // Function (4)
		generatecrossword(mywords, myclues, a1, b1); // Function (5)
		displaycrossword(mywords, myclues, a1, b1); // Function (6)
		savefile (filename, mywords, myclues, a1, b1); // Function (8)
	}

	// If more than three arguments are provided
	// **************
	else if (argc > 3){
		cout << "Too many arguments have been provided!" << endl;
		return 2;
	}
	return 0;
}

//FUNCTIONS
// Function (1)
void insertword (vector<string> &mywords, string strObject){
	double n;
	string s1;
	bool inserted = false;
	
	for (auto it=mywords.begin(); it != mywords.end(); it++){
		s1 = *it;
		if(strObject.size() >= s1.size()){
			mywords.insert(it, strObject);	
			inserted = true;
			break;
		}
	}
	if(inserted == false){
		mywords.push_back(strObject);
	}
}

// Function (2)
bool checkcharacters (string strObject){
	bool correct = true;	
	strObject.c_str();
	int i = 0;	
	 while (strObject[i]) {
    		if (isalpha(strObject[i]) == 0){
			correct = false;
			break;	 
		}
		i++;
  	}
	return correct;
}

// Function (3)
void readvector (vector<string> &mywords){
	cout << "The list of words is: " << endl;
	for(auto it = mywords.begin(); it != mywords.end(); it++){
		int i = distance (mywords.begin(), it) + 1;
		cout << i << ". " << *it << endl;
	}
}

// Function (4)
void fileinserted(vector<string> &mywords, string &strObject, bool &checkchars, int &wr, ifstream &ifs){
	cout << "CROSSWORD PUZZLE GENERATOR" << endl;
	cout << "--------------------------" << endl;
	
	ifs >> strObject;
	transform(strObject.begin(), strObject.end(), strObject.begin(), ::toupper);
	checkchars = checkcharacters(strObject);
	
	if (strObject.size()<=15 && checkchars == true && strObject != " ") 
		mywords.push_back(strObject); 
	else
		cout << "Word " << wr << " does not satisfy criteria. Enter new word:" << endl;
	
	while (!ifs.eof() || strObject != ".") {
		ifs >> strObject;
		wr++; 
		transform(strObject.begin(), strObject.end(), strObject.begin(), ::toupper);
		checkchars = checkcharacters(strObject);
		if (strObject != "."){
			if(strObject.size()<=15 && checkchars == true && strObject != " ")
				insertword(mywords, strObject);
			else {
				cout << "Word " << wr << " inserted does not satisfy criteria. Enter next word:" << endl;
				wr = wr - 1;	
			}
	
			if (wr == 20) { // To check how many words the vector contains
				cout << "The list of words has already reached the maximum of 20 words. No further words can be added. " << endl;
				strObject = ".";
			}
		}
	}	

	readvector(mywords); //function that displays the list of words
}

// Function (5)
void generatecrossword (vector<string> &mywords, vector<string> &myclues, Board &a1, Board &b1){
	string str_r, str_c, dir, strclue;
	int r, c;
	bool insertedBoard = false;	
	
	auto it = mywords.begin();
	a1.insertFirstWord(*it, r, c, dir);
	str_r = to_string(r + 1);
	str_c = to_string(c + 1);
	strclue="(";
	strclue.append(str_r);
	strclue.append(",");
	strclue.append(str_c);
	strclue.append(") ");
	strclue.append(dir);
	myclues.push_back(strclue);
		
	for(auto it = mywords.begin() + 1; it != mywords.end(); it++){// Iterate through the vector (mywords) and insert words into board
		r = 0;
		c = 0;
		insertedBoard = a1.insertBoard(*it, r, c, dir); // return boolean. Modify a1
		if (insertedBoard == true){ //if word can be inserted keep track of the coordinate of the first letter and the direction of the word
			str_r = to_string(r + 1);
			str_c = to_string(c + 1);
			strclue="(";
			strclue.append(str_r);
			strclue.append(",");
			strclue.append(str_c);
			strclue.append(") ");
			strclue.append(dir);			
			myclues.push_back(strclue);
		}
		else if(insertedBoard == false){ // If word cannot be inserted
			int i = distance(mywords.begin(), it) + 1;
			cout << "The word number " << i << " of the list could not be added. No further words have been added." << endl;
			break;
		}
	}
}

// Function (6)
void displaycrossword(vector<string> mywords, vector<string> myclues, Board a1, Board &b1){	
	cout << endl;	
	cout << "SOLUTION: " << endl;
	cout << a1 << endl;
	b1.encodeBoard(a1);
	cout << "CROSSWORD PUZZLE: " << endl;
	cout << b1 << endl;
	cout << "CLUES: " << endl;
	displayclues(myclues, mywords);	
}

// Function (7)
void displayclues (vector<string> myclues, vector<string> mywords){ 
	auto it2 = mywords.begin();
	string content;
	srand(unsigned(time(NULL)));	
	
	for (auto it=myclues.begin(); it!=myclues.end(); it++, it2++){
		content = *it2;
		content.c_str();
		random_shuffle(content.begin(), content.end());
		cout << *it << "\t" << content <<endl;
	}	
}

// Function (8)
void savefile (string filename, vector<string> mywords, vector<string> myclues, Board a1, Board b1){
	ofstream ofs;
	string content;

	if (filename != ""){
		ofs.open(filename);
		ofs << "The list of words is: " << endl;
		for (auto it2 = mywords.begin(); it2 != mywords.end(); it2++){
			ofs << *it2 << endl;
		}
		ofs << endl;
		ofs << "SOLUTION: " << endl; 
		ofs << a1 << endl;
		ofs << "CROSSWORD PUZZLE: " << endl;
		ofs << b1 << endl;
		ofs << "CLUES: " << endl;
		auto it2 = mywords.begin();
		for ( auto it = myclues.begin(); it != myclues.end(); it++, it2++){
			content = *it2;
			content.c_str();
			random_shuffle(content.begin(), content.end());
			ofs << *it << "\t" << content << endl;			
		}
		cout << "The crossword has been saved as: " << filename << endl;	
	}
}
