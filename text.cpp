#include"text.h"
#include<iostream>
using namespace std;

Text::Text(char* fileName = "") :Counter(fileName)
{	
	clearText = true;
	update_counts();
	cout << "Text Constructor.." << endl;
}

Text::~Text()
{	
	delete[] textData;
	textData = NULL;
	cout << "Text Deleted.." << endl;
}

void Text::set_textData(char* input)
{
	textData = deepcopy(input);
}

char* Text::get_textData()
{
	return deepcopy(textData);
}

void Text::encrypt()
{
	if (clearText == false)
	{
		cout << "TEXT IS ALREADY ENCRYPTED.." << endl;
	}
	else
	{
		int code = 3, temp;
		int size = strlen(textData);
		for (int i = 0; i < size; i++)
		{
			if (textData[i] >= 97 && textData[i] <= 122)//for small letters
			{
				temp = textData[i] + code;
				if (temp <= 122)
				{
					textData[i] = textData[i] + code;
				}
				else
				{
					textData[i] - 26;
					textData[i] = textData[i] + code;
				}
			}
			else if (textData[i] >= 65 && textData[i] <= 90)//for capital letters
			{
				temp = textData[i] + code;
				if (temp <= 90)
				{
					textData[i] = textData[i] + code;
				}
				else
				{
					textData[i] - 26;
					textData[i] = textData[i] + code;
				}
			}//nested if condition
		}//forloop
		clearText = false;
		cout << "TEXT ENCRYPTED SUCCESSFULLY." << endl;
	}//outer if condition
	
}
void Text::decrypt()
{
	if (clearText == true)
	{
		cout << "TEXT IS ALREADY DECRYPTED.." << endl;
	}
	else
	{
		int code = 3, temp;
		int size = strlen(textData);
		for (int i = 0; i < size; i++)
		{
			if (textData[i] >= 97 && textData[i] <= 122)//for small letters
			{
				temp = textData[i] - code;
				if (temp >= 97)
				{
					textData[i] = textData[i] - code;
				}
				else
				{
					textData[i] + 26;
					textData[i] = textData[i] - code;
				}
			}
			else if (textData[i] >= 65 && textData[i] <= 90)//for capital letters
			{
				temp = textData[i] - code;
				if (temp >= 90)
				{
					textData[i] = textData[i] + code;
				}
				else
				{
					textData[i] + 26;
					textData[i] = textData[i] - code;
				}
			}//nested if condition
		}//forloop
		clearText = true;
		cout << "TEXT DECRYPTED SUCCESSFULLY." << endl;
	}//outer if condition
}

char* Text::deepcopy(char* arr)
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
/////////////////////////////////////////////////////////////////////////////////////////
///////////////OPERATORS ONLY BELOW//////////////////////////////////////////////////////

bool Text::operator==(Text& obj)//check if two para are equal
{
	bool flag = false;
	int size1, size2;
	size1 = strlen(this->textData);
	size2 = strlen(obj.textData);
	if (size1 != size2)
	{
		flag = false;
	}
	else
	{
		for (int i = 0; i < size1; i++)
		{
			if (this->textData[i] == obj.textData[i])
			{
				flag = true;
				continue;
			}
			else
			{
				flag = false;
				break;
			}
		}//end of loop..
	}//end of outer condition..
	return flag;
}

Text Text::operator++()//make all text uppercase
{
	int size = strlen(this->textData);
	for (int i = 0; i < size; i++)
	{
		if (textData[i] >= 97 && textData[i] <= 122)
		{
			textData[i] - 32;
		}
	}
	return *this;
}

Text Text::operator--()//make all text lowercase
{
	int size = strlen(this->textData);
	for (int i = 0; i < size; i++)
	{
		if (textData[i] >= 65 && textData[i] <= 90)
		{
			textData[i] + 32;
		}
		else
			continue;
	}
	return *this;
}

Text Text::operator+(Text& obj)//add two paragraphs into a single one
{
	Text temp = *this;
	int size1 = strlen(textData);//size of 1
	int size2 = strlen(obj.textData);//size of 2
	int size3 = size1 + size2 + 1;//size of resulting obj text

	//copy data of this->text into new array..
	char* arr = new char[size3];
	arr = deepcopy(textData);
	arr[size1]=' ';
	for (int i = size1 + 1, j = 0; i < size3; i++, j++)
	{
		arr[i] = obj.textData[j];
	}
	arr[size3] = '\0';
	textData = arr;
	cout << "Merged Text: " << textData << endl;
	return temp;
}

//////////////////////FILE INPUT OUTPUT///////////////////////////

ostream& operator<<(ostream& out, Text& obj)
{
	out << "File Name: " << obj.get_fileName() << endl;
	out << "File Data: " << obj.get_textData() << endl;
	out << "Total Characters: " << obj.get_charactersCount() << endl;
	out << "Total Words: " << obj.get_wordsCount() << endl;
	out << "Total Sentences: " << obj.get_sentencesCount() << endl;
	out << "Total Punctations: " << obj.get_punctuationsCount();
	return out;
}

ifstream& operator>>(ifstream& in, Text& obj)
{	
	cout << "Taking input from file.." << endl;
	char temp[500]{'\0'};
	int index = 0;
	while (!in.eof())
	{
		in.get(temp[index]);
		index++;
	}
	obj.set_textData(temp);
	return in;
}
ofstream& operator<<(ofstream& out, Text& obj)
{
	cout << "Creating output file.." << endl;
	out << "File Name: " << obj.get_fileName() << endl;
	out << "File Data: " << obj.get_textData() << endl;
	out << "Total Characters: " << obj.get_charactersCount() << endl;
	out << "Total Words: " << obj.get_wordsCount() << endl;
	out << "Total Sentences: " << obj.get_sentencesCount() << endl;
	out << "Total Punctations: " << obj.get_punctuationsCount();
	return out;
}