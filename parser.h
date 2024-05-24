#pragma once
#include <string>
#include <iostream>
#include "freq_dict.h"

class parser {
private:



public:

	//void read_text(const std::string&, dict_abstract&); //»спользование квалификаторов, таких как const или volatile со ссылками на C++, €вл€етс€ устаревшей практикой. C4227
	void read_text(std::istream&, dict_abstract&);

	std::string filter(const std::string&);

	void write_result(const std::string&, dict_abstract&);
};