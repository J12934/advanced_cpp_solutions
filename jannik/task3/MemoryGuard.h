#pragma once

#include <iostream>

template <class t>
class MemoryGuard{
    t * subject;
public:
    explicit MemoryGuard(t * subject) : subject(subject){}

    ~MemoryGuard(){
        std::cout << "Memory guard deleting its subject" <<  std::endl;
        delete(this->subject);
    }
};