#ifndef _SIMPLE_CPP_SUPPORTS__BASIC_VARIABLE_H
#define _SIMPLE_CPP_SUPPORTS__BASIC_VARIABLE_H

#include <memory>

namespace scs {

class ObjectBase
{
	public:
		virtual ~ObjectBase() = 0;
};



template <class T>
class BasicObject : public ObjectBase
{
	public:
		typedef T Type;

		BasicObject(Type objectSet) : object {std::move(objectSet)} {}

		Type object;
};



class BasicVariable
{
	public:
		friend void swap(BasicVariable& first, BasicVariable& second);

		BasicVariable() {}
		BasicVariable(ObjectBase* object);
		template <class T>
		BasicVariable(T object) : object_ {new BasicObject<T>(std::move(object))} {}
		BasicVariable(BasicVariable && other);

		BasicVariable & operator=(BasicVariable other);


		template <class T>
		typename BasicObject<T>::Type& get() {
			return dynamic_cast<BasicObject<T>*>(object_.get())->object;
		}

		template <class T>
		T const & get() const {
			return dynamic_cast<BasicObject<T> const *>(object_.get())->object;
		}


	private:
		std::unique_ptr<ObjectBase> object_;
};

} // scs

#endif // _SIMPLE_CPP_SUPPORTS__BASIC_VARIABLE_H
