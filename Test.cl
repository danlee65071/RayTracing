#define GENERATE_OPENCL_CODE
#define INCLUDED_IN_IMPLEMENTATION_FILE

class TestClass
{
private:
	int x = 1;
public:
	void setX(int other) { x = other; }
	int getX() const { return x; }
};

void kernel simple_add(global const TestClass* A, global const TestClass* B, global TestClass* C)
{
    C->setX(A->getX() + B->getX());
}