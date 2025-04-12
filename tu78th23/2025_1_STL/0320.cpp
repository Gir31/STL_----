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

	friend std::istream& operator>>(std::istream& is, const Dog& dog) {
		return is.read((char*)&dog, sizeof(Dog));
	}
};

// [문제] Dog 객체 10만개를 binary 모드로 연 파일 "Dog 10만마리"에 저장하였다.
// 출력 연산자 << 를 사용하여 저장하였다.
// 함수는 다음과 같다.
//	friend std::ostream& operator<<(std::ostream& os, Dog& dog) {
//		os.write((char*)&dog, sizeof(Dog));
//		return os;
//	}


std::array<Dog, 100000> dogs;

//--------
int main()
//--------
{
	std::ifstream in{ "Dog 10만마리" , std::ios::binary };
	if (not in)
		exit(20250320);

	// [문제] 한 번에 메모리에 읽어온다.
	
	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs)
		std::cout << dog << std::endl;
	
	save("0320.cpp");
}


// open mode
// low-level의 속도가 굉장히 빠르다
// binary -> high-level ( >>, << )
// text -> low-level (read(), write())