#include "interface.hpp"
#include <iostream>
#include <memory>

struct plugin1 : plugin {
	void do_stuff(std::shared_ptr<Foo> f) override {
		if (!f){
			std::cout << "not a" << std::endl;
			return;
		}
		auto b = std::dynamic_pointer_cast<Bar>(f);
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

extern "C" plugin* create() {
	return new plugin1;
}

extern "C" void destroy(plugin *p){
	delete p;
}
