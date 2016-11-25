#include <iostream>
#include <stdexcept>
#include "utils.hpp"
#include "TextAnalyser.hpp"
#include "Comparator.hpp"



int main(int argc, char** argv){
	if(argc<2){
        throw std::out_of_range("too few arguments of command line");
    }
    TextAnalyser Analyser(argc, argv);
    try{
    	std::set<node,Comparator> Words= Analyser.analyse();
    	Analyser.printResult(Words);
    }catch(std::bad_alloc &ba){
    	std::cout<<"caught: "<<ba.what()<<std::endl;
    }
    return 0;
}