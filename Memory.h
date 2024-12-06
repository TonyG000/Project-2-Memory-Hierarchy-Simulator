#ifndef MEMORY_H
#define MEMORY_H

class Memory {
private:
    int address_bits;
    int access_time;
    int total_memory;

public:
    Memory(int addressBits, int accessTime);
    int getTotalSize() const;
    int getAccessTime() const;
};

#endif // MEMORY_H