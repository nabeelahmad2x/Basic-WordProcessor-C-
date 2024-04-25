#include"text.h"
#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	char* inputFile1 = { "sample1.txt" };
	char* inputFile2 = { "sample2.txt" };
	char* outputFile = { "frequency.txt" };


	Text T1(inputFile1);
	Text T2(inputFile2);

	ifstream fin(inputFile1);
	fin >> T1;
	fin.close();
	fin.open(inputFile2);
	fin >> T2;
	fin.close();

	cout << T1 << endl;
	cout << T2 << endl;

	if (T1 == T2)
	{
		cout << "same" << endl;
	}
	else
	{
		cout << "not same" << endl;
	}

	ofstream fout(outputFile);
	fout << T2;
	fout.close();

	T2.decrypt();
	T2.encrypt();
	cout << T2 << endl;	
	T2.decrypt();
	cout << T2 << endl;

	cout << T1 << endl;
	Text T3(outputFile);
	T3 = T1 + T2;
	
	T1++;
	T2--;
	
	
	cout << T1 << endl;
	cout << T2 << endl;
	cout << T3 << endl;
		

	delete[] inputFile1; inputFile1 = '\0';
	delete[] inputFile2; inputFile2 = '\0';
	delete[] outputFile; outputFile = '\0';
	return 0;
}