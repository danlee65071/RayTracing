//
// Created by Hazzea Charlsie on 5/19/22.
//

#ifndef RT_PARSER_HPP
#define RT_PARSER_HPP

#include <iostream>
#include <utility>
#include <fstream>
#include <vector>
#include <sstream>
#include "utils.hpp"
#include "Color.hpp"

class Parser
{
private:
	std::string									_fileName;
	std::vector<std::string>					_vConfig;
	std::vector<std::shared_ptr<s_ambient> >	_v_ambient;
	std::vector<std::shared_ptr<s_camera> >		_v_camera;
	std::vector<std::shared_ptr<s_figure> >		_v_figure;
	std::stringstream							_ss;

public:
	Parser() = default;
	explicit Parser(std::string fileName);
	~Parser() = default;

private:
//	parser methods
	void _readFile();
//	check file methods
	void _checkFileName() const;
	static size_t _checkSpace(const std::string& line);
	void _parseConfig();
//	stringstream clear
	void _ssClear();
//	check objects methods
	void _parseAmbient(const std::string& line);
	void _parseCamera(const std::string& line);
	void _parseLight(const std::string& line);
	void _parseCylinder(const std::string& line);
	void _parseSphere(const std::string& line);
	void _parseCone(const std::string& line);
	void _parsePlane(const std::string& line);
//	parse params
	template<class T>
	static std::vector<T> _parseParamsToVec(const std::string& str);

//	test methods
public:
	void testReadFile();
	void testParseAmbient();
	void testParseCamera();
	void testParseLight();
	void testParseCylinder();
	void testParseSphere();
	void testParsePlane();

//	exceptions
private:
	class BadFileName: public std::exception
	{
		[[nodiscard]] const char* what() const noexcept override;
	};

	class BadFile: public std::exception
	{
		[[nodiscard]] const char* what() const noexcept override;
	};

	class UnknownObject: public std::exception
	{
		[[nodiscard]] const char* what() const noexcept override;
	};

	class TooManyParameters: public std::exception
	{
	public:
		[[nodiscard]] const char* what() const noexcept override;
	};

	class TooLowParameters: public std::exception
	{
	public:
		[[nodiscard]] const char* what() const noexcept override;
	};

	class InvalidParameter: public std::exception
	{
	public:
		[[nodiscard]] const char* what() const noexcept override;
	};
};

#endif //RT_PARSER_HPP
