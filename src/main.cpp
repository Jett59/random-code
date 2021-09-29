#include <iostream>

#include "bytecode.h"

using std::cout;
using std::endl;

int main() {
     cout << "Using instruction length: " << sizeof(code::Instruction) * 8 << endl;
  return 0;
}
