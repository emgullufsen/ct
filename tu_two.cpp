#include "header.h"

struct T {};

int main() {
	auto &TI1 = Info;
	auto &TI2 = typeid(T*);
	assert(TI1 == TI2);
	assert(TI1.hash_code() == TI2.hash_code());
}
