#ifndef _BYTECODE_H
#define _BYTECODE_H

#include <cstdint>

namespace code {
enum class Opcode : uint8_t { 
    NOP = 0,
     MOV = 1
     };
class Instruction {
 public:
  Opcode opcode;
  uint8_t src : 4;
  uint8_t dst : 4;
  uint16_t immediate;
    };
}

#endif