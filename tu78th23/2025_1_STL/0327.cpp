//------------------------------------------------------------------------
// 2025.03.25 STL 화78											 (4주 1일)
//------------------------------------------------------------------------
// callable types - 호출가능한 타입
// 1. 함수
// 2. 함수 포인터
// 3. 람다 - 이름없는 함수
//------------------------------------------------------------------------
// 컴파일 환경은 이렇게 맞춰주세요
// VS 버젼 - 17.3.0 이후
// Release / x64, C++ 언어 표준 - /std::C++latest, SDL검사 - 아니요 
//------------------------------------------------------------------------
#include <iostream>
#include <algorithm>
#include <array>
#include <random>
#include <print>
#include <ranges>
#include <chrono>
#include "save.h"

// [문제] 랜덤 int 1000만개를 메모리에 저장하라.
// STL의 sort를 사용하여 정렬하라.
// 정렬결과를 앞에서부터 1000개를 화면 출력하라

std::default_random_engine dre;
std::uniform_int_distribution uid{0, 999'9999};


const int NUM{ 1000'0000 };
std::array<int, NUM> a;

bool 오름차순(int a, int b)
{
	return a < b;
}
bool 내림차순(int a, int b)
{
	return a > b;
}

//--------
int main()
//--------
{
	auto 람다 = []() {
		std::cout << "람다" << std::endl;
		};

	std::cout << "람다의 정체" << std::endl;
	std::cout << "람다의 크기 - " << sizeof(람다) << std::endl;
	std::cout << "람다의 위치 - " << std::addressof(람다) << std::endl;
	std::cout << "람다의 타입 - " << typeid(람다).name() << std::endl;

	std::cout << std::endl;


	std::cout << "main의 위치 - " << std::addressof(main) << std::endl;
	{
		for (int& num : a)
			num = uid(dre);

		// 스톱워치 시작
		auto b = std::chrono::high_resolution_clock::now();
		std::sort(a.begin(), a.end(), 오름차순);
		auto e = std::chrono::high_resolution_clock::now();
		// 스톱워치 끝

		std::cout << "걸린 시간 - " << e - b << std::endl;
	}

	{
		for (int& num : a)
			num = uid(dre);

		// 스톱워치 시작
		auto b = std::chrono::high_resolution_clock::now();
		std::sort(a.begin(), a.end(), [](int a, int b) {
			return a < b;
			});
		auto e = std::chrono::high_resolution_clock::now();
		// 스톱워치 끝

		std::cout << "걸린 시간 - " << e - b << std::endl;
	}

	save("0327.cpp");
}

 //std::views::takes : 거르는 기능
 //int a[100]; -> std::array<int, 100> a;
 //int(*메인)() = main; -> 
 //sort 함수는 default로 오름차순으로 되어있다.