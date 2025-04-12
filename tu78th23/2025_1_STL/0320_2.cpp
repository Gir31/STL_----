//------------------------------------------------------------------------
// 2025.03.20 STL 목23											 (3주 2일)
//------------------------------------------------------------------------
// 강의 소개 / 많은 개수 자료를 처리하기 - 파일 입출력
//										 - 객체를 
//										 - 바이너리 모드와 저수준 입출력
//------------------------------------------------------------------------
// 컴파일 환경은 이렇게 맞춰주세요
// VS 버젼 - 17.3.0 이후
// Release / x64, C++ 언어 표준 - /std::C++latest, SDL검사 - 아니요 
//------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include "save.h"

class Dog {
private:
	std::string name;
	int id;

	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.id << "\t" << dog.name;
	}
};

// [문제] Dog 객체 10만개를 binary 모드로 연 파일 "Dog 10만마리"에 저장하였다.
// 파일의 write함수를 사용하여 객체 메모리 전체를 그대로 저장하였다.
// 파일을 있는 객체 전체를 메모리로 읽어와라.
// name과 id를 화면에 출력하라

std::array<Dog, 100000> dogs;

//--------
int main()
//--------
{
	std::ifstream in{ "Dog 10만마리" , std::ios::binary };
	if (not in)
		exit(20250320);

	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs)
		std::cout << dog << std::endl;

	save("0320.cpp");
}
