#include <iostream>
#include <memory>

using namespace std;

class Toy
{
  public:
  string name;

  Toy(string name)
  {
    cout << "called constructor " << this << endl;
    this->name = name;
  }

   Toy(const Toy &other)
  {
    cout << "called constructor copy " << this << endl;
    this->name = other.name;
  }

  Toy& operator = (const Toy &other)
  {
    cout << "caled operator " << this << endl;
    if(this != & other)
    {
       this->name = other.name;
    }
    return * this;
  }

  
  ~Toy()
  {
    cout << "called destructor " << this << " " << name << endl;
  }
};

 

int main() {

  Toy toy1("Alex");
  Toy toy2("Boris");

  cout << toy1.name << endl;
  cout << toy2.name << endl;

  toy2 = toy1;

  cout << toy1.name << endl;
  cout << toy2.name << endl;


    return 0;
}

