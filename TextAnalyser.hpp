#ifndef TEXTANALYSER_HPP
#define TEXTANALYSER_HPP
#include <set>
#include "Comparator.hpp"

class TextAnalyser{
private:
	int argc;
	char **argv;
	std::set<node, Comparator>myset;
public:
	~TextAnalyser();
	TextAnalyser();
	//TextAnalyser(const TextAnalyser& other);
	TextAnalyser(int argc_, char** argv_);
	std::set<node,Comparator>& analyse();
	void printResult(std::set<node,Comparator>& myset);
};


#endif
