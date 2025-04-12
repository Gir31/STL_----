//------------------------------------------------------------------------
// 2025.03.11 STL ȭ78											 (2�� 1��)
//------------------------------------------------------------------------
// save ���� �и� / Generic Programming�� �ٽ� - tamplate
//------------------------------------------------------------------------
// ������ ȯ���� �̷��� �����ּ���
// VS ���� - 17.3.0 ����
// Release / x64, C++ ��� ǥ�� - /std::C++latest, SDL�˻� - �ƴϿ� 
//------------------------------------------------------------------------
// C++ ���� ������� ���Ͼ��� ��
// 1. char* (���ڿ�)(X) -> string -> string_view
// 2. T*(X) -> unique_ptr<T>, shared_ptr<T>
// 3. T[N] (X) -> array<T, N>

#include <iostream>
#include "save.h"
//using namespace std; // ���� �̷��� ���� ����

// [����] main�� �����ϸ� �ȵ�. �ǵ���� ����ǰ� ����

class Dog {
public:
	Dog() = default;
	Dog(int n) : num{ n } {}
	
	//operator int() {
	//	return num;
	//} 
	// ���������� ������� �ʴ°� ���� �ڵ��. 
private:
	int num{ };
	
	friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
		return os << dog.num;
	}
};

// [����] C++���� change�� �� ���� ������ �ϳ�?
// -- C++ ����� �ڷ����� �� ���� �ֳ�? a. �ڷ����� �����ϴ�. -> �ҽ��ڵ带 �ڵ� ��������
// C++ template
// template�� ����� ���Ǹ� �и����� �ʴ´�.
template <class T>
void change(T& a, T& b) {
	T temp{ a }; // ���� �����ڴ� �ſ� Ư���� ����, ���α׷��Ӱ� �ڵ������ʾƵ� ������ش�
	a = b; // ������ a.operator = (b);��� �Լ��ε� �̰� ���� �����ϰ� ������ش�
	b = temp;
}

//---------
int main()
//---------
{
	{
		Dog a{ 1 }, b{ 2 };
		change(a, b);
		std::cout << a << ", " << b << std::endl; // �ǵ� - 2, 1 ���
	}


	{
		int a{ 1 }, b{ 2 };
		change(a, b);
		std::cout << a << ", " << b << std::endl; // �ǵ� - 2, 1 ���
	}

	save("0311.cpp");
}
