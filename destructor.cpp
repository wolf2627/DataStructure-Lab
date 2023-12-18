#include<iostream>
using namespace std;

class destructor  {
    private:
		int x;
    public:
        destructor(int n){
			x = n;
			cout<<"Constructor called"<<endl;
		}
		~destructor(){
			cout<<"Destructor called"<<endl;
		}

		void display(){
		cout<<"Value of x: "<<x<<endl;
		}
        

};


int main() {
    int num1;
    cout << "Enter a number: ";
    cin >> num1;
	destructor des(num1);
	des.display();

}
