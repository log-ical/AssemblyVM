#include "memory.h"
#include <cstdint>
#include <stdexcept>
#include <iostream>

uint8_t Memory::load(uint16_t address){
    if(address > Memory::MEMORY_SIZE){
        throw std::out_of_range("Out of range memory");
    }
    return memory[address];
}

void Memory::store(uint16_t address, uint8_t value){
    if(address > MEMORY_SIZE){
        throw std::out_of_range("Out of range memory");
    }
    memory[address] = value;
}   