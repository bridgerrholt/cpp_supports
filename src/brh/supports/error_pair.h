#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_ERROR_PAIR_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_ERROR_PAIR_H

#include <string>
#include <tuple>

namespace brh {
	namespace supports {

template <class T>
class BasicErrorPair
{
	public:
		void swap(BasicErrorPair & first, BasicErrorPair & second) {
			using std::swap;

			swap(first.pairedBool_, second.pairedBool_);
		}

		BasicErrorPair() :
			pairedBool_ (T(), false) {}

		BasicErrorPair(T value) :
			pairedBool_ (std::move(value), true) {}

		template <class ... ArgPack>
		BasicErrorPair(ArgPack ... valueArgs) :
			BasicErrorPair (T(valueArgs...)) {}

		BasicErrorPair(BasicErrorPair && other) : BasicErrorPair() {
			swap(*this, other);
		}

		BasicErrorPair & operator=(BasicErrorPair other) {
			swap(*this, other);

			return *this;
		}

		T       & get()       { return pairedBool_.first; }
		T const & get() const { return pairedBool_.first; }

		bool     failed() const { return pairedBool_.second; }
		operator bool()   const { return failed(); }


	private:
		std::pair<T, bool> pairedBool_;
};

using ErrorPair = BasicErrorPair<std::string>;


	}
}

#endif
