#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_CALC_IS_ALIGNED_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_CALC_IS_ALIGNED_H

#include <cstdint>

namespace brh {
	namespace supports {

/// Calculates whether the given pointer is aligned to the specified alignment.
/// @param ptr       The pointer for an alignment of @ref alignment.
/// @param alignment The alignment that @ref ptr must be.
/// @return If @ref ptr is divisible by @ref alignment.
template <class P, class T = std::size_t>
constexpr bool calcIsAligned(P * ptr, T alignment)
{
	return (reinterpret_cast<std::uintptr_t>(ptr) % alignment == 0);
}


	}
}

#endif
