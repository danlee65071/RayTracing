#include "RayTracing.hpp"

void testParser(Parser& p)
{
	p.testReadFile();
	std::cout << std::endl;
	p.testParseAmbient();
	std::cout << std::endl;
	p.testParseCamera();
	std::cout << std::endl;
	p.testParseLight();
	std::cout << std::endl;
	p.testParseCylinder();
	std::cout << std::endl;
	p.testParseSphere();
	std::cout << std::endl;
	p.testParsePlane();
}

int main()
{
	Parser p("scenes/hi.rt");
	testParser(p);
}
