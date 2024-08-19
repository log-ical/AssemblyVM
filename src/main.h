#include <cstdint>

struct Opcode {
  uint32_t operand[3];
  op_type type;
};
enum class op_type
{
    mov_reg,
    add_reg,
    sub_reg,
    int_reg, //temp print
    push_reg,
    pop_reg,
};