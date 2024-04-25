#pragma once
class Counter
{
protected:
	char* fileName;
	int characterCount;
	int wordsCount;
	int sentencesCount;
	int punctuationsCount;
public:
	Counter(char*);
	~Counter();
	void update_counts();
	char* get_fileName();
	void set_fileName(char*);
	void update_data(char*);
	int get_charactersCount();
	int get_wordsCount();
	int get_sentencesCount();
	int get_punctuationsCount();
	char* deepcopy(char*);
};