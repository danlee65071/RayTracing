#include "Parser.hpp"
#include "Scene.hpp"

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
	std::cout << std::endl;
	p.testScene();
}

void CLStart()
{
	cl_uint nP;
	cl_uint status = clGetPlatformIDs(0, NULL, &nP);
	std::cout << "nP: " << nP << std::endl;
	std::cout << "status: " << status << std::endl;
	std::vector<cl::Platform> platforms;
	status = cl::Platform::get(&platforms);
	std::cout << "status get platforms: " << status << std::endl;
	std::cout << "num of platforms: " << platforms.size() << std::endl;
	std::cout << "platform name: " << platforms[0].getInfo<CL_PLATFORM_NAME>() << std::endl;
	std::vector<cl::Device> devices;
	status = platforms[0].getDevices(CL_DEVICE_TYPE_GPU, &devices);
	std::cout << "num of gpu devices: " << devices.size() << std::endl;
	std::cout << "status get devices: " << status << std::endl;
	cl::Context ClContext(devices);
	std::cout << "context getInfo: " << ClContext.getInfo(CL_CONTEXT_DEVICES, &devices) << std::endl;

	cl::CommandQueue ClQueue(ClContext, devices[0]);

	std::ifstream file("Test.cl");
	std::string ProgramText((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

	cl::Program::Sources ClSrcs(1, std::make_pair(ProgramText.c_str(), ProgramText.size() + 1));
	cl::Program ClProgram(ClContext, ClSrcs);
	ClProgram.build(devices);

	cl::Kernel ClKernel(ClProgram, "Test");
	char text[4] = "bbb";
	cl::Buffer buf(ClContext, CL_MEM_READ_WRITE, sizeof(text));
	ClKernel.setArg(0, buf);
	ClQueue.enqueueTask(ClKernel);
	ClQueue.enqueueReadBuffer(buf, true, 0, sizeof(text), text);

	std::cout << text << std::endl;
}

int main(int argc, char** argv)
{
	CLStart();
	Parser p("scenes/hi.rt");
	testParser(p);
	Scene s = p.getScene();
	s.rendering(argc, argv);
}
