#include <iostream>
using namespace std;
class Circle{
    private:
    int radius;
    public:
    Circle(int r){
        radius=r;
    }
    void area()
    {
        cout<<3.14*radius*radius;
    }
    void circumference()
    {
        cout<<2*3.14*radius;
    }
};
int main(void){
     int rad;
     cout << "Input the radius of the circle:";
     cin>>rad;
     Circle c(rad);
     c.circumference();
     c.area();
}