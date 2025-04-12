//------------------------------------------------------------------------
// 2025.03.11 STL 화78											 (2주 1일)
//------------------------------------------------------------------------
// save 파일 분리 / Generic Programming의 핵심 - tamplate
//------------------------------------------------------------------------
// 컴파일 환경은 이렇게 맞춰주세요
// VS 버젼 - 17.3.0 이후
// Release / x64, C++ 언어 표준 - /std::C++latest, SDL검사 - 아니요 
//------------------------------------------------------------------------
// C++ 에서 사용하지 말하야할 것
// 1. char* (문자열)(X) -> string -> string_view
// 2. T*(X) -> unique_ptr<T>, shared_ptr<T>
// 3. T[N] (X) -> array<T, N>

#include <iostream>
#include "save.h"
//using namespace std; // 절대 이렇게 하지 말자

// [문제] main을 수정하면 안됨. 의도대로 실행되게 하자

class Dog {
public:
	Dog() = default;
	Dog(int n) : num{ n } {}
	
	//operator int() {
	//	return num;
	//} 
	// 간단하지만 사용하지 않는게 나은 코드다. 
private:
	int num{ };
	
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.num;
	}
};

// [질문] C++에서 change를 몇 개나 만들어야 하나?
// -- C++ 언어의 자료형은 몇 개나 있나? a. 자료형은 무한하다. -> 소스코드를 자동 생성하자
// C++ template
// template은 선언과 정의를 분리하지 않는다.
template <class T>
void change(T& a, T& b) {
	T temp{ a }; // 복사 생성자는 매우 특별한 동작, 프로그래머가 코딩하지않아도 만들어준다
	a = b; // 원래는 a.operator = (b);라는 함수인데 이것 또한 간단하게 만들어준다
	b = temp;
}

//---------
int main()
//---------
{
	{
		Dog a{ 1 }, b{ 2 };
		change(a, b);
		std::cout << a << ", " << b << std::endl; // 의도 - 2, 1 출력
	}


	{
		int a{ 1 }, b{ 2 };
		change(a, b);
		std::cout << a << ", " << b << std::endl; // 의도 - 2, 1 출력
	}

	save("0311.cpp");
}
