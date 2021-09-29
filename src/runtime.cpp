#include "bytecode.h"
#include "runtime.h"
#include <iostream>

using std::cout;
using std::endl;

static uint64_t registers[32] = {0};

namespace runtime {
void machineDump() { 
    for (int i = 0; i < 32; i ++) {
      cout << "r" << i << ": " << registers[i] << endl;
}
 }
}

namespace code {
void Instruction::operator() () {
    switch (opcode) {
          case Opcode::MOV:
            if (immediate) {
              registers[dst] = immediate;
            }else {
              registers[dst] = registers[src];
            }
            break;
            default:
              break;
    }
}
}
