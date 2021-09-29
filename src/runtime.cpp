#include "bytecode.h"
#include "runtime.h"
#include <iostream>

using code::Instruction;
using code::Register;
using std::cout;
using std::endl;
using std::vector;

static uint64_t registers[32] = {0};

namespace runtime {
void machineDump() { 
    for (int i = 0; i < 32; i ++) {
      cout << "r" << i << ": " << registers[i] << endl;
}
 }
 void exec(vector<Instruction> instructions) {
   while (registers[Register::IP] / sizeof(Instruction) < instructions.size()) {
     instructions[registers[Register::IP] / 4]();
     registers[Register::IP] += sizeof(Instruction);
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
