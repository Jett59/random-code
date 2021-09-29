#include "bytecode.h"
#include "runtime.h"
#include <iostream>

#define MEMORY_SIZE  1048576

using code::Instruction;
using code::Register;
using std::cout;
using std::endl;
using std::vector;

static uint64_t registers[32] = {0};
static uint8_t memory[MEMORY_SIZE] = {0};

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
   for (int i = 0; i < instructions.size(); i ++) {
     *((Instruction*)memory + i) = instructions[i];
   }
   while (registers[Register::IP] < MEMORY_SIZE) {
     (*(Instruction*)(memory + registers[Register::IP])) ();
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
