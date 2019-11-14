//Saar Haber

#include "my_memory.h"

//Unique Pointer Class:

//DEFAULT CONSTRUCOTR
template <typename Type>
my_unique_ptr<Type>::my_unique_ptr() : ptr_(nullptr) {}

//PARAMETERIZED CONSTRUCTOR
template <typename Type>
my_unique_ptr<Type>::my_unique_ptr(Type *rhsPtr) : ptr_(rhsPtr) {}

//MOVE CONSTRUCTOR
template <typename Type>
my_unique_ptr<Type>::my_unique_ptr(my_unique_ptr &&rhs) : ptr_(rhs.ptr_)
{
	rhs.ptr_ = nullptr;
}

//DESTRUCTOR
template <typename Type>
my_unique_ptr<Type>::~my_unique_ptr()
{
	if (ptr_ != nullptr)
	{
		delete ptr_;
		ptr_ = nullptr;
	}
}

//DEREFRENCE OPERATOR
template <typename Type>
Type &my_unique_ptr<Type>::operator*()
{
	if (ptr_ == nullptr)
	{
		throw;
	}

	return *ptr_;
}

//OPERATOR ->
template <typename Type>
Type *my_unique_ptr<Type>::operator->()
{
	return ptr_;
}

//MOVE ASSIGMENT
template <typename Type>
my_unique_ptr<Type> &my_unique_ptr<Type>::operator=(my_unique_ptr &&rhs)
{
	if (ptr_ == nullptr)
	{
		ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;
	}
	else if (this != &rhs)
	{
		Type *temporary(nullptr);

		temporary = ptr_;

		ptr_ = rhs.ptr_;
		rhs.ptr_ = nullptr;

		delete temporary;
		temporary = nullptr;
	}

	return *this;
}

//isNullptr
template <typename Type>
bool my_unique_ptr<Type>::isNullptr()
{
	return (ptr_ == nullptr);
}

//Shared Pointer Class:

//DEAFULT CONSTRUCTOR
template <typename Type>
my_shared_ptr<Type>::my_shared_ptr() : sharedPtr(nullptr), counter(nullptr) {}

//PARAMETERIZED CONSTRUCTOR
template <typename Type>
my_shared_ptr<Type>::my_shared_ptr(Type *ptr_) : sharedPtr(ptr_), counter(new int{1}) {}

//COPY CONSTRUCTOR
template <typename Type>
my_shared_ptr<Type>::my_shared_ptr(const my_shared_ptr &rhs) : sharedPtr(rhs.sharedPtr), counter(rhs.counter)
{
	if (counter != nullptr)
		(*counter) += 1;
}

//MOVE CONSTRUCTOR
template <typename Type>
my_shared_ptr<Type>::my_shared_ptr(my_shared_ptr &&rhs) : sharedPtr(rhs.sharedPtr), counter(rhs.counter)
{
	rhs.sharedPtr = nullptr;
	rhs.counter = nullptr;
}

//DESTRUCTOR
template <typename Type>
my_shared_ptr<Type>::~my_shared_ptr()
{
	if (counter != nullptr)
	{

		if ((*counter) > 1)
		{
			(*counter) -= 1;
			counter = nullptr;
			sharedPtr = nullptr;
		}
		else
		{
			delete counter;
			counter = nullptr;
			delete sharedPtr;
			sharedPtr = nullptr;
		}
	}
}

//OPERATOR ->
template <typename Type>
Type *my_shared_ptr<Type>::operator->()
{
	if (sharedPtr == nullptr)
	{
		throw;
	}
	return sharedPtr;
}

//DEREFERENCE OPERATOR
template <typename Type>
Type &my_shared_ptr<Type>::operator*()
{
	if (sharedPtr == nullptr)
	{
		throw;
	}
	return *sharedPtr;
}

//MOVE ASSIGNMENT
template <typename Type>
my_shared_ptr<Type> &my_shared_ptr<Type>::operator=(my_shared_ptr &&rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	if (sharedPtr == nullptr || counter == nullptr)
	{
		sharedPtr = rhs.sharedPtr;
		rhs.sharedPtr = nullptr;
		counter = rhs.counter;
		rhs.counter = nullptr;
		//return *this;
	}
	else if ((*counter) <= 1)
	{
		Type *temporary;
		int *countTemporary;

		temporary = sharedPtr;
		countTemporary = counter;

		sharedPtr = rhs.sharedPtr;
		counter = rhs.counter;

		rhs.counter = nullptr;
		rhs.sharedPtr = nullptr;

		delete temporary;
		delete countTemporary;

		return *this;
	}
	else if ((*counter) > 1)
	{
		(*counter) -= 1;

		sharedPtr = rhs.sharedPtr;
		counter = rhs.counter;

		rhs.sharedPtr = nullptr;
		rhs.counter = nullptr;
	}

	return *this;
}

//COPY ASSIGNMENT
template <typename Type>
my_shared_ptr<Type> &my_shared_ptr<Type>::operator=(const my_shared_ptr &rhs)
{
	//already the same:
	if (this == &rhs)
	{
		return *this;
	}

	if (counter == nullptr)
	{
		sharedPtr = rhs.sharedPtr;
		counter = rhs.counter;
	}
	else if ((*counter) == 1)
	{

		counter = rhs.counter;
		sharedPtr = rhs.sharedPtr;
	}
	else if ((*counter) > 1)
	{
		(*counter) -= 1;
		counter = rhs.counter;
		sharedPtr = rhs.sharedPtr;
	}

	if (counter != nullptr)
	{
		(*counter) += 1;
	}
	return *this;
}

//isNullptr
template <typename Type>
bool my_shared_ptr<Type>::isNullptr()
{
	return (sharedPtr == nullptr);
}