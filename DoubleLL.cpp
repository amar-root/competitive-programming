#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data = val;
        next = prev = nullptr;
    }
};

class DLL{
    public:
        Node* head;

        DLL(){head = nullptr;}

        void insertAtHead(int val){
            Node* nn = new Node(val);

            if(head == NULL){
                head = nn;
                return;
            }
            nn->next = head;
            head->prev = nn;
            head = nn;
        }

        void reversek(int k){
            if(head == NULL) return;

            Node* curr = head;
            Node* newHead = nullptr;
            Node* groupPointHead = nullptr;

            while(curr != nullptr){
                Node* groupHead = curr;
                Node* prev = nullptr;
                int cnt = 0;

                while(curr != nullptr && cnt <k){
                    Node* newNode = curr->next;
                    curr->next = prev;
                    curr->prev = newNode;
                    prev = curr;
                    curr = newNode;
                    cnt++;
                }

                if(!newHead) newHead = prev;

                if(groupPointHead){
                    groupPointHead->next = prev;
                    prev->prev = groupPointHead;
                }
                groupPointHead = groupHead;
            }
            head = newHead;
        }
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};

int main(){
    DLL root;
    root.insertAtHead(5);
    root.insertAtHead(3);
    root.insertAtHead(4);
    root.insertAtHead(1);
    root.insertAtHead(9);
    root.insertAtHead(6);
    root.insertAtHead(7);
    root.insertAtHead(2);
    root.insertAtHead(8);

    cout << "Doubly linked list is : \n";
    root.display();

    root.reversek(3);
    cout << "\nDoubly linked list after k reverse : \n";
    root.display();
}