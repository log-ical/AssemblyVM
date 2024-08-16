#include <vector>
#include <cstdint>



class Memory{
public:
    const size_t MEMORY_SIZE = 65536;
    Memory(): memory(MEMORY_SIZE,0) {}
    uint8_t load(uint16_t reg);
    void store(uint16_t reg, uint8_t value);
private:
    std::vector<uint8_t> memory;
};