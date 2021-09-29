#ifndef _RANDOM_H
#define _RANDOM_H

#include <cstdlib>
#include <cstdint>

class Random {
    private:
     Random() {}
     public:
      static void init() { srand((unsigned int)time(0)); }
      static uint8_t u8() { return (uint8_t)(rand() & 0xFF); }
      static uint16_t u16() { return ((uint16_t)u8() << 8) | u8(); }
};

#endif