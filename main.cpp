#include <iostream>
#include <memory>

using namespace std;

class Toy {
public:
    Toy( string name) {
        name_ = name;
    }

    string getName() {
        return name_;
    }
    ~Toy() {
        cout << "Toy " << name_ << " was dropped " << endl;
    }
private:
    string name_;
};


class Dog {
public:
    void getToy(shared_ptr<Toy> toy) {
        if (toy == nullptr) {
            cout << "No toy to get." << endl;
        } else if (toy_ == nullptr) {
            toy_ = toy;
            cout << "I got the toy: " << toy_->getName() << endl;
        } else if (toy_ == toy) {
            cout << "I already have this toy." << endl;
        } else {
            cout << "Another dog is playing with this toy." << endl;
        }
    }

    void dropToy() {
        if (toy_ == nullptr) {
            cout << "Nothing to drop." << endl;
        } else {
            cout << "I dropped the toy: " << toy_->getName() << endl;
            toy_.reset();
        }
    }

private:
    shared_ptr<Toy> toy_;
};

int main() {
    shared_ptr<Toy> toy1 = make_shared<Toy>("Ball");
    shared_ptr<Toy> toy2 = make_shared<Toy>("Bone");

    Dog dog1;
    Dog dog2;

    dog1.getToy(toy1);
    dog2.getToy(toy2);

    dog1.getToy(toy2);
   
    dog1.dropToy();
    dog2.dropToy();

    return 0;
}

