#include <vector>
#include <cstdint>
#include <string>
#include "memory.cpp"

class Instructions {
public:
    Instructions():clock(0){}
    void loadInstructions(const std::vector<std::string>& program);
    void execute();
private:
    Memory memory;
    std::vector<std::string> program;
    uint32_t clock;
    uint16_t regAddress(std::string& reg);
    bool isRegister(const std::string str);
    void exeInstruction(const std::string& instruction);
    void print(const uint16_t reg);
    void mov(uint16_t& reg, int value);
    void mov(uint16_t& reg, uint16_t& reg2);
    void push(uint16_t& reg);
    void pop(uint16_t& reg);
    // void lea();
    //arithm
    void add(uint16_t& reg1, uint16_t& reg2);
    void sub(uint16_t& reg1, uint16_t& reg2);
    //void inc();
    //void dec();
    //void imul();
    //void idiv();
    ////bitwise
    //void _and();
    //void _or();
    //void _xor();
    //void _not();
    //void neg();
    //void shl();
    //void shr();
    ////flow instruction
    //void jmp();
    ////condtional jumps
    //void je();
    //void jne();
    //void jz();
    //void jg();
    //void jge();
    //void jl();
    //void jle();
//
    //void cmp();
    //void call();
    //void ret();

};