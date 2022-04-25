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
	virtual void funky() { }
	/*void kfunky() { 
		std::cout << "this works" << std::endl; 
	}*/
	virtual ~A(){}
};

struct B : A {
	void  funky() override { 
		std::cout << "B funky" << std::endl; 
		return;
	}
	~B(){}
};
struct plugin
{
	virtual void do_stuff(std::shared_ptr<A>) {}
	virtual ~plugin(){}
};

typedef plugin* create_t();
typedef void destroy_t(plugin*);

struct plugin1 : plugin {
	void do_stuff(std::shared_ptr<A> a) override {
		if (!a){
			std::cout << "not a" << std::endl;
			return;
		}
		auto b = std::dynamic_pointer_cast<B>(a);
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
