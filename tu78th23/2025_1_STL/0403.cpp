//------------------------------------------------------------------------
// 2025.04.01 STL 화78											 (5주 1일)
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
#include <print>
#include <algorithm>
#include <ranges>
#include <memory>
#include "save.h"

using namespace std;

// 표준 std::string과 유사한 동작을 하는 클래스
class STRING {
public:

	// 디폴트를 반드시 코딩

	STRING(const char* s) : len{ strlen(s) } {
		p.reset();
		p = make_unique<char[]>(len); // p가 자원을 확보하게 한다.
		memcpy(p.get(), s, len);
	}

	STRING(const STRING& other) : len{ other.len } {
		p.reset();
		p = make_unique<char[]>(len);
		memcpy(p.get(), other.p.get(), len);
	}

	// copy assignment operator 를 반드시 코딩해야 한다.

	size_t size() const {
		return len;
	}

private:
	size_t len;
	unique_ptr<char[]> p;


	friend ostream& operator << (ostream & os, const STRING& str) {
		for (int i = 0; i < str.len; ++i)
			os << str.p[i];
		return os;
	}
};

//--------
int main()
//--------
{
	STRING s{ "std::string과 유사한 클래스" };

	STRING t = s;

	cout << s << endl;
	cout << t << endl;


	save("0403.cpp");
}




//==============================================================
// 오름차순 : sort(dogs.begin(), dogs.end());
// bool operator<( const Dog& other ) const {
// return name.size() < other.name.size();
//		}

// 내림차순 : sort(dogs.begin(), dogs.end(), greater<>());
// bool operator>( const Dog& other ) const {
// return name.size() > other.name.size();
//		}

// && : r-value 레퍼런스

// oop -> 특정 type을 위한 coding star
// generic -> 타입과 무관한

// lvalue : location value
// unique : 자원을 독점한다