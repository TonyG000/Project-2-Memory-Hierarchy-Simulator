#include "Cacheline.h"
#include <iostream>
using namespace std;
Cacheline::Cacheline() {
    valid = false;  // initialize as invalid
    tag = -1;       // invalid tag when -1
}
void Cacheline::display() const {
    cout << "Valid: " << valid << ", Tag: ";
    if (tag == -1) {
        cout << "invalid";   
    } else {
        cout << tag;     
    }
    cout << endl;
}
