#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_NUMERIC_ENUM_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_NUMERIC_ENUM_H

namespace brh {
	namespace supports {

/// A templated wrapper providing numeric operations to an enum type.
/// @tparam t_EnumType   The enum type to hold.
/// @tparam t_NumberType The type to cast the enum to during operations.
template <class t_EnumType, class t_NumberType = int>
class NumericEnum
{
	public:
		using EnumType   = t_EnumType;
		using NumberType = t_NumberType;

		/// The value stored by this instance.
		EnumType value;


		constexpr NumericEnum(EnumType valueSet) :
			value {valueSet} {}

		constexpr NumericEnum(NumberType valueSet) :
			value {static_cast<EnumType>(valueSet)} {}


		constexpr NumberType getNumeric() const {
			return castEnum(value);
		}

		constexpr NumberType & getNumeric() {
			return *reinterpret_cast<NumberType*>(&value);
		}


		static constexpr NumberType castEnum(EnumType value) {
			return static_cast<NumberType>(value);
		}

		constexpr explicit operator EnumType() {
			return value;
		}

		friend constexpr NumericEnum operator~(NumericEnum object) {
			return {~object.getNumeric()};
		}

		friend constexpr NumericEnum operator!(NumericEnum object) {
			return {!object.getNumeric()};
		}


		friend constexpr NumericEnum operator|(NumericEnum first,
		                                       NumericEnum second) {
			return {first.getNumeric() | second.getNumeric()};
		}

		friend constexpr NumericEnum operator&(NumericEnum first,
		                                       NumericEnum second) {
			return {first.getNumeric() & second.getNumeric()};
		}

		friend constexpr NumericEnum operator^(NumericEnum first,
		                                       NumericEnum second) {
			return {first.getNumeric() ^ second.getNumeric()};
		}


		friend constexpr NumericEnum operator|=(NumericEnum & first,
		                                        NumericEnum   second) {
			first.getNumeric() |= second.getNumeric();
			return first;
		}

		friend constexpr NumericEnum operator&=(NumericEnum & first,
		                                        NumericEnum second) {
			first.getNumeric() &= second.getNumeric();
			return first;
		}

		friend constexpr NumericEnum operator^=(NumericEnum & first,
		                                        NumericEnum second) {
			first.getNumeric() ^= second.getNumeric();
			return first;
		}


		friend constexpr bool operator==(NumericEnum first,
		                                 NumericEnum second) {
			return (first.value == second.value);
		}

		friend constexpr bool operator!=(NumericEnum first,
		                                 NumericEnum second) {
			return !(first == second);
		}
};


	}
}

#endif
