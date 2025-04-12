//------------------------------------------------------------------------------------
// STRING.cpp - std::string과 유사한 클래스
//			  STL의 표준 컨테이너로서 동작할 수 있도록
// 
//																			2025.04.08
//------------------------------------------------------------------------------------
#include <iostream>
#include <memory>
#include <print>
#include <string>
#include "STRING.h"

bool 관찰{false};
size_t STRING::gid{ 0 };

STRING::STRING()
	: id{++gid}
{
	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "default 생성자", len, (void*)this, (void*)p.get());
	}
}

STRING::~STRING()
{
	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "소멸자", len, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const char* s)
	: id{++gid}, len { strlen(s) }
{
	p.reset();
	p = std::make_unique<char[]>(len); // p가 자원을 확보하게 한다.
	memcpy(p.get(), s, len);

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "생성자(char*)", len, (void*)this, (void*)p.get());
	}
}

STRING::STRING(const STRING& other)
	: id{ ++gid }, len{ other.len }
{
	p.reset();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "복사생성자", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(const STRING& other)
{
	if (this == &other)
		return *this;

	len = other.len;
	p.release();
	p = std::make_unique<char[]>(len);
	memcpy(p.get(), other.p.get(), len);

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "복사 operator=", len, (void*)this, (void*)p.get());
	}

	return *this;
}

// 이동생성과 이동할당연산
STRING::STRING(STRING&& other)
	: id{++gid}, len{other.len}
{
	p.reset(other.p.release());
	other.len = 0;

	if (관찰) {
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}",
			id, "이동생성자", len, (void*)this, (void*)p.get());
	}
}

STRING& STRING::operator=(STRING&& other)
{
	if (this == &other)
		return *this;

	len = other.len; 
	p.reset(other.p.release());
	other.len = 0;

	if (관찰) { 
		std::println("[{:8}] - {:<20} 자원수:{:<6} 주소:{:>16}, 자원의 주소:{:>16}", 
			id, "이동 operator=", len, (void*)this, (void*)p.get()); 
	} 

	return *this;
}

bool STRING::operator<(const STRING& other)
{
	return size() < other.size();
}

size_t STRING::size() const 
{ 
	return len;
}

std::ostream& operator << (std::ostream& os, const STRING& str) 
{
	for (int i = 0; i < str.len; ++i)
		os << str.p[i];
	return os;
}

std::istream& operator >> (std::istream& is, STRING& str)
{
	std::string s;

	is >> s;

	str.p.release( );
	str.p = std::make_unique<char[]>( s.size( ) );
	str.len = s.size( );

	memcpy(str.p.get( ), s.data( ), str.len);

	return is;
}