#include "interpreter.h"
#include "instructions.cpp"
#include <sstream>
#include <iostream>
#include <cstdint>
#include <unordered_map>
#include <algorithm>




void Interpreter::loadInstructions(const std::vector<std::string>& program){
    this->program = program;
}
void Interpreter::execute(){
    while(line<program.size()){
        std::cout<<program[line]<<std::endl;
        parseLine(program[line]);
        ++line;
    }
}

void Interpreter::parseLine(std::string line){
    std::istringstream iss(line);
    std::string op;
    std::string s_reg;
    uint32_t v1, v2;
    iss >> op >> s_reg >> v1 >> v2;
    op_type type = convertToOpType(op);
    reg_type reg = convertToReg(s_reg);

    Opcode opcode = convertToOpcode(type, reg, v1, v2);
    exeInstruction(opcode);
}

Interpreter::Opcode Interpreter::convertToOpcode(op_type type, reg_type reg, uint32_t v1, uint32_t v2){
    Opcode op;
    op.type = type;
    op.operand[0] = uint32_t(reg);
    op.operand[1] = v1;
    return op;
}
Interpreter::op_type Interpreter::convertToOpType(std::string op){
    std::transform(op.begin(), op.end(), op.begin(), ::toupper);
    static const std::unordered_map<std::string, op_type> ops = {
        {"MOV", op_type::mov_reg},
        {"ADD", op_type::add_reg},
        {"SUB", op_type::sub_reg},
        {"INT", op_type::int_reg},
        {"PUSH",op_type::push_reg},
        {"POP", op_type::pop_reg},
    };
    return ops.find(op)->second;
}
Interpreter::reg_type Interpreter::convertToReg(std::string str){
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    static const std::unordered_map<std::string, reg_type> reg = {
        {"R0", R0},
        {"R1", R1},
        {"R2", R2},
        {"R3", R3},
        {"R4", R4},
        {"R5", R5},
        {"R6", R6},
        {"R7", R7},
        {"R8", R8},
        {"R9", R9}
    };
    return reg.find(str)->second;
}


void Interpreter::exeInstruction(Interpreter::Opcode opcode){
    Instructions instruction;
    switch(opcode.type){
        case Interpreter::op_type::mov_reg:
        {
            instruction.mov(opcode.operand[0], opcode.operand[1]);
            break;
        }
        case Interpreter::op_type::add_reg:
        {
            break;
        }
        case Interpreter::op_type::sub_reg:
        {
            break;
        }
        case Interpreter::op_type::int_reg:
        {
            break;
        }
        case Interpreter::op_type::push_reg:
        {
            break;
        }
        case Interpreter::op_type::pop_reg:
        {
            break;
        }
    };

}