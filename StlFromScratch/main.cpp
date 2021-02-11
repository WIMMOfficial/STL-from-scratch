#include <array>
#include <string>
#include <iostream>
#include "warray.h"
#include "wvector.h"


template <typename T>
void PrintVector(const wvector<T>& v)
{
	for (size_t i = 0; i < v.Size(); ++i)
	{
		std::cout << v[i] << " ";
	}

	std::cout << std::endl;
}


template <typename T, size_t N>
void PrintArr(const warray<T, N>& wa)
{
	for (size_t i = 0; i < wa.Size(); ++i)
	{
		std::cout << wa[i] << " ";
	}

	std::cout << std::endl;
}


template<typename T, size_t N>
void PrintArray(const std::array<T, N> arr)
{
	for (size_t i = 0; i < arr.size(); ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


int main()
{
	return 0;
}