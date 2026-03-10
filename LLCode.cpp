#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next;
    public:
        Node(){
            data = 0;
            next = nullptr;
        }
        void push(Node** hr,int x){
            Node* temp = new Node();
            temp->data = x;
            temp->next = *hr;
            *hr = temp;
        }
        void display(Node* head){
            Node* temp = head;
            while(temp){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        void insertAtLast(Node** hr,int x){
            Node* temp = new Node();
            temp->data = x;
            temp->next = NULL;
            if(*hr == NULL){
                *hr = temp;
                return;
            }
            Node* nn = *hr;
            while(nn->next != NULL){
                nn = nn->next;
            }
            nn->next = temp;
        }
};
int main(){
    Node* root = NULL;
    root->insertAtLast(&root, 5);
    root->push(&root, 10);
    root->push(&root, 20);
    root->push(&root, 30);
    root->push(&root, 40);
    root->push(&root, 60);
    root->insertAtLast(&root, 50);
    root->display(root);
}