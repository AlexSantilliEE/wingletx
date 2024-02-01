// wingletx.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "defines.h"
#include "protos.h"
#include "globals.h"

int main(int argc, char* argv[])
{

    std::cout << WINGLET_PROG_VERSION << std::endl;

    readCommands();

    return 0;

}