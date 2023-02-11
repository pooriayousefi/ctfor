
#include <iostream>
#include "ctfor.h"

auto main() -> int
{
	try
	{
		int i = 0, j = 0, k = 0;
		float f = 0.0f;
		double d = 0.0;
		std::string s{ "0 " };

		std::cout << "\ninitial values: " << i << ' ' << f << ' ' << d << ' ' << s << std::endl;

		ctfor([](auto& inp) { using T = std::remove_reference_t<decltype(inp)>;
		if constexpr (std::is_same_v<T, std::string>)
			inp += std::string{ "1 " };
		else
			inp += 1; }, i, f, d, s);

		std::cout << "\nmodified values: " << i << ' ' << f << ' ' << d << ' ' << s << std::endl;

		return EXIT_SUCCESS;
	}
	catch (const std::exception& xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return EXIT_FAILURE;
	}
}