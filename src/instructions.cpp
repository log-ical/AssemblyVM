#include "instructions.h"
#include <stdexcept>
#include <cstdint>
#include <sstream>
#include <iostream>
#include <limits> 

void Instructions::loadInstructions(const std::vector<std::string>& program){
    this->program = program;
}
void Instructions::execute(){
    while(clock<program.size()){
        exeInstruction(program[clock]);
        ++clock;
    }
}
void Instructions::exeInstruction(const std::string& instruction){
    std::istringstream iss(instruction);
    std::string op;
    std::string reg;
    std::string reg2;
    uint8_t value;

    iss >> op;
    if(op == "MOV"){
        iss >> reg >> reg2;
        if(isRegister(reg2)){
            std::cout << "Test";
            uint16_t destReg = regAddress(reg);
            uint16_t srcReg = regAddress(reg);
            mov(destReg, srcReg);
        }
        else{
            iss.clear();
            iss.ignore(std::numeric_limits<std::streamsize>::max(), ' ');
            std::istringstream valueStream(reg2);
            valueStream >> value;
            uint16_t address = regAddress(reg);
            mov(address, value);
        }
    }
    else if(op == "PUSH"){
        iss >> reg >> reg2;
        uint16_t address = regAddress(reg2);
        uint16_t value = regAddress(reg);
        add(value, address);
    }
    else if(op == "POP"){
    }
    else if(op == "ADD"){
    }
    else if(op == "SUB"){
    }
    else if(op == "PRINT"){
        iss >> reg;
        uint16_t address = regAddress(reg);
        print(address);
    }
}

void Instructions::print(const uint16_t reg){
    auto val = memory.load(reg);
    std::cout << val << std::endl;
}
void Instructions::mov(uint16_t& reg, int value){
    memory.store(reg, value);
}
void Instructions::mov(uint16_t& reg, uint16_t& reg2){
    auto val = memory.load(reg2);
    memory.store(reg, val);
}
void Instructions::push(uint16_t& reg){

}
void Instructions::pop(uint16_t& reg){

}

void Instructions::add(uint16_t& reg1, uint16_t& reg2){

}
void Instructions::sub(uint16_t& reg1, uint16_t& reg2){

}
uint16_t Instructions::regAddress(std::string& reg){
    if(reg == "EAX") return 0x0000;
    if(reg == "EBX") return 0x0004;
    if(reg == "ECX") return 0x0008;
    if(reg == "EDX") return 0x000C;
    throw std::invalid_argument("Register not valid");
}

bool Instructions::isRegister(std::string str){
    return (str == "EAX" || str == "EBX" || str == "ECX" || str == "EDX");
}