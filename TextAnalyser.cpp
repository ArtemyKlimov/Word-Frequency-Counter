#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <stdexcept>
#include "utils.hpp"
#include "Comparator.hpp"
#include "TextAnalyser.hpp"

TextAnalyser::TextAnalyser(int argc_, char** argv_) : argc(argc_), argv(argv_){}
TextAnalyser::TextAnalyser() : argc(0), argv(nullptr){}
TextAnalyser::~TextAnalyser(){}

std::set<node, Comparator>& TextAnalyser::analyse(){
std::string newword;
bool element_exist;
for(int i = 1; i<argc; ++i){
    std::ifstream file(argv[i]);
    if(file.is_open()){
    	file.imbue(std::locale(std::locale(), new letter_only()));
    	try{
	     	while(file>>newword){
    			element_exist = false;
    			node found_element;
	     		node n(newword);
	     		for(auto it: myset)
	     			if(n.word == it.word){
	     				element_exist =true;
	     				found_element = it;
	     				break;
	     			}
     			if(!element_exist)
     				myset.insert(n);
     			else{
     				myset.erase(found_element);
     				size_t ncount= found_element.getCount();
     				ncount++;
     				found_element.setCount(ncount);
     				myset.insert(found_element);
     			}
	     	}
	    }catch(std::bad_alloc &ba){
	    	throw ba;
	    }
    file.close();
    }
	else{
		throw std::out_of_range("can not open file");
	}
}
return myset;
}

void TextAnalyser::printResult(std::set<node, Comparator>& myset)
{
	for(std::set<node, Comparator>::iterator it = myset.begin(); it !=myset.end(); ++it){
		std::cout<<*it;
	}
}