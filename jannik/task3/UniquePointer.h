#pragma once

#include <iostream>

template <class t>
class UniquePointer {
    t * subject;
public:
    explicit UniquePointer(t* subject): subject(subject){}
    explicit UniquePointer(t& subject): subject(&subject){}

    explicit UniquePointer(UniquePointer<t>& pointer){
        this->subject = pointer.subject;
        delete pointer;
    }

    ~UniquePointer(){
        if(subject != nullptr){
            std::cout << "Unique Pointer deleting subject" << std::endl;
            delete subject;
        }else {
            std::cout << "Unique Pointer tried to delete subject but was null" << std::endl;
        }
    }

    UniquePointer & swap(){
        auto ptr = new UniquePointer(this->subject);
        this->subject = nullptr;
        return *ptr;
    }

    t& operator*() {
        if(this->subject != nullptr){
            return *subject;
        }
        throw std::runtime_error("Tried to dereference a nullpointer");
    }

    t* get() const{
        return subject;
    }
};