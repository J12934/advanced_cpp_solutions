#include <iostream>

#include "ResourceGuard.h"
#include "MemoryGuard.h"
#include "UniquePointer.h"

class Demo{
    std::string name;
public:
    explicit Demo(std::string name): name(std::move(name)){
        std::cout << "Demo instance '" << this->name << "' created." << std::endl;
    }

    void teardown(){
        std::cout << "Demo instance '" << this->name << "' teared down." << std::endl;
    }

    ~Demo(){
        std::cout << "Demo instance '" << this->name << "' deleted." << std::endl;
    }
};

int main() {
    /*{
        Demo demo = Demo("Resource Demo");
        auto resourceGuard = ResourceGuard([&] {
            demo.teardown();
        });
    }*/

    /*{
        Demo* demo = new Demo("Memory Demo");
        {
            auto memoryGuard = MemoryGuard<Demo>(demo);
            std::cout << "Exiting Inner Scope" << std::endl;
        }
        std::cout << "Exiting Outer Scope" << std::endl;
    }*/

    {
        auto demo = new Demo("Unique Pointer Demo");
        auto p1 = new UniquePointer<Demo>(demo);

        std::cout << "P1: '" << p1->get() << "'" << std::endl;

        std::cout << "Swapping" << std::endl;
        UniquePointer<Demo> p2 = p1->swap();

        std::cout << "P1: '" << p1.get() << "'" << std::endl;
        std::cout << "P2: '" << p2.get() << "'" << std::endl;
    }
}