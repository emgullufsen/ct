#include "interface_orig.hpp"
#include <dlfcn.h>
#include <iostream>
#include <memory>

int main(int argc, char **argv){
	void *obj = dlopen("./libplugin1_dl_gcc.so",RTLD_LAZY);
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
	std::shared_ptr<A> a = std::make_shared<A>();
	p->do_stuff(a);
	destroy_plugin1struct(p);
	dlclose(obj);
}
