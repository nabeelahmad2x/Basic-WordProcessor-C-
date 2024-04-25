#include"counter.h"
#include<fstream>
#include<iostream>

using namespace std;

Counter::Counter(char* fileName = "")
{	
	this->fileName = deepcopy(fileName);
}
Counter::~Counter()
{
	delete[] fileName;
	fileName = NULL;
	cout << "Counter deleted.." << endl;
}

void Counter::update_counts()
{
	characterCount = get_charactersCount();
	wordsCount = get_wordsCount();
	sentencesCount = get_sentencesCount();
	punctuationsCount = get_punctuationsCount();
	cout << "Counter updated." << endl;
}

char* Counter::get_fileName()
{
	return deepcopy(fileName);
}
void Counter::set_fileName(char* fileName)
{
	this->fileName = deepcopy(fileName);
}


int Counter::get_charactersCount()
{
	int count = 0;
	char temp;
	ifstream fin(fileName);
	while (!fin.eof())
	{
		fin >> temp;
		if (temp >= 65 && temp <= 90)//checking ascii of small and capital english letters
		{
			count++;
		}
		else if (temp >= 97 && temp <= 122)
		{
			count++;
		}
	}
	fin.close();
	return count;
}

int Counter::get_wordsCount()
{
	int count = 0;
	char temp;
	ifstream fin(fileName);
	while (!fin.eof())
	{
		fin.get(temp);
		if (temp == ' ' || temp == ',' || temp == '.') 
		{
			count++;
		}
	}
	fin.close();
	count--;
	return count;
}
int Counter::get_sentencesCount()
{
	int count = 0;
	char temp;
	ifstream fin(fileName);
	while (!fin.eof())
	{
		fin >> temp;
		if (temp == '.') 
		{
			count++;
		}
	}
	fin.close();
	count--;
	return count;
}
int Counter::get_punctuationsCount()
{
	int count = 0;
	char temp;
	ifstream fin(fileName);
	while (!fin.eof())
	{
		fin >> temp;
		if (temp >= 33 && temp <= 47) //checking ascii of punctuations
		{
			count++;
		}
		else if (temp >= 58 && temp <= 64)
		{
			count++;
		}
		else if (temp >= 123 && temp <= 126)
		{
			count++;
		}
	}
	fin.close();
	count--;
	return count;
}

char* Counter::deepcopy(char* arr)
{
	int size = strlen(arr);
	char* newArr = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = '\0';
	return newArr;
}