#ifndef CLANG_TYPEINFO_TESTER_H
#define CLANG_TYPEINFO_TESTER_H

#include <memory>
#include <iostream>
// hi
class Foo {
public:
	Foo() : ff(22) {}
	int ff;
	~Foo() = default;
	virtual void init() = 0;
};

class Bar : public Foo {
public:
	int bb;
	~Bar() = default;
	void init() override { std::cout << "hi" << std::endl; }
};

struct A {
	virtual ~A();
	virtual void funky() = 0;
};

struct B : A {
	virtual ~B();
	void funky() override;
};

struct plugin
{
	virtual void do_stuff(std::shared_ptr<A>) {}
	virtual ~plugin(){}
};

typedef plugin* create_t();
typedef void destroy_t(plugin*);

#endif
