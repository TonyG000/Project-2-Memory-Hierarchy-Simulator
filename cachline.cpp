#include "cacheline.h"
#include <iostream>
using namespace std;

Cacheline::Cacheline() {
    valid = false;   // Initialize as invalid
    tag = -1;        // Invalid tag when -1
    data = "empty";  // Default data
}

void Cacheline::display() const {
    cout << "Valid: " << valid << ", Tag: ";
    if (tag == -1) {
        cout << "invalid";
    } else {
        cout << tag;
    }
    cout << ", Data: " << data << endl;
}
