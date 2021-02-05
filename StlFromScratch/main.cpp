#include <string>
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
	wvector<std::string> v;
	v.PushBack("Hello");
	v.PushBack("World");

	PrintVector(v);
	
	return 0;
}