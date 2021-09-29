#include "bytecode.h"
#include "runtime.h"
#include <iostream>

using code::Instruction;
using code::Register;
using std::cout;
using std::endl;
using std::vector;

static uint64_t registers[32] = {0};

template<int n, class t> t notEqualOrElse (t prefered, t fallback) {
  return prefered == n ? fallback : prefered;
}

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
            registers[dst] = notEqualOrElse<0, uint64_t>(immediate, registers[src]);
            break;
            case Opcode::SL:
            registers[dst] <<= notEqualOrElse<0, uint64_t>(immediate, registers[src]);
            break;
            case Opcode::SR:
            registers[dst] >>= notEqualOrElse<0, uint64_t>(immediate, registers[src]);
            break;
            default:
              break;
    }
}
}
