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

	std::cout << std::endl;
}


int main()
{
	
	wvector<int> wv1;
	wv1.PushBack(102);
	wv1.PushBack(88);
	wv1.PushBack(34);
	wv1.PushBack(23);
	wv1.PushBack(11);

	/*
	wvector<int> wv2;
	wv2.PushBack(192);
	wv2.PushBack(88);
	wv2.PushBack(8);
	wv2.PushBack(77);
	wv2.PushBack(111);
	wv2.PushBack(7);
	wv2.PushBack(60);
	*/

	//wv1.Swap(wv2);

	wvector<int> wv2(wv1);

	PrintVector(wv2);
	//PrintVector(wv2);
	

	

	return 0;
}