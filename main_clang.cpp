#include "interface.hpp"
#include <dlfcn.h>
#include <iostream>
#include <memory>

int main(int argc, char **argv){
	void *obj = dlopen("./libplugin1_dl.so",RTLD_LAZY);
	// load the plugin1 library
	if (!obj){
		std::cout << "failed to open handle on .so" << std::endl;
		return 1;
	}

	// reset errors
	dlerror();

	// load the symbols
	createfoo_t* createfoo_f = (createfoo_t*)dlsym(obj, "createfoo");
	const char* dlsym_error = dlerror();
	if (dlsym_error){
		std::cout << "failed to symbol: " << dlsym_error << std::endl;
		return 1;
	}

	destroyfoo_t* destroyfoo_f = (destroyfoo_t*)dlsym(obj, "destroyfoo");
	dlsym_error = dlerror();
	if (dlsym_error){
		std::cout << "failed to symbol: " << dlsym_error << std::endl;
		return 1;
	}

	Foo *f = createfoo_f();
	std::shared_ptr<A> a = std::make_shared<A>();
	p->do_stuff(a);
	destroy_plugin1struct(p);
	dlclose(obj);
}
