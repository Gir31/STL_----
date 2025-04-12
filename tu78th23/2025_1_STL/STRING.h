//------------------------------------------------------------------------------------
// STRING.h - std::string과 유사한 클래스
//			  STL의 동작을 깊게 들여다 보기 위해...
// 
//																			2025.04.08
//------------------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <memory>

class STRING {
public:
	STRING();
	STRING(const char* s);
	~STRING();						// 전혀 작성할 필요가 없는 함수인데
									// 관찰하려고 코딩하였다.

	// 복사생성과 복사할당연산자
	STRING(const STRING& other);
	STRING& operator=(const STRING&);

	// 이동생성과 이동할당연산
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	// 연산자들
	bool operator<(const STRING& other);

	size_t size() const;

private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	size_t id;						// 생성시 부여되는 고유값

	static size_t gid;

	friend std::ostream& operator << (std::ostream& os, const STRING& str);
	friend std::istream& operator >> (std::istream& is, STRING& str);
};