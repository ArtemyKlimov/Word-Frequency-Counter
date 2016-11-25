#ifndef NEWFUNC_HPP
#define NEWFUNC_HPP
#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iterator>
#include <algorithm>

struct node{
	std::string word;
	size_t count;
	node();
	node(const std::string word_);
	~node();
	size_t getCount()const;
	void setCount(size_t ncount);
	bool operator==(const node &node) const;
	bool operator!=(const node &node) const;
	node& operator=(const node& other);
	node& operator=(node& other);
	node& operator=(const std::string& str);
	friend bool operator <(const node& a, const node& b);
	friend bool operator >(const node& a, const node& b);
	friend std::istream& operator>>(std::istream& is, node& obj);
	friend std::ostream& operator<<(std::ostream& os, const node& obj);
};


struct letter_only: std::ctype<char> {
    letter_only(): std::ctype<char>(get_table()) {}

    static std::ctype_base::mask const* get_table(){
        static std::vector<std::ctype_base::mask> 
            rc(std::ctype<char>::table_size,std::ctype_base::space);
        std::fill(&rc['A'], &rc['z'+1], std::ctype_base::alpha);
        return &rc[0];
    }
};


#endif