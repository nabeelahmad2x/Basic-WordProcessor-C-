#pragma once
#include<fstream>
#include<iostream>
#include"counter.h"
using namespace std;
class Text:public Counter
{
private:
	bool clearText;//used for encryption decryption..
	char* textData;		
	
public:
	Text(char*);
	~Text();
	
	void set_textData(char*);
	char* get_textData();
	void encrypt();
	void decrypt();
	char* deepcopy(char*);

	bool operator==(Text&);//check if two para are equal
	Text operator++();//make all text uppercase
	Text operator--();//make all text lowercase
	Text operator+(Text&);//add two paragraphs into a single one
	
};

ostream& operator<<(ostream&, Text&);
ifstream& operator>>(ifstream&, Text&);
ofstream& operator<<(ofstream&, Text&);