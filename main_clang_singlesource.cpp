#include "interface_noimpl.hpp"
#include <dlfcn.h>
#include <iostream>
#include <memory>
#include <typeinfo>

int main(int argc, char **argv){
	void *obj = dlopen("./libplugin1AA.so",RTLD_LOCAL);
	// load the plugin1 library
	if (!obj){
		std::cout << "failed to open handle on .so" << std::endl;
		return 1;
	}

	// reset errors
	dlerror();

	// load the symbols
	create_t* create_plugin1struct = (create_t*)dlsym(obj, "create");
	const char* dlsym_error = dlerror();
	if (dlsym_error){
		std::cout << "failed to symbol: " << dlsym_error << std::endl;
		return 1;
	}

	destroy_t* destroy_plugin1struct = (destroy_t*)dlsym(obj, "destroy");
	dlsym_error = dlerror();
	if (dlsym_error){
		std::cout << "failed to symbol: " << dlsym_error << std::endl;
		return 1;
	}

	plugin* p = create_plugin1struct();
	std::shared_ptr<A> a = std::make_shared<B>();
	std::cout << "type of a:" << std::endl;
	std::cout << typeid(a.get()).name() << std::endl;
	p->do_stuff(a);
	destroy_plugin1struct(p);
	dlclose(obj);
}
