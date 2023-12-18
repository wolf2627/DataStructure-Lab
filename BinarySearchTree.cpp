#include<iostream>

using namespace std;

class BsTree{
    public: 
    int data;
    BsTree  *left, *right, *parent;
};

BsTree* root=NULL;

class BsTreeOperations{
    public: 
     BsTree* insert(int x, BsTree *node) {
        if (node == NULL) {
            BsTree *T = new BsTree();
            T->data = x;
            T->left = T->right = T->parent = NULL;
            return T;
        } else if (x < node->data) {
            node->left = insert(x, node->left);
            node->left->parent = node;
        } else if (x > node->data) {
            node->right = insert(x, node->right);
            node->right->parent = node;
        }
        return node;
    }

    BsTree* deletenode(int x, BsTree *root){
        if(root==NULL){
            cout<<"Tree not found" <<endl;
        } else if (x < root->data){
            root->left = deletenode (x, root->left);
        } else if(x> root->data){
            root->right = deletenode(x, root->right);
        } else {
            if(root->left == NULL){
                BsTree* temp = root->right;
                delete root;
                cout<<"SuccessFully Deleted"<<endl;
                return temp;
            } else if(root->right == NULL){
                BsTree* temp = root->left;
                delete root;
                cout<<"Deleted SuccessFully"<<endl;
                return temp;
            } else {
                BsTree *temp = minValue(root->right);
                root->data = temp ->data;
                root->right = deletenode(temp->data, root->right);
            }
        }
        return root;
    } 

    BsTree *minValue(BsTree *node){
        BsTree *current = node ;
        while(current->left != NULL){
            current = current ->left;
        }
        return current;
    }

    void inorder (BsTree *root){
        if(root==NULL)
            return;
        else {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }


    BsTree *search(int x, BsTree *root){
        if(root==NULL)
            return root;
        if(x > root ->data)
            return search(x, root->right);
        if(x < root->data)
            return search(x, root->left);
        return root;
    }

};

int main(){
    int ch, e;
    BsTreeOperations b;
    while(1){
        cout<<"1. Insert 2.delete 3.inorder 4.search 5.exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch (ch)
        {
        case 1:
            cout<<"Enter element to insert : ";
            cin>>e;
            root = b.insert(e, root);
            break;
        case 2:
            cout<<"Enter the element to be deleted: ";
            cin>>e;
            root = b.deletenode(e , root);
            break;
        case 3: 
            cout<<"Inorder traversal : ";
            b.inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Enter the searching element : ";
            cin>>e;
            if(b.search(e, root)==NULL){
                cout<<"found"<<endl;
            } else 
                cout<<"not found"<<endl;
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
}