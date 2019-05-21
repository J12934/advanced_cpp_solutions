#pragma once

#include <iostream>

class ResourceGuard{
    std::function<void(void)> func;
public:
    explicit ResourceGuard(std::function<void(void)> func) : func(std::move(func)){}

    ~ResourceGuard(){
        this->func();
    }
};