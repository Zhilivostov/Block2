#pragma once
#include <string>
#include <iostream>
#include "freq_dict.h"

class parser {
private:



public:

	//void read_text(const std::string&, dict_abstract&); //������������� ��������������, ����� ��� const ��� volatile �� �������� �� C++, �������� ���������� ���������. C4227
	void read_text(std::istream&, dict_abstract&);

	std::string filter(const std::string&);

	void write_result(const std::string&, dict_abstract&);
};