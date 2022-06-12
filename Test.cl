#include "Scene.hpp"

__kernel void Test(__global char* data)
{
    for (int i = 0; i < 4; i++)
        data[i] = 'A';
    data[4] = '\0';
}