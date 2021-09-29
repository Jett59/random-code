#include <iostream>
#include <vector>

#include "bytecode.h"
#include "random.h"
#include "runtime.h"

using std::cout;
using std::endl;
using std::vector;

using code::Instruction;
using code::Opcode;

using runtime::exec;

int main() {
  Random::init();
  cout << "Using instruction length: " << sizeof(Instruction) * 8 << endl;
  runtime::machineDump();
  vector<Instruction> instructions;
  instructions.push_back(Instruction(Opcode::MOV, 0, 1, 1024));
  instructions.push_back(Instruction(Opcode::MOV, 1, 0, 0));
  exec(instructions);
  runtime::machineDump();
  return 0;
}
