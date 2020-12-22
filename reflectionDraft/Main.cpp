



//#include "ReflectionRuntime.hpp"

//#include "SomeClass.hpp"

#include <iostream>
#include <functional>


// use
struct A {
	A(int a) :a(a) { }
private:
	int a;
	void Print() { std::cout << "Hello" << std::endl; }
};


template<typename Tag, typename Tag::type M>
struct Rob {
	friend typename Tag::type get(Tag) {
		return M;
	}
};

template<typename Tag, typename Member>
struct TagBase {
	typedef Member type;
	friend type get(Tag);
};

//// tag used to access A::a
//struct A_f {
//	typedef int A::* type;
//	friend type get(A_f);
//};

struct A_f : TagBase<A_f, int A::*> { };
struct A_f2 : TagBase<A_f2, void(A::*)(void)> { };

template struct Rob<A_f, &A::a>;
template struct Rob<A_f2, &A::Print>;

int main() {
	A a(42);
	std::cout << "proof: " << a.*get(A_f()) << std::endl;
	(a.*get(A_f2()))();
}



//int main()
//{
//	std::cout << QED::Tools::Reflection::Runtime::isReflective<test>() << std::endl;
//	std::cout << QED::Tools::Reflection::Runtime::isReflective<SomeNamespace::SomeClass>() << std::endl;
//
//	std::cout << QED::Tools::Reflection::Runtime::Name<SomeNamespace::SomeClass>() << std::endl;
//	std::cout << QED::Tools::Reflection::Runtime::Name<test>() << std::endl;
//
//
//
//
//
//	return 0;
//}