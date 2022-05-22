//
// Created by Hazzea Charlsie on 5/19/22.
//

#include "Parser.hpp"

const char *Parser::BadFileName::what() const noexcept
{
	return "Bad file name!";
}

const char *Parser::BadFile::what() const noexcept
{
	return "Bad file!";
}

const char *Parser::UnknownObject::what() const noexcept
{
	return "Unknown object!";
}

const char* Parser::TooManyParameters::what() const noexcept
{
	return "Too many parameters!";
}

const char* Parser::TooLowParameters::what() const noexcept
{
	return "Too low parameters!";
}

const char* Parser::InvalidParameter::what() const noexcept
{
	return "Invalid parameters!";
}
