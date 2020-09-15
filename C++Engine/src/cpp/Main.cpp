#include <iostream>
#include "../hpp/Array.h"//Array Functionality.
#include "../hpp/Vector.h"//Vector Functionality.
#include "../hpp/Vector3.h"//Vector3 Functionality.

template<typename T>
void PrintVector(const Vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;

	std::cout << "------------------------------------\n";
}

template<>
void PrintVector(const Vector<Vector3>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i].x << ", " << vector[i].y << ", " << vector[i].z << std::endl;

	std::cout << "------------------------------------\n";
}

int main()
{
	Vector<std::string> values;
	values.EmplaceBack("1");
	values.EmplaceBack("2");
	values.EmplaceBack("3");
	values.EmplaceBack("Willy");
	values.EmplaceBack("4");
	values.EmplaceBack("5");

	std::cout << "Not using iterators:\n";
	for (int i = 0; i < values.Size(); i++)
	{
		std::cout << values[i] << std::endl;
	}

	std::cout << "Range-based for loop:\n";
	for (auto& value : values)
		std::cout << value << std::endl;

	std::cout << "Iterator:\n";
	for (Vector<std::string>::Iterator it = values.begin();
		it != values.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	////Using Array.
	//Array<std::string, 2> data;
	//data[0] = "Kyle";
	//data[1] = "Pearce";

	///*for (size_t i = 0; i < data.Size(); i++)
	//{
	//	std::cout << data[i] << std::endl;
	//}*/

	//{
	//	//Using Vector.
	//	Vector<Vector3> vector;
	//	vector.EmplaceBack(1.0f);
	//	vector.EmplaceBack(2, 3, 4);
	//	vector.EmplaceBack(1, 3, 4);
	//	vector.EmplaceBack();
	//	PrintVector(vector);
	//	vector.PopBack();
	//	vector.PopBack();
	//	PrintVector(vector);
	//	vector.EmplaceBack(5, 3, 0);
	//	vector.EmplaceBack(1, 7, 9);
	//	PrintVector(vector);

	//	vector.Clear();
	//	PrintVector(vector);
	//	vector.EmplaceBack(5, 3, 0);
	//	vector.EmplaceBack(1, 7, 9);
	//	PrintVector(vector);
	//}

	//Vector<int> intVector;
	//intVector.PushBack(5);
	//intVector.EmplaceBack(2);
	//intVector.EmplaceBack(2);
	//intVector.EmplaceBack(2);
	//intVector.EmplaceBack(2);
	//intVector.EmplaceBack(2);
	//PrintVector(intVector);
	//intVector.PopBack();
	//PrintVector(intVector);
	//intVector.Clear();

	std::cout << std::endl;
	std::cout << "Press enter to close application..." << std::endl;
	std::cin.get();
}