#include <iostream>

#include "bytecode.h"
#include "random.h"

using std::cout;
using std::endl;

int main() {
  Random::init();
  cout << "Using instruction length: " << sizeof(code::Instruction) * 8 << endl;
  cout << Random::u8() << endl;
  return 0;
}
