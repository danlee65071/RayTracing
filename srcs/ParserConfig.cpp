//
// Created by Hazzea Charlsie on 5/19/22.
//

#include "Parser.hpp"

void Parser::_checkFileName() const
{
	if (this->_fileName.size() <= 3 ||
		this->_fileName.substr(this->_fileName.size() - 3, 3) != ".rt")
		throw BadFileName();
}

size_t Parser::_checkSpace(const std::string& line)
{
	size_t i;
	for (i = 0; i < line.size(); ++i)
		if (!isspace(line[i]))
			return i;
	return i;
}

void Parser::_parseConfig()
{
	std::string 		key;

	for (auto& line: this->_vConfig)
	{
		this->_ssClear();
		this->_ss << line;
		this->_ss >> key;
		if (key == "A")
			this->_parseAmbient(line);
		else if (key == "C")
			this->_parseCamera(line);
		else if (key == "L")
			this->_parseLight(line);
		else if (key == "pl")
			this->_parsePlane(line);
		else if (key == "cy")
			this->_parseCylinder(line);
		else if (key == "sp")
			this->_parseSphere(line);
		else if (key == "co")
			this->_parseCone(line);
		else
			throw UnknownObject();
	}
}

