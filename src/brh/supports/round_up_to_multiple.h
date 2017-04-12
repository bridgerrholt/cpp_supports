#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_ROUND_UP_TO_MULTIPLE_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_ROUND_UP_TO_MULTIPLE_H

namespace brh {
	namespace supports {

/// @param numberToRound The number that will be rounded.
template <class T1, class T2 = T1>
constexpr void roundUpToMultipleRef(T1 & numberToRound, T2 factor) {
	auto remainder = numberToRound % factor;

	if (numberToRound % factor != 0)
		numberToRound += factor - remainder;
}


/// Rounds a number up to a multiple of a factor.
/// Does not round up if the number is already divisible by the factor.
/// @param numberToRound The number that will be rounded then returned.
/// @param factor        What the return value will be divisible by.
/// @return A number >= @ref numberToRound and divisible by @ref factor.
template <class T1, class T2 = T1>
constexpr T1 roundUpToMultiple(T1 numberToRound, T2 factor) {
	roundUpToMultipleRef(numberToRound, factor);
	return numberToRound;
}


	}
}

#endif
