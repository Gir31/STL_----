//------------------------------------------------------------------------
// 2025.03.13 STL 목23											 (2주 2일)
//------------------------------------------------------------------------
// 강의 소개 / 많은 개수 자료를 처리하기 - FILE에 저장하고 읽어오기
//------------------------------------------------------------------------
// 컴파일 환경은 이렇게 맞춰주세요
// VS 버젼 - 17.3.0 이후
// Release / x64, C++ 언어 표준 - /std::C++latest, SDL검사 - 아니요 
//------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <print>
#include <algorithm>
#include "save.h"
// [문제] 파일 "int 1000개.txt"에는 int값 1000개가 text mode로 기록되어 있다.
// 가장 큰 값을 찾아 화면에 출력하라.

//--------
int main()
//--------
{
	std::ifstream in{ "int 1000개.txt" };
	if (not in)
		return 20250313;

	int num;
	int maxValue{ std::numeric_limits<int>::min() };
	
	auto pos = std::min_element(std::istream_iterator<int>{in}, {});

	std::cout << "최솟값 - " << *pos << std::endl;

	save("0313.cpp");
}