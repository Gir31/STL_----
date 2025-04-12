//---------------------------------------------------------
// save.cpp										2025.03.11
// 
// 한 학기 강의를  저장한다.
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
	// 파일 fileName을 연다
	std::ifstream in{ fileName.data() }; // data()는 const char*로 변환해줌
	if (not in) { // !in 이 아닌 not in 으로 적을것
		std::cout << fileName << "을 열 수 없습니다." << std::endl;
		exit(20250306);
	}

	// 저장할 파일도 열어야 한다
	std::string writeFile{ "2025 1학기 STL 화78목23 강의저장.txt" };
	std::ofstream out{ writeFile, std::ios::app };

	// 저장했음을 화면에 출력하자
	std::cout << writeFile << "에 " << fileName << "을 덧붙였습니다 - " 
		<< std::filesystem::file_size(fileName) << " bytes" << std::endl;

	// 저장한 시간을 파일에 기록하자
	auto now = std::chrono::system_clock::now(); // time_point를 얻는다
	auto utc = std::chrono::system_clock::to_time_t(now); // time_point를 UTC시간으로 변경
	auto lt = std::localtime(&utc); // 지역시간으로 변경
	auto old = out.imbue(std::locale("ko_KR")); // out의 지역을 한국으로

	out << '\n' << '\n';
	out << "================================" << '\n';
	out << "저장한 시간 : " << std::put_time(lt, "%c %A") << '\n';
	out << "================================" << '\n';
	out << '\n';
	out.imbue(old);

	// 읽을 파일의 내용을 읽어서 저장할 파일에 덧붙인다
	std::copy(std::istreambuf_iterator{ in }, {}, std::ostreambuf_iterator{ out });
}