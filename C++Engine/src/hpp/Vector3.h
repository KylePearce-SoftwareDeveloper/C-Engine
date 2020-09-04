#pragma once
class Vector3
{
public:
	float x = 0.0f, y = 0.0f, z = 0.0f;
	int* m_MemoryBlock = nullptr;

	Vector3() { m_MemoryBlock = new int[5]; }
	Vector3(float scalar)
		: x(scalar), y(scalar), z(scalar) {
		m_MemoryBlock = new int[5];
	}
	Vector3(float x, float y, float z)
		: x(x), y(y), z(z) {
		m_MemoryBlock = new int[5];
	}

	Vector3(const Vector3& other) = delete;

	Vector3(Vector3&& other)
		: x(other.x), y(other.y), z(other.z)
	{
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		//std::cout << "Move\n";
	}

	~Vector3()
	{
		//std::cout << "Destroy\n";
		delete[] m_MemoryBlock;
	}

	Vector3& operator=(const Vector3& other) = delete;

	Vector3& operator=(Vector3&& other)
	{
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		//std::cout << "Move\n";
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
};
