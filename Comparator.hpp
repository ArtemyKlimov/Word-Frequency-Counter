#ifndef COMPARATOR_HPP
#define COMPARATOR_HPP
#include "utils.hpp"

class Comparator {
public:
	bool operator()(const node& left, const node& right)
	{
		if(left.count < right.count && left.count !=1) return false;
		if(left.count < right.count && left.count ==1) return false;
		if(left.count > right.count) return true;
		if(left.word < right.word) return true;
		return false;
	}
};

#endif