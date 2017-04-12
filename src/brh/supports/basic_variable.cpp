#include "basic_variable.h"

namespace brh {
	namespace supports {

// ObjectBase
ObjectBase::~ObjectBase() {}


// BasicVariable
BasicVariable::BasicVariable(ObjectBase* object) : object_ {object} {}

BasicVariable::BasicVariable(BasicVariable && other)
{
	object_ = std::move(other.object_);
}



BasicVariable &
BasicVariable::operator=(BasicVariable other)
{
	swap(*this, other);
	return *this;
}



void swap(BasicVariable& first, BasicVariable& second)
{
	using std::swap;
	swap(first.object_, second.object_);
}


	}
}