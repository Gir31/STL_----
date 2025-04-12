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
#include <random>
#include <array> // STL sequence container 중 하나
#include <print>
#include <algorithm> // 여기있는 걸 기능을 코딩하면 안된다
#include <fstream>
#include "save.h"
// [문제] 랜덤 int 값 1000개를 생성하여 메모리에 저장하라
// 저장된 값 중에 가장 큰 값을 찾아라
// 찾은 값을 화면에 출력하라. 출력값을 8칸에 맞춰라
// pseudo - 가짜 (알아두자)
// 컴퓨터에서 만들어내는 random 데이터는 수식에 의해 만들기 때문에 예측가능하다

std::default_random_engine dre{ }; // 랜덤 엔진
std::uniform_int_distribution uid{ 0, 999'9999 }; // 엔진의 결과값을 특정 분포로 가공
// uniform 데이터를 쭉 늘어나도록 가공


//--------
int main()
//--------
{
	std::array<int, 1000> a;

	for (int i = 0; i < 1000; ++i) a[i] = uid(dre);

	// 가장 큰 값을 찾기

	std::cout << "최댓값 - " << *std::max_element(a.begin(), a.end()) << std::endl;

	// [문제] a에 있는 값을 파일 "int 1000개.txt"에 텍스트 그대로 저장하라
	// 화면 출력한 것과 같은 형태로 - 파일을 열었을 때 int값을 사람이 읽을 수 있도록

	std::ofstream out{ "int 1000개.txt"}; //RAII
	int i{ 0 };
	for (int num : a) {
		std::print(out, "{:8}", num);
		if (not(++i % 8))
			out << std::endl;
	}

	save("0313.cpp");
}