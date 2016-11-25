#include <iostream>
#include <set>
#include <cstring>
#include <string>
#include <iomanip>
#include "utils.hpp"


node::node(): count(0){}
node::node(const std::string word_): word(word_), count(1){}
node::~node(){}

bool operator <(const node& a, const node& b) {
	return a.word<b.word;
}
bool operator >(const node& a, const node& b) {
	return a.word>b.word;
}

size_t node::getCount()const{
	return count;
}

void node::setCount(size_t ncount){
	count = ncount;
}

bool node::operator==(const node &node) const {
	if(this->word==node.word && this->count ==node.count) return true;
		return false;
}
bool node::operator!=(const node &node) const{
	if(this->word==node.word) return false;
		return true;
}

node& node::operator=(const node& other){
		word = other.word;
		count = other.count;
		return *this;
}

node& node::operator=(node& other){
		word = other.word;
		count = other.count;
		return *this;
}
node& node::operator=(const std::string& str){
		word = str;
		count = 0;
		return *this;
}

std::ostream& operator<<(std::ostream& os, const node& obj){
	os <<std::setw(10)<<obj.word<<" : "<<obj.count<<std::endl;
	return os;
}