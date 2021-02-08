#include <string>
#include <vector>
#include "wvector.h"

template <typename T>
void PrintVector(const wvector<T>& v)
{
	for (size_t i = 0; i < v.Size(); ++i)
	{
		std::cout << v[i] << " ";
	}
}


int main()
{
	return 0;
}