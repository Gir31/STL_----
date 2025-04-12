//------------------------------------------------------------------------
// 2025.04.01 STL ȭ78											 (5�� 1��)
// �߰���� - 4�� 24�� ����� (8�� 2��)
// �������� - 4�� 10�� �����
//------------------------------------------------------------------------
// class STRING - STL ���� �����̳�ó�� �����ϴ� �ڷᱸ��
//------------------------------------------------------------------------
// ������ ȯ���� �̷��� �����ּ���
// VS ���� - 17.3.0 ����
// Release / x64, C++ ��� ǥ�� - /std::C++latest, SDL�˻� - �ƴϿ� 
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

// ǥ�� std::string�� ������ ������ �ϴ� Ŭ����
class STRING {
public:

	// ����Ʈ�� �ݵ�� �ڵ�

	STRING(const char* s) : len{ strlen(s) } {
		p.reset();
		p = make_unique<char[]>(len); // p�� �ڿ��� Ȯ���ϰ� �Ѵ�.
		memcpy(p.get(), s, len);
	}

	STRING(const STRING& other) : len{ other.len } {
		p.reset();
		p = make_unique<char[]>(len);
		memcpy(p.get(), other.p.get(), len);
	}

	// copy assignment operator �� �ݵ�� �ڵ��ؾ� �Ѵ�.

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
	STRING s{ "std::string�� ������ Ŭ����" };

	STRING t = s;

	cout << s << endl;
	cout << t << endl;


	save("0403.cpp");
}




//==============================================================
// �������� : sort(dogs.begin(), dogs.end());
// bool operator<( const Dog& other ) const {
// return name.size() < other.name.size();
//		}

// �������� : sort(dogs.begin(), dogs.end(), greater<>());
// bool operator>( const Dog& other ) const {
// return name.size() > other.name.size();
//		}

// && : r-value ���۷���

// oop -> Ư�� type�� ���� coding star
// generic -> Ÿ�԰� ������

// lvalue : location value
// unique : �ڿ��� �����Ѵ�