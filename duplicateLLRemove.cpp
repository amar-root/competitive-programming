#include <iostream>
#include <vector>

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

class LL{
    public:
        Node* head;
        LL(){
            head = nullptr;
        }

        void addNode(int val){
            Node* nn = new Node(val);

            if(head == NULL){
                head = nn;
                return;
            }
            Node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = nn;
        }

        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }

        void removeDuplicate(){
            vector<bool> v(1001,false);

            Node* curr = head;
            Node* prev = nullptr;

            while(curr){
                if(v[curr->data]){
                    prev->next = curr->next;
                    curr = curr->next;
                } else {
                    v[curr->data] = true;
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
};

int main(){
    LL root;
    root.addNode(3);
    root.addNode(4);
    root.addNode(5);
    root.addNode(6);
    root.addNode(2);
    root.addNode(3);
    root.addNode(4);

    cout << "LL are : \n";
    root.display();

    cout << "\nLL after duplicate removal : \n";
    root.removeDuplicate();
    root.display();
}
