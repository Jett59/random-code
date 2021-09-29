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
  instructions.push_back(Instruction(Opcode::MOV, 0, 1, 1));
  instructions.push_back(Instruction(Opcode::SL, 0, 1, 16));
  instructions.push_back(Instruction(Opcode::LDR, 0, 2, -4));
  instructions.push_back(Instruction(Opcode::STR, 2, 0, -8));
  instructions.push_back(Instruction(Opcode::LDR, 0, 5, -12));
  instructions.push_back(Instruction(Opcode::ADD, 0, 0, 4));
  instructions.push_back(Instruction(Opcode::DOWN, 0, 0, 0));
  instructions.push_back(Instruction(Opcode::SUB, 0, 0, 8));
  exec(instructions);
  runtime::machineDump();
  return 0;
}
