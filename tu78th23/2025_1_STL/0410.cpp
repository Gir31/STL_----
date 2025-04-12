//------------------------------------------------------------------------
// 2025.04.10													
// 중간고사 - 4월 24일 목요일 (8주 2일)
// 과제설명 - 4월 10일 목요일
//------------------------------------------------------------------------
// class STRING - STL 정식 컨테이너처럼 동작하는 자료구조
//------------------------------------------------------------------------
// 컴파일 환경은 이렇게 맞춰주세요
// VS 버젼 - 17.3.0 이후
// Release / x64, C++ 언어 표준 - /std::C++latest, SDL검사 - 아니요 
//------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include "STRING.h"
#include "save.h"
using namespace std;

extern bool 관찰;

// [문제] "0410.cpp"에 있는 단어(공백으로 분리된 char의 집합)를 모두 메모리에 저장하라.
// 단어를 50개만 읽는다.
// 단어를 길이기준 오름차순으로 정렬하라.
// 정렬한 단어를 모두 출력하라.

array<STRING, 50 > words;

//--------
int main()
//--------
{
	STRING s;

	ifstream in{ "0410.cpp" };
	if (not in)
		return 20250410;
	
	for (STRING& word : words)
		in >> word;

	std::sort(words.begin(), words.end());			// 기본 정렬 -> < 또는 less{}를 이용

	for (const STRING& word : words)
		cout << word << endl;

	save("0410.cpp");
}

// cout << s << endl; -> xvalue를 사용하는 코드의 결과는 정의되어 있지 않음