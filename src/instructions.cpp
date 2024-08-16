#include "instructions.h"
#include <stdexcept>
#include <cstdint>
#include <sstream>

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
    iss >> op;
    if(op == "MOV"){
        std::string reg;
        uint8_t value;
        iss >> reg >> value;
        uint16_t address = regAddress(reg);
        mov(address, value);
    }
    else if(op == "PUSH"){

    }
    else if(op == "POP"){

    }
    else if(op == "ADD"){
        
    }
    else if(op == "SUB"){
        
    }
    else if(op == "PRINT"){
        
    }
}

void Instructions::print(const uint16_t reg){

}
void Instructions::mov(uint16_t& reg, int value){
    memory.store(reg, value);
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
