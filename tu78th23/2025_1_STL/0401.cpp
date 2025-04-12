//------------------------------------------------------------------------
// 2025.04.01 STL ȭ78											 (5�� 1��)
// �߰���� - 4�� 24�� ����� (8�� 2��)
// �������� - 4�� 10�� �����
//------------------------------------------------------------------------
// callable types - ȣ�Ⱑ���� Ÿ�� -> ��� ȣ�� ���� Ÿ���� ��Ÿ�� �� �ִ� function
// 1. �Լ�
// 2. �Լ� ������
// 3. ���� - �̸����� �Լ�
// 4. �Լ���ü - �Լ� ȣ�� �����ڸ� �����ε��� Ŭ������ ���� ��ü (function object)
// 5. ����Լ� 
//------------------------------------------------------------------------
// ������ ȯ���� �̷��� �����ּ���
// VS ���� - 17.3.0 ����
// Release / x64, C++ ��� ǥ�� - /std::C++latest, SDL�˻� - �ƴϿ� 
//------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <array>
#include "save.h"

using namespace std;

class Dog {
public:
	
private:
	string name; // [3, 50] ������ ���� �ҹ��ڷθ� ����
	int num; // ���� int ������ ����

	friend ostream& operator <<(ostream& os, const Dog& dog) {
		return os << dog.num << " " << dog.name << " ";
	}
	/*friend istream& operator >> (istream& is, const Dog& dog) {
		return is.read((char*)&dog, sizeof(Dog));
	}*/
};

// [��Ȳ] Dog ��ü 10������ ���� "Dog �ʸ�����" �� ����Ͽ���.
// ������ ������ ���� ������.
//		ofstream out("Dog �ʸ�����");
// �� Dog ��ü�� 
//		out << dog; �� ���� ����Ͽ���.
// [����] Ʋ������ Dog 10������ ��ü�� ��ϵǾ���.
// ���� "Dog �ʸ�����"�� ���� ��� Dog ��ü�� �޸𸮿� �����϶�
// ���� ������ ��ü�� ������ ȭ�鿡 ����ϰ� �������� ��°���� �����.
// �޸𸮿� ������ Dog ��ü�� name ���̱��� ������������ �����϶�
// �տ������� 5000���� ������ ȭ�鿡 ����϶�.

//bool Dog(int a, int b) 
//{
//	return a > b;
//}

//--------
int main()
//--------
{
	ifstream in{ "Dog �ʸ�����" };
	if (not in)
		return 20250401;

	array<Dog, 10'0000> dog;

	in.read((char*)dog.data(), dog.size() * sizeof(Dog));

	for (Dog d : dog) {
		cout << d << endl;
	}

	//array<int, 10> a{1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
	// [����] �������� ������ �� �ְ� �϶�

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