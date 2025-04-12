//------------------------------------------------------------------------
// 2025.04.01 STL 화78											 (5주 1일)
// 중간고사 - 4월 24일 목요일 (8주 2일)
// 과제설명 - 4월 10일 목요일
//------------------------------------------------------------------------
// callable types - 호출가능한 타입 -> 모든 호출 가능 타입을 나타낼 수 있는 function
// 1. 함수
// 2. 함수 포인터
// 3. 람다 - 이름없는 함수
// 4. 함수객체 - 함수 호출 연산자를 오버로딩한 클래스로 만든 객체 (function object)
// 5. 멤버함수 
//------------------------------------------------------------------------
// 컴파일 환경은 이렇게 맞춰주세요
// VS 버젼 - 17.3.0 이후
// Release / x64, C++ 언어 표준 - /std::C++latest, SDL검사 - 아니요 
//------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include "save.h"

using namespace std;

class Dog {
public:
	
private:
	string name; // [3, 50] 사이의 랜덤 소문자로만 구성
	int num; // 랜덤 int 값으로 구성

	friend ostream& operator <<(ostream& os, const Dog& dog) {
		return os << dog.num << " " << dog.name << " ";
	}
	/*friend istream& operator >> (istream& is, const Dog& dog) {
		return is.read((char*)&dog, sizeof(Dog));
	}*/
};

// [상황] Dog 객체 10만개를 파일 "Dog 십만마리" 에 기록하였다.
// 파일은 다음과 같이 열었다.
//		ofstream out("Dog 십만마리");
// 각 Dog 객체는 
//		out << dog; 와 같이 기록하였다.
// [문제] 틀림없이 Dog 10만마리 객체가 기록되었다.
// 파일 "Dog 십만마리"를 열어 모든 Dog 객체를 메모리에 저장하라
// 제일 마지막 객체의 정보를 화면에 출력하고 답지에도 출력결과를 적어라.
// 메모리에 저장한 Dog 객체를 name 길이기준 오름차순으로 정렬하라
// 앞에서부터 5000개의 정보를 화면에 출력하라.

//bool Dog(int a, int b) 
//{
//	return a > b;
//}

//--------
int main()
//--------
{
	ifstream in{ "Dog 십만마리" };
	if (not in)
		return 20250401;

	array<Dog, 10'0000> dog;

	in.read((char*)dog.data(), dog.size() * sizeof(Dog));

	for (Dog d : dog) {
		cout << d << endl;
	}

	//array<int, 10> a{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	// [문제] 내림차순 정렬할 수 있게 하라

	/*auto Dog = [](int a, int b) {
		return a > b;
		};*/

	//function<bool(int, int)> Dog = X::operator();


	//sort(a.begin(), a.end(), Dog);

	/*for (int num : a) {
		cout << num << " ";
	}
	cout << endl;*/

	/*for (int i = 0; i < 10'0000; ++i) {
		Dog dog;
		out << dog;
	}*/


	save("0401.cpp");
}