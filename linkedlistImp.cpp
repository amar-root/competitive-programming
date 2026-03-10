#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
        Node(int val){
            data = val;
            next = nullptr;
        }
};
class llist{
    Node* head;
    public:
        llist(){
            head = nullptr;
        }
        void insertAtbegning(int data){
            Node* nn = new Node(data);
            if(head == NULL){
                head = nn;
                return;
            }
            nn->next = this->head;
            this->head = nn;
        }
        void insertAtEnd(int data){
            Node* nn = new Node(data);
            if(head == NULL){
                head = nn;
                return;
            }
            if(head->next == NULL){
                head->next = nn;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = nn;
            //head = temp;
        }
        void reverseLL(){
            Node* prev = nullptr;
            Node* curr = head;
            Node* nex = nullptr;
            while(curr != NULL){
                nex = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nex;
            }
            head = prev;
        }
        void insertAfterGivenNode(int pos, int data){
            Node* nn = new Node(data);
            if(head == NULL){
                head = nn;
                return;
            }
            Node* temp = head;
            while(temp->data != pos){
                temp = temp->next;
            }
            nn->next = temp->next;
            temp->next = nn;            
        }
        void print(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};
int main(){
    llist root;
    root.insertAtEnd(10);
    root.insertAtbegning(5);
    root.insertAtbegning(4);
    root.insertAtbegning(12);
    root.insertAtbegning(7);
    root.insertAtEnd(1);
    root.insertAtEnd(100);
    root.insertAfterGivenNode(7,70);
    cout << "Print element in the linked list :\n";
    root.print();
    cout << "\nReverse of a linked list :\n";
    root.reverseLL();
    root.print();

    return 0;
}