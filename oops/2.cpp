#include<iostream>
using namespace std;
class rectangle{
    private:
    int length;
    int breadth;
    public:
   rectangle(int x, int y)
   {
       length=x;
       breadth=y;
   }
   void area()
   {
       cout<<"area of rectangle is"<<length*breadth<<endl;
   }
   void perimeter()
   {
       cout<<"perimeter of rectangle is "<<2*(length+breadth)<<endl;
   }
};
int main()
{
    rectangle r(50,20);
    r.area();
    r.perimeter();
    return 0;
}
