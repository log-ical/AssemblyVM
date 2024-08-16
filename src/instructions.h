#include <vector>
#include <cstdint>

class Instructions {
public:


private:
    void print(const uint16_t reg);
    void mov(uint16_t& reg, int value);
    void push(uint16_t& reg);
    void pop();
    // void lea();
    //arithm
    void add();
    void sub();
    void inc();
    void dec();
    void imul();
    void idiv();
    //bitwise
    void _and();
    void _or();
    void _xor();
    void _not();
    void neg();
    void shl();
    void shr();
    //flow instruction
    void jmp();
    //condtional jumps
    void je();
    void jne();
    void jz();
    void jg();
    void jge();
    void jl();
    void jle();

    void cmp();
    void call();
    void ret();

};