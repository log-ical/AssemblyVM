
#include <cstdint>
#include <vector>
#include <string>
#include "memory.cpp"
//include "interpreter.h"


class Instructions {
public:
    void _int(const uint16_t reg);
    void mov(uint16_t reg, uint16_t reg2);
    void push(uint16_t& reg);
    void pop(uint16_t& reg);
    // void lea();
    void add(uint16_t& reg1, uint16_t& reg2);
    void sub(uint16_t& reg1, uint16_t& reg2);
    //void inc();
    //void dec();
    //void imul();
    //void idiv();
    //void _and();
    //void _or();
    //void _xor();
    //void _not();
    //void neg();
    //void shl();
    //void shr();
    //void jmp();
    ////condtional jumps
    //void je();
    //void jne();
    //void jz();
    //void jg();
    //void jge();
    //void jl();
    //void jle();
    //void cmp();
    //void call();
    //void ret();
private:
    Memory memory;
};
