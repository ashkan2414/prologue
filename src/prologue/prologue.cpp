#include "prologue/prologue.h"
#include "Core/Platform.h"

#include <iostream>

using namespace prologue;

void prologue::log(std::string msg)
{
    std::cout << msg << std::endl;
}