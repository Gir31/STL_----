//------------------------------------------------------------------------
// 2025.03.25 STL ȭ78											 (4�� 1��)
//------------------------------------------------------------------------
// callable types - ȣ�Ⱑ���� Ÿ��
// 1. �Լ�
// 2. �Լ� ������
// 3. ���� - �̸����� �Լ�
//------------------------------------------------------------------------
// ������ ȯ���� �̷��� �����ּ���
// VS ���� - 17.3.0 ����
// Release / x64, C++ ��� ǥ�� - /std::C++latest, SDL�˻� - �ƴϿ� 
//------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <print>
#include <ranges>
#include <chrono>
#include "save.h"

// [����] ���� int 1000������ �޸𸮿� �����϶�.
// STL�� sort�� ����Ͽ� �����϶�.
// ���İ���� �տ������� 1000���� ȭ�� ����϶�

std::default_random_engine dre;
std::uniform_int_distribution uid{0, 999'9999};


const int NUM{ 1000'0000 };
std::array<int, NUM> a;

bool ��������(int a, int b)
{
	return a < b;
}
bool ��������(int a, int b)
{
	return a > b;
}

//--------
int main()
//--------
{
	auto ���� = []() {
		std::cout << "����" << std::endl;
		};

	std::cout << "������ ��ü" << std::endl;
	std::cout << "������ ũ�� - " << sizeof(����) << std::endl;
	std::cout << "������ ��ġ - " << std::addressof(����) << std::endl;
	std::cout << "������ Ÿ�� - " << typeid(����).name() << std::endl;

	std::cout << std::endl;


	std::cout << "main�� ��ġ - " << std::addressof(main) << std::endl;
	{
		for (int& num : a)
			num = uid(dre);

		// �����ġ ����
		auto b = std::chrono::high_resolution_clock::now();
		std::sort(a.begin(), a.end(), ��������);
		auto e = std::chrono::high_resolution_clock::now();
		// �����ġ ��

		std::cout << "�ɸ� �ð� - " << e - b << std::endl;
	}

	{
		for (int& num : a)
			num = uid(dre);

		// �����ġ ����
		auto b = std::chrono::high_resolution_clock::now();
		std::sort(a.begin(), a.end(), [](int a, int b) {
			return a < b;
			});
		auto e = std::chrono::high_resolution_clock::now();
		// �����ġ ��

		std::cout << "�ɸ� �ð� - " << e - b << std::endl;
	}

	save("0327.cpp");
}

 //std::views::takes : �Ÿ��� ���
 //int a[100]; -> std::array<int, 100> a;
 //int(*����)() = main; -> 
 //sort �Լ��� default�� ������������ �Ǿ��ִ�.