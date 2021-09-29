#ifndef _RUNTIME_H
#define _RUNTIME_H

#include <vector>

#include "bytecode.h"

namespace runtime {
void machineDump();

void exec(std::vector<code::Instruction> instructions);
}

#endif