#include "bytecode.h"
#include "runtime.h"
#include <iostream>

#define MEMORY_SIZE  1048576

using code::Instruction;
using code::Opcode;
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
 void disassemble (Instruction& instruction) {
   switch (instruction.opcode) {
     case Opcode::MOV: {
       if (instruction.immediate) {
              cout << "mov " << instruction.immediate << ", r" << (unsigned)instruction.dst << endl;
            }else {
              cout << "mov r" << (unsigned)instruction.src << ", r" << (unsigned)instruction.dst << endl;
            }
            break;
     }
     case Opcode::SL: {
       if (instruction.immediate) {
              cout << "sl " << instruction.immediate << ", r" << (unsigned)instruction.dst << endl;
            }else {
              cout << "sl r" << (unsigned)instruction.src << ", r" << (unsigned)instruction.dst << endl;
            }
            break;
     }
     case Opcode::SR: {
       if (instruction.immediate) {
              cout << "sl " << instruction.immediate << ", r" << (unsigned)instruction.dst << endl;
            }else {
              cout << "sl r" << (unsigned)instruction.src << ", r" << (unsigned)instruction.dst << endl;
            }
            break;
     }
     case Opcode::LDR: {
              cout << "ldr " << instruction.immediate << "(r" << (unsigned)instruction.src << "), r" << (unsigned)instruction.dst << endl;
            break;
     }
     case Opcode::STR: {
       cout << "str r" << (unsigned)instruction.src << ", " << instruction.immediate  << "(r" << (unsigned)instruction.dst << ")" << endl;
       break;
     }
     case Opcode::DOWN: {
       cout << "down" << endl;
       break;
            }
     default:
       cout << "<Unknown>" << endl;
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
  runtime::disassemble(*this);
  switch (opcode) {
    case Opcode::MOV: {
      registers[dst] = notEqualOrElse<0, uint64_t>(immediate, registers[src]);
      break;
    }
            case Opcode::SL: {
            registers[dst] <<= notEqualOrElse<0, uint64_t>(immediate, registers[src]);
            break;
    }
            case Opcode::SR: {
            registers[dst] >>= notEqualOrElse<0, uint64_t>(immediate, registers[src]);
            break;
    }
            case Opcode::LDR: {
              uint64_t address = registers[src] + immediate;
                if (address < MEMORY_SIZE - 8) {
                registers[dst] = *(uint64_t*)(memory + address);
                }
              break;
            }
              case Opcode::STR: {
                uint64_t address = registers[dst] + immediate;
                if (address < MEMORY_SIZE - 8) {
                *(uint64_t*)(memory + address) = registers[src];
                }
                break;
              }
              case Opcode::DOWN: {
                registers[Register::IP] = MEMORY_SIZE;
                break;
              }
             default:
               cout << "Unknown opcode: " << static_cast<int>(opcode) << endl;
               break;
    }
}
}
