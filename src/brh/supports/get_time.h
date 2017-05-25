#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_GET_TIME_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_GET_TIME_H

#include <chrono>

namespace brh {
	namespace supports {

template <class T = std::chrono::microseconds>
std::ptrdiff_t getTime() {
	auto now = std::chrono::system_clock::now().time_since_epoch();
	return std::chrono::duration_cast<T>(now).count();
}

	}
}

#endif
