#ifndef SOME_CLASS_GEN_HPP
#define SOME_CLASS_GEN_HPP

#include <type_traits>


#include "ReflectionRuntime.hpp"



namespace SomeNamespace
{
	class SomeClass;
}

namespace QED
{
	namespace Tools
	{
		namespace Reflection
		{
			namespace Runtime
			{

				template <>
				struct isReflective<SomeNamespace::SomeClass> : std::true_type { };

				template <>
				constexpr std::string_view Name<SomeNamespace::SomeClass>() { return "SomeClass"sv; }


			}
		}
	}
}


#endif // !SOME_CLASS_GEN_HPP

