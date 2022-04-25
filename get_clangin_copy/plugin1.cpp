#include <memory>
#include <iostream>
#include "interface.hpp"

struct plugin1 : plugin {
	void do_stuff(std::shared_ptr<A> a) override {
		if (!a){
			std::cout << "not a" << std::endl;
			return;
		}
		auto b = std::static_pointer_cast<B>(a);
		if (!b){
			std::cout << "unsuccessful cast" << std::endl;
			return;
		}
		else {
			std::cout << "successful cast" << std::endl;
			return;
		}
	}
	~plugin1(){}
};

extern "C" B* createb() {
	return new B;
}

extern "C" void destroyb(B *b){
	delete b;
}

extern "C" plugin* create() {
	return new plugin1;
}

extern "C" void destroy(plugin *p){
	delete p;
}
