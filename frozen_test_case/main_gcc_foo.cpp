#include "interface.hpp"
#include <dlfcn.h>
#include <iostream>
#include <memory>

int main(int argc, char **argv){
	void *obj = dlopen("./libplugin1_dl_gcc.so",RTLD_GLOBAL);
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
	std::shared_ptr<Foo> f = std::make_shared<Bar>();
	std::cout << "type of f:" << std::endl;
	std::cout << typeid(f.get()).name() << std::endl;
	p->do_stuff(f);
	destroy_plugin1struct(p);
	dlclose(obj);
}
