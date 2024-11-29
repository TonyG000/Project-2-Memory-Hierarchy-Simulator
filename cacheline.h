#ifndef CACHELINE_H
#define CACHELINE_H

class Cacheline {
public:
    bool valid;   // Valid bit indicating if the cacheline is valid
    int tag;      // Tag stored in the cacheline
    Cacheline();
    void display() const;
};

#endif  
