#include <iostream>
#include <memory>

using namespace std;


class Toy {
public:
   Toy(string name) {
       name_ = name;
   }
   string getName() {
       return name_;
   }
   ~Toy() {
       cout << "Toy " << name_ << " was dropped" << std::endl;
   }
private:
   string name_;
};

class Dog {
public:

    void getToy(shared_ptr<Toy> toy) {

       if (toy == nullptr) {
            cout << "No toy to get." << endl;
       }

       else if (toy_ == toy) {
            cout << "I already have this toy." << endl;
         }
      
           else if (toy.use_count() > 2) {
            cout << "Another dog is playing with this toy." << std::endl;
        }
         

        else {
            toy_ = toy;
            cout << "I got a new toy: " << toy_->getName() << std::endl;
        }
        
         
    }

   
    void dropToy() {
        if (toy_) {
            toy_.reset();
            cout << "I dropped the toy." << endl;
        } else {
            cout << "Nothing to drop." << endl;
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
    dog1.getToy(toy1); 
    dog2.getToy(toy1);
    dog2.getToy(toy2); 
    dog1.dropToy(); 
    dog2.dropToy();
  

    return 0;
}

