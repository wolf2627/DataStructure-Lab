#include<iostream>

using namespace std;

class dist{
    public:
        int feet;
        int inches;

        void display(){
            cout<<feet<<" feet "<<inches<<" inches."<<endl;
        }

        void add(dist d1, dist d2){
            feet = d1.feet + d2.feet;
            inches = d1.inches + d2.inches;
            if(inches>=12){
                feet = feet + (inches/12);
                inches = inches % 12;
            }
        }
};

int main(){
    dist d1 , d2, d3;
    cout<<"Enter the feet and inch of the first distance: ";
    cin>>d1.feet>>d1.inches;
    cout<<"Enter the feet and inch of the second distance: ";
    cin>>d2.feet>>d2.inches;

    d1.display();
    d2.display();

    d3.add(d1, d2);
    cout<<"Sum of the two distances: "<<endl;
    d3.display();

}