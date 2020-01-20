#include<iostream>
using namespace std;
 
class A
{
  int x;
  public:
    A() { x = 0;}
    void fun() {
      delete this;
      cout<<x;
    }
};
class B
{
  public:
    void fun()
    {
        delete this;
    }
};
 
int main()
{
  A *ptr = new A;
  ptr->fun();
  ptr = NULL; 
 
  A a;
  a.fun();
 
  getchar();
  return 0;
}
