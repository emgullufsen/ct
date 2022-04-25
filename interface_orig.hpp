#ifndef INTERFACE_ORIG_H
#define INTERFACE_ORIG_H

#include <memory>
#include <iostream>

struct A {
	virtual void funky(){ std::cout << "A funky" << std::endl; }
	void kfunky() { std::cout << "this works" << std::endl; }
};
struct B : A {
	void funky() override { std::cout << "B funky" << std::endl; }
	//~B(){}
};
struct plugin
{
	virtual void do_stuff(std::shared_ptr<A>) {}
	virtual ~plugin(){}
};

typedef plugin* create_t();
typedef void destroy_t(plugin*);

#endif
