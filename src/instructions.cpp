#include "instructions.h"
#include <stdexcept>
#include <cstdint>
#include <sstream>
#include <iostream>
#include <limits> 

void Instructions::_int(const uint16_t reg){
    auto val = memory.load(reg);
    std::cout << val << std::endl;
}

void Instructions::mov(uint16_t reg, uint16_t value){
    std::cout << "moved " << value <<" to " << reg << std::endl;
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
