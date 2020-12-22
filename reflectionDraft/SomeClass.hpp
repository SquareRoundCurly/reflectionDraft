#ifndef SOME_CLASS_HPP
#define SOME_CLASS_HPP

#include "SomeClass.gen.hpp"

namespace SomeNamespace
{

	// Reflection
	class SomeClass
	{
	public:

	private:
		int member = 5;
		// Reflection
		void SomeMethod();
	};

	// tag used to access SomeClass::member
	struct SomeClass_member
	{
		typedef int SomeClass::* type;
		friend type get(SomeClass_member);
	};

	template struct inject<SomeClass_member, &SomeClass::member>;

	template<typename Tag, typename Tag::type M>
	struct inject
	{
		friend typename Tag::type get(Tag)
		{
			return M;
		}
	};

} // !SomeNamespace

#endif // !SOME_CLASS_HPP
