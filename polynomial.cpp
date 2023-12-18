#include<iostream>

using namespace std;

class polynode{
    public: 
    int coeff;
    int exp;
    polynode *next;
};

class polynomial{
    public:
    polynode *head = NULL, *y = NULL;
        void create(int n){
            for(int i = 0; i<n; i++){
                polynode *p = new polynode();
                cout<<"Enter coeff and expononent of the node : ";
                cin>>p->coeff>>p->exp;
                if(head == NULL){
                    head = p;
                    y = p;
                    p->next = NULL;
                } else {    
                    y->next = p;
                    y = p;
                    p->next = NULL;
                }
            }
        }

        void add(polynomial p1, polynomial p2){
            head = NULL;
            polynode *cur1 = p1.head, *cur2 = p2.head, *rescur;
            while(cur1 && cur2){
                polynode *p = new polynode();
                if(cur1->exp > cur2-> exp){
                    p->coeff = cur1->coeff;
                    p->exp = cur1->exp;
                    cur1 = cur1->next;
                } 
                else if(cur1->exp < cur2->exp){
                    p->coeff = cur2 ->coeff;
                    p->exp = cur2->exp;
                    cur2= cur2->next;
                } 
                else {
                    p->coeff = cur1->coeff + cur2->coeff;
                    p->exp = cur1 ->exp;
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                }
                if(head == NULL){
                    head = p;
                    rescur = p;
                } else {
                    rescur->next = p;
                    rescur = p;
                }
                p->next = NULL;
                //cur2 = cur2->next;
            }

            while(cur1){
                polynode *y = new polynode();
                y->coeff = cur1->coeff;
                y->exp = cur1->exp;
                if(head == NULL){
                    head = y;
                    rescur = y;
                } else {
                    rescur->next = y;
                    rescur = y;
                }
                y->next = NULL;
                cur1 = cur1 -> next;
                
            }  
            while(cur2){
                polynode *y = new polynode();
                y->coeff = cur2 ->coeff;
                y->exp = cur2->exp;
                if(head == NULL){
                    head = y;
                    rescur = y;
                } else {
                    rescur->next = y;
                    rescur=y;
                }
                y->next = NULL;
                cur2 = cur2->next;
            }
        }

        void display(){
            y = head;
            while(y){
                cout<<y->coeff<<"x^ "<<y->exp<<"--->";
                y=y->next;
            }
            cout<<"NULL"<<endl;
        }
};


int main(){
    polynomial p1, p2, p3;
    cout<<"Enter the first polynomial: "<<endl;
    p1.create(3);
    cout<<"Enter the second polynomial: "<<endl;
    p2.create(3);
    cout<<"Addition Result: ";
    p3.add(p1, p2);
    p3.display();

}