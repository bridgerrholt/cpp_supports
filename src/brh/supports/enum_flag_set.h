#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_ENUM_FLAG_SET_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_ENUM_FLAG_SET_H

#include "numeric_enum.h"

namespace brh {
	namespace supports {

/// Provides convenient ways of storing and altering an enum value.
/// Internally holds a @ref NumericEnum.
/// @tparam t_EnumType   The enum type to pass to @ref NumericEnum.
/// @tparam t_NumberType The number type to pass to @ref NumericEnum.
template <class t_EnumType, class t_NumberType = int>
class EnumFlagSet
{
	public:
		using EnumType        = t_EnumType;
		using NumberType      = t_NumberType;
		using NumericEnumType = NumericEnum<EnumType, NumberType>;

		/// ORs together multiple enum values.
		template <class ... ArgPack>
		constexpr EnumFlagSet(EnumType first, ArgPack ... others) :
			EnumFlagSet (first) {

			for (auto const & next : {others...}) {
				set(EnumType(next));
			}
		}

		template <class ... ArgPack>
		constexpr EnumFlagSet(NumericEnumType first, ArgPack ... others) :
			EnumFlagSet(first.value, others...) {}


		/// Uses a single enum value.
		constexpr EnumFlagSet(EnumType value) :
			EnumFlagSet (NumericEnumType(value)) {}

		/// Copies over a NumericEnum.
		constexpr EnumFlagSet(NumericEnumType numericEnum) :
			numericEnum_ {numericEnum} {}


		/// Sets the given enum within the value.
		/// ORs the internal enum value with @ref value.
		/// @param value The enum to set.
		/// @return A reference to the instance.
		constexpr EnumFlagSet & set(NumericEnumType value) {
			numericEnum_ |= value;
			return *this;
		}

		constexpr EnumFlagSet & set(EnumType value) {
			return set(NumericEnumType(value));
		}


		/// Unsets the given enum within the value.
		/// ANDs the internal enum value with the NOT of @ref value.
		/// @param value The enum to unset.
		/// @return A reference to the instance.
		constexpr EnumFlagSet & unset(NumericEnumType value) {
			numericEnum_ &= ~value;
			return *this;
		}

		constexpr EnumFlagSet & unset(EnumType value) {
			return unset(NumericEnumType(value));
		}


		/// Checks whether the given value is within the internal enum or not.
		/// @param value The
		constexpr bool isSet(NumericEnumType value) const {
			return ((numericEnum_ & value) == value);
		}

		constexpr bool isSet(EnumType value) const {
			return isSet(NumericEnumType(value));
		}


		constexpr NumericEnumType & getNumericEnum()       { return numericEnum_; }
		constexpr NumericEnumType   getNumericEnum() const { return numericEnum_; }

		constexpr EnumType & getEnum()       { return numericEnum_.value; }
		constexpr EnumType   getEnum() const { return numericEnum_.value; }


	private:
		NumericEnumType numericEnum_;
};


	}
}

#endif
