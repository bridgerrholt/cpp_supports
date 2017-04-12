#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <tuple>

#include <brh_supports.h>

template<class F, class...Ts, std::size_t...Is>
void forEachInTuple(const std::tuple<Ts...> & tuple, F func, std::index_sequence<Is...>){
	using expander = int[];
	(void)expander { 0, ((void)func(std::get<Is>(tuple)), 0)... };
}

template<class F, class...Ts>
void forEachInTuple(const std::tuple<Ts...> & tuple, F func){
	forEachInTuple(tuple, func, std::make_index_sequence<sizeof...(Ts)>());
}

template <class Stream, class ... ArgTypes>
void addArgsToStream(Stream & stream, std::string delimiter, ArgTypes ... args) {
	std::tuple<ArgTypes...> container {args...};

	forEachInTuple(container, [&stream](const auto &x) { stream << x << ", "; });
}

template <class F, class ... ArgTypes>
void outputFunctionTest(std::string functionName, F func, ArgTypes ... args) {

	std::cout << functionName << "(";

	std::stringstream stream;
	addArgsToStream(stream, ", ", args...);

	std::string toPrint = stream.str();
	toPrint.erase(toPrint.end()-2, toPrint.end());

	std::cout << toPrint << ") -> " << func(args...) << '\n';
};

int main(int argc, char* argv[]) {
	using namespace brh::supports;

	outputFunctionTest("calcGcd", std::function<int(int, int)>(calcGcd<int>), 49, 70);
	outputFunctionTest("calcLcm", std::function<int(int, int)>(calcLcm<int>), 49, 70);

	outputFunctionTest("roundUpToMultiple", std::function<int(int, int)>(roundUpToMultiple<int>), 143, 70);
}