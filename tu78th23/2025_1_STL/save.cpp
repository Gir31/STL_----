//---------------------------------------------------------
// save.cpp										2025.03.11
// 
// �� �б� ���Ǹ�  �����Ѵ�.
//---------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <chrono>

//----------------------------------
void save(std::string_view fileName)
//----------------------------------
{
	// ���� fileName�� ����
	std::ifstream in{ fileName.data() }; // data()�� const char*�� ��ȯ����
	if (not in) { // !in �� �ƴ� not in ���� ������
		std::cout << fileName << "�� �� �� �����ϴ�." << std::endl;
		exit(20250306);
	}

	// ������ ���ϵ� ����� �Ѵ�
	std::string writeFile{ "2025 1�б� STL ȭ78��23 ��������.txt" };
	std::ofstream out{ writeFile, std::ios::app };

	// ���������� ȭ�鿡 �������
	std::cout << writeFile << "�� " << fileName << "�� ���ٿ����ϴ� - " 
		<< std::filesystem::file_size(fileName) << " bytes" << std::endl;

	// ������ �ð��� ���Ͽ� �������
	auto now = std::chrono::system_clock::now(); // time_point�� ��´�
	auto utc = std::chrono::system_clock::to_time_t(now); // time_point�� UTC�ð����� ����
	auto lt = std::localtime(&utc); // �����ð����� ����
	auto old = out.imbue(std::locale("ko_KR")); // out�� ������ �ѱ�����

	out << '\n' << '\n';
	out << "================================" << '\n';
	out << "������ �ð� : " << std::put_time(lt, "%c %A") << '\n';
	out << "================================" << '\n';
	out << '\n';
	out.imbue(old);

	// ���� ������ ������ �о ������ ���Ͽ� �����δ�
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
}