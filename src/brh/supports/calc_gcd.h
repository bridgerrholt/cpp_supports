#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_CALC_GCD_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_CALC_GCD_H

namespace brh {
	namespace supports {

/// Calculates the greatest common divisor of
/// two numbers using the Euclidean algorithm.
/// @param first  One of the numbers.
/// @param second One of the numbers.
/// @return The greatest common divisor of @ref first and @ref second.
template <class T>
constexpr T calcGcd(T first, T second)
{
	while (second != 0) {
		auto temp = second;
		second = first % second;
		first = temp;
	}

	return first;
}


	}
}

#endif
