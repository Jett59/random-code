#ifndef _BYTECODE_H
#define _BYTECODE_H

#include <cstdint>

namespace code {
enum class Opcode : uint8_t { 
     MOV = 0, // Move to register
     SL = 1, // Shift left
     SR = 2, // Shift right
     };
     class Register {
         private:
          Register() {}
          public:
           static const unsigned IP = 0;
     };
class Instruction {
 public:
  Opcode opcode;
  uint8_t src : 4;
  uint8_t dst : 4;
  uint16_t immediate;

  Instruction(Opcode opcode, uint8_t src, uint8_t dst, uint16_t immediate)
      : opcode(opcode), src(src), dst(dst), immediate(immediate) {}

  void operator()();
    };
}

#endif