#include "memory.h"
#include <cstdint>
#include <stdexcept>

uint8_t Memory::load(uint16_t reg){
    if(reg > Memory::MEMORY_SIZE){
        throw std::out_of_range("No memory");
    }
    return memory[reg];
}

void Memory::store(uint16_t reg, uint8_t value){

}