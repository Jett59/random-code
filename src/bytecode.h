#ifndef _BYTECODE_H
#define _BYTECODE_H

#include <cstdint>

namespace code {
enum class Opcode : uint8_t { 
     MOV = 0
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

  void operator()();
    };
}

#endif