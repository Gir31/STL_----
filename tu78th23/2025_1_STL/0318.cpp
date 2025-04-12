//------------------------------------------------------------------------
// 2025.03.13 STL 목23											 (2주 2일)
//------------------------------------------------------------------------
// 강의 소개 / 많은 개수 자료를 처리하기 - 파일 입출력
//										 - 바이너리 모드와 저수준 입출력
//------------------------------------------------------------------------
// 컴파일 환경은 이렇게 맞춰주세요
// VS 버젼 - 17.3.0 이후
// Release / x64, C++ 언어 표준 - /std::C++latest, SDL검사 - 아니요 
//------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include "save.h"
// [문제] e-class에서 다운 받은 "진짜 랜덤" 파일에는 int 값 100000개가 있다.
// 파일은 binary mode로 오픈하였고 write 함수를 사용하여 int값을 기록하였다.
// int값 10만개를 메모리로 읽어와라
// 가장 큰 값과 가장 작은 값을 찾아 화면에 출력하라.
// 출력된 값도 답지에 적어라

//--------
int main()
//--------
{
	std::ifstream in{ "진짜 랜덤", std::ios::binary };
	if (not in)
		exit(20250318);

	std::array<int, 100000> a;
	in.read((char*)a.data(), a.size() * sizeof(int));

	auto [minPos, maxPos] = std::minmax_element(a.begin(), a.end()); //std::pair
	// [] structured binding
	std::cout << "최솟값 - " << *minPos << std::endl;
	std::cout << "최댓값 - " << *maxPos << std::endl;

	save("0318.cpp");
}

// 꼭 외울 것! : 시간의 연속성 (continuous), 공간의 연속성 (contiguous)
// 메모리를 저장할때 뒤에서부터 저장하는 방식  - Little endian