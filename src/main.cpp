#include <iostream>

#include "bytecode.h"
#include "random.h"
#include "runtime.h"

using std::cout;
using std::endl;

using code::Instruction;
using code::Opcode;

int main() {
  Random::init();
  cout << "Using instruction length: " << sizeof(Instruction) * 8 << endl;
  runtime::machineDump();
  Instruction instruction;
  instruction.opcode = Opcode::MOV;
  instruction.dst = 1;
  instruction.immediate = 100;
  instruction();
  runtime::machineDump();
  return 0;
}
