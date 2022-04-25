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
	int aa;
	virtual ~A(){}
	virtual void funky() { std::cout << "A funky" << std::endl; }
	void kfunky() { std::cout << "this works" << std::endl; }
};

struct B : A {
	int bb;
	void  funky() override { std::cout << "B funky" << std::endl; }
	~B(){}
};
struct plugin
{
	virtual void do_stuff(std::shared_ptr<A>) {}
	virtual ~plugin(){}
};

typedef plugin* create_t();
typedef void destroy_t(plugin*);
