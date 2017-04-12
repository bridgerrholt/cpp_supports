#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_CALC_LCM_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_CALC_LCM_H

#include <functional>

#include "calc_gcd.h"

namespace brh {
	namespace supports {

/// Uses any greatest common divisor function.
template <class T, class GcdFunc>
constexpr T calcLcm(T first, T second, GcdFunc gcdFunc) {
	return ((first / gcdFunc(first, second)) * second);
}

/// Calculates the least common multiple of two numbers.
/// Uses the Euclidean algorithm for greatest commmon divisor.
/// @param first  One of the numbers.
/// @param second One of the numbers.
/// @return The least common multiple of @ref first and @ref second.
template <class T>
constexpr T calcLcm(T first, T second) {
	return calcLcm(first, second, std::function<T(T, T)>(calcGcd<T>));
}


	}
}

#endif
