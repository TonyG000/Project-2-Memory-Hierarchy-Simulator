#include "Memory.h"
#include <cmath>

Memory::Memory(int addressBits, int accessTime)
    : address_bits(addressBits), access_time(accessTime) {
    total_memory = static_cast<int>(pow(2, addressBits));
}

int Memory::getTotalSize() const {
    return total_memory;
}

int Memory::getAccessTime() const {
    return access_time;
}