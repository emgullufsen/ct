#include "interface_noimpl.hpp"
A::~A(){}
B::~B(){}

void B::funky() { 
	std::cout << "B funky" << std::endl; 
	return;
}
