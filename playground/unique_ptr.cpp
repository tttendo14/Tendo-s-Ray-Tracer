#include <iostream>
#include <memory>

using namespace std;

struct A {
  void print() { cout << "Object of A" << endl; }
};

int main() {
  unique_ptr<A> ptr = make_unique<A>();
  ptr->print();
  cout << "Address: " << ptr.get() << endl;

  unique_ptr<A> ptr2 = std::move(ptr);
  cout << "Address: " << ptr.get() << endl;
  cout << "Address: " << ptr2.get() << endl;
  return 0;
}
