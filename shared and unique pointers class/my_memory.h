//Saar Haber

#ifndef MY_MEMORY_
#define MY_MEMORY_

template <typename Type>
class my_unique_ptr
{
public:
	//constructors
	my_unique_ptr();
	my_unique_ptr(Type *rhsPtr);
	my_unique_ptr(my_unique_ptr &&rhs);
	my_unique_ptr(const my_unique_ptr &tempPtr) = delete;

	//destructor
	~my_unique_ptr();

	//operators
	Type &operator*();
	Type *operator->();
	my_unique_ptr &operator=(my_unique_ptr &&rhs);
	my_unique_ptr &operator=(const my_unique_ptr &rhs) = delete;

	bool isNullptr();

private:
	Type *ptr_;
};

template <typename Type>
class my_shared_ptr
{
public:
	//constructors
	my_shared_ptr();
	my_shared_ptr(Type *ptr_);
	my_shared_ptr(const my_shared_ptr &rhs);
	my_shared_ptr(my_shared_ptr &&rhs);

	//destructor
	~my_shared_ptr();

	//operators
	Type &operator*();
	Type *operator->();
	my_shared_ptr &operator=(const my_shared_ptr &rhs);
	my_shared_ptr &operator=(my_shared_ptr &&rhs);

	bool isNullptr();

private:
	Type *sharedPtr;
	int *counter;
};

#include "my_memory.cpp"
#endif