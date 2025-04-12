//------------------------------------------------------------------------
// 2025.03.20 STL ��23											 (3�� 2��)
//------------------------------------------------------------------------
// ���� �Ұ� / ���� ���� �ڷḦ ó���ϱ� - ���� �����
//										 - ��ü�� 
//										 - ���̳ʸ� ���� ������ �����
//------------------------------------------------------------------------
// ������ ȯ���� �̷��� �����ּ���
// VS ���� - 17.3.0 ����
// Release / x64, C++ ��� ǥ�� - /std::C++latest, SDL�˻� - �ƴϿ� 
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

// [����] Dog ��ü 10������ binary ���� �� ���� "Dog 10������"�� �����Ͽ���.
// ��� ������ << �� ����Ͽ� �����Ͽ���.
// �Լ��� ������ ����.
//	friend std::ostream& operator<<(std::ostream& os, Dog& dog) {
//		os.write((char*)&dog, sizeof(Dog));
//		return os;
//	}


std::array<Dog, 100000> dogs;

//--------
int main()
//--------
{
	std::ifstream in{ "Dog 10������" , std::ios::binary };
	if (not in)
		exit(20250320);

	// [����] �� ���� �޸𸮿� �о�´�.
	
	in.read((char*)dogs.data(), dogs.size() * sizeof(Dog));

	for (const Dog& dog : dogs)
		std::cout << dog << std::endl;
	
	save("0320.cpp");
}


// open mode
// low-level�� �ӵ��� ������ ������
// binary -> high-level ( >>, << )
// text -> low-level (read(), write())