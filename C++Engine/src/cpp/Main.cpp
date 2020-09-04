#include <iostream>

template<typename T, size_t S>
class Array
{
public:
	constexpr size_t Size() const { return S; }

	T& operator[](size_t index) { return m_Data[index]; }
	const T& operator[](size_t index) const { return m_Data[index]; }

	T* Data() { return m_Data; }
	const T* Data() const { return m_Data; }
private:
	T m_Data[S];
};

int main()
{
	int size = 5;
	Array<std::string, 2> data;
	data[0] = "Kyle";
	data[1] = "Pearce";

	for (size_t i = 0; i < data.Size(); i++)
	{
		std::cout << data[i] << std::endl;
	}

	std::cout << std::endl;
	std::cout << "Press enter to close application..." << std::endl;
	std::cin.get();
}