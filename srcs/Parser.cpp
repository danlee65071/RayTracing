//
// Created by Hazzea Charlsie on 5/19/22.
//

#include "Parser.hpp"

Parser::Parser(std::string fileName): _fileName(std::move(fileName))
{
	this->_readFile();
	this->_parseConfig();
}

void Parser::_readFile()
{
	std::fstream	file(this->_fileName);
	std::string		buf;

	this->_checkFileName();
	if (file.is_open())
	{
		while (std::getline(file, buf, '\n'))
		{
			if (!buf.empty() && Parser::_checkSpace(buf) != buf.size())
				this->_vConfig.push_back(buf);
		}
		file.close();
	}
	else
	{
		throw BadFile();
	}
}

void Parser::_ssClear()
{
	this->_ss.clear();
	this->_ss.str("");
}
