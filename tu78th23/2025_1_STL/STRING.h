//------------------------------------------------------------------------------------
// STRING.h - std::string�� ������ Ŭ����
//			  STL�� ������ ��� �鿩�� ���� ����...
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
	~STRING();						// ���� �ۼ��� �ʿ䰡 ���� �Լ��ε�
									// �����Ϸ��� �ڵ��Ͽ���.

	// ��������� �����Ҵ翬����
	STRING(const STRING& other);
	STRING& operator=(const STRING&);

	// �̵������� �̵��Ҵ翬��
	STRING(STRING&&);
	STRING& operator=(STRING&&);

	// �����ڵ�
	bool operator<(const STRING& other);

	size_t size() const;

private:
	size_t len{};
	std::unique_ptr<char[]> p{};
	size_t id;						// ������ �ο��Ǵ� ������

	static size_t gid;

	friend std::ostream& operator << (std::ostream& os, const STRING& str);
	friend std::istream& operator >> (std::istream& is, STRING& str);
};