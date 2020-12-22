#ifndef REFLECTION_RUNTIME_HPP
#define REFLECTION_RUNTIME_HPP

#include <type_traits>
#include <string_view>
using namespace std::string_view_literals;

namespace QED
{
	namespace Tools
	{
		namespace Reflection
		{
			namespace Runtime
			{
				// Declarations with Reflection attribute are given the 'Reflective' trait
				template <typename T>
				struct isReflective : std::false_type { };

				// Declarations with Reflection attribute return their name as string
				template <typename T>
				constexpr std::string_view Name() { return ""sv; }

				class ClassReflection
				{

				};
			}
		}
	}
}



#endif // !REFLECTION_RUNTIME_HPP
