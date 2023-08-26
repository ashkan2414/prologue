#include "prologue/prologue.h"

#include <iostream>

using namespace prologue;

void prologue::log(std::string msg)
{
    std::cout << msg << std::endl;
}