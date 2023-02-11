
#pragma once
#include <functional>

namespace
{
	// compile-time for
	template<typename F, typename... T>
	auto ctfor(F&& fn, T&... args) -> void
	{
		if constexpr (sizeof...(args) == static_cast<size_t>(0))
			return;
		(fn(args), ...);
	}
}
