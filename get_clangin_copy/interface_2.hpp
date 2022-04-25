#include <memory>
#include <iostream>

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
	virtual void funky() = 0;
	virtual ~A(){}
	int num();
};

int A::num() { return 33; }

struct B : A {
	void funky() override { 
		std::cout << "B funky" << std::endl; 
		return;
	}
	~B(){}
};

struct plugin
{
	virtual void do_stuff(std::shared_ptr<A>) const = 0;
	virtual ~plugin() = default;
};

typedef plugin* create_t();
typedef void destroy_t(plugin*);
