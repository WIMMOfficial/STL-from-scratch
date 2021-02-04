#include "vector.h"
template <typename T>
void PrintVector(const vector<T>& v)
{
	for (size_t i = 0; i < v.Size(); ++i)
	{
		std::cout << v.At(i) << " ";
	}
}


int main()
{

	vector<int> vect;
	vect.PushBack(5);
	vect.PushBack(8);
	vect.PushBack(10);
	vect.PushBack(23);
	vect.PushBack(23);
	vect.PushBack(90);
	vect.PushBack(44);
	vect.PushBack(11);
	vect.PushBack(0);
	vect.PushBack(4);
	vect.PushBack(-3);

	PrintVector(vect);

	vect.PopBack();
	vect.PopBack();
	vect.PopBack();

	std::cout << std::endl;

	PrintVector(vect);

	return 0;
}