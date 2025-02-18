﻿#include<iostream>

using namespace std;

template <typename T, int size>
class StaticArray_BASE
{
private:
	T m_array[size];

public:
	T *getArray()
	{
		return m_array;
	}

	T &operator [] (int index)
	{
		return m_array[index];
	}

	void print()
	{
		for (int count = 0; count < size; count++)
		{
			cout << (*this)[count] << ' ';
		}
		cout << endl;
	}
};

template <typename T, int size>
class StaticArray : public StaticArray_BASE<T, size>
{

};

template <int size>
class StaticArray<char,size> : public StaticArray_BASE<char, size> // 문자열부분만 특수화 // print함수 오버라이딩
{
public:
	void print()
	{
		for (int count = 0; count < size; count++)
		{ 
			cout << (*this)[count];
		}
		cout << endl;
	}
};

int main()
{
	StaticArray<int, 4> int4;

	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.print();

	StaticArray<char, 14> char14;

	strcpy_s(char14.getArray(), 14, "Hello, World");

	char14.print();

	return 0;
}