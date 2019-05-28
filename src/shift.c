#include "shift.h"

uint32_t lsl(uint32_t value, uint32_t shift)
{
  return value << shift;
}

uint32_t lsr(uint32_t value, uint32_t shift)
{
  return value >> shift;
}

uint32_t asr(uint32_t value, uint32_t shift)
{
  /* If the number is negative*/
  if (value >> 31)
  {
    return ~(~value >> shift);
  }
  else
  {
    return value >> shift;
  }
}

uint32_t ror(uint32_t value, uint32_t shift)
{
  return (value >> shift) | (value << (32 - shift));
}
