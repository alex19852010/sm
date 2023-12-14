#include <iostream>
#include <memory>

using namespace std;
 
 class Toy {
public:
    Toy(const std::string& name) : name(name) {
        std::cout << "Toy " << name << " was created" << std::endl;
    }

    ~Toy() {
        std::cout << "Toy " << name << " was dropped" << std::endl;
    }

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

class shared_ptr_toy {
public:
    shared_ptr_toy() : ptr(nullptr), count(nullptr) {}

    explicit shared_ptr_toy(const std::string& name) : ptr(new Toy(name)), count(new int(1)) {}

    shared_ptr_toy(const shared_ptr_toy& other) : ptr(other.ptr), count(other.count) {
        if (count) {
            (*count)++;
        }
    }

    ~shared_ptr_toy() {
        reset();
    }

    void reset() {
        if (count) {
            (*count)--;
            if (*count == 0) {
                delete ptr;
                delete count;
                std::cout << "Toy was deleted" << std::endl;
            }
        }
        ptr = nullptr;
        count = nullptr;
    }

    Toy* get() const {
        return ptr;
    }

    int use_count() const {
        if (count) {
            return *count;
        }
        return 0;
    }

    std::string getToyName() const {
        if (ptr) {
            return ptr->getName();
        }
        return "Nothing";
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this != &other) {
            reset();
            ptr = other.ptr;
            count = other.count;
            if (count) {
                (*count)++;
            }
        }
        return *this;
    }

private:
    Toy* ptr;
    int* count;
};

shared_ptr_toy make_shared_toy(const std::string& name) {
    return shared_ptr_toy(name);
}

int main() {
  
    shared_ptr_toy toy_01 = make_shared_toy("ball");
    shared_ptr_toy toy_02(toy_01);
    shared_ptr_toy toy_03("duck");

    std::cout << "=================================================" << std::endl;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;

    std::cout << "=================================================" << std::endl;
    toy_02 = toy_03;
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;

    std::cout << "=================================================" << std::endl;
    toy_01.reset();
    std::cout << toy_01.getToyName() << " links:" << toy_01.use_count() << "  "
              << toy_02.getToyName() << " links:" << toy_02.use_count() << "  "
              << toy_03.getToyName() << " links:" << toy_03.use_count() << std::endl;

    std::cout << "=================================================" << std::endl;
    
    
    return 0;
}
