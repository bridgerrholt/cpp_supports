#ifndef BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_BASIC_VARIABLE_H
#define BRH_CPP_SUPPORTS_SRC_BRH_SUPPORTS_BASIC_VARIABLE_H

#include <memory>

namespace brh {
	namespace supports {

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

	}
}


#endif
