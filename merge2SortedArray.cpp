#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = nullptr;
        }
};

class msLL{
    
    public:
    Node* head;
        msLL(){
            head = nullptr;
        }
        void inserNodeAtEnd(int data){
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
        }
        
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp->data << " " ;
                temp = temp->next;
            }
        }
        static Node* mergeLL(Node* h1, Node* h22);
        static Node* MS2LL(Node* h1,Node* h2);
};

Node* msLL::mergeLL(Node* h1, Node* h2) {
    vector<int> ans;
    Node* t1 = h1;
    Node* t2 = h2;
    while(t1 != NULL){
        ans.push_back(t1->data);
        t1 = t1->next;
    }
    while(t2 != NULL){
        ans.push_back(t2->data);
        t2 = t2->next;
    }

    sort(ans.begin(), ans.end());

    Node* dummy = new Node(-1);
    Node* curr = dummy;

    for(auto& itr : ans){
        curr->next = new Node(itr);
        curr = curr->next;
    }
    return dummy->next;
}

Node* msLL::MS2LL(Node* h1,Node* h2){
    Node* t1 = h1;
    Node* t2 = h2;

    Node* dummy = new Node(-1);
    Node* curr = dummy;
    while(t1 != NULL && t2 != NULL){
        if(t1->data <= t2->data){
            curr->next = new Node(t1->data);
            curr = curr->next;
            t1 = t1->next;
        } else {
            curr->next = new Node(t2->data);
            curr = curr->next;
            t2 = t2->next;
        }
    }
    /*while(t1 != NULL){
        curr->next = new Node(t1->data);
        curr = curr->next;
        t1 = t1->next;
    }
    while(t2 != NULL){
        curr->next = new Node(t2->data);
        curr = curr->next;
        t2 = t2->next;
    }*/
   if(h1 != NULL){
      curr->next = t1;
   } else {
       curr->next = t2;
   }
    return dummy->next;
}

int main(){
    msLL root;
    root.inserNodeAtEnd(2);
    root.inserNodeAtEnd(7);
    root.inserNodeAtEnd(17);
    root.inserNodeAtEnd(40);
    root.inserNodeAtEnd(45);
    root.inserNodeAtEnd(50);
    root.inserNodeAtEnd(55);
    cout << "Element in the linked list :\n";
    root.display();
    msLL root1;
    root1.inserNodeAtEnd(5);
    root1.inserNodeAtEnd(10);
    root1.inserNodeAtEnd(15);
    root1.inserNodeAtEnd(20);
    cout << "\nElement in the linked list :\n";
    root1.display();

    /*Node* root2 = msLL::mergeLL(root.head, root1.head);

    cout << "\nMerged sorted Element in the linked list :\n";
    while(root2){
        cout << root2->data << " ";
        root2 = root2->next;
    }*/

    Node* root3 = msLL::mergeLL(root.head, root1.head);

    cout << "\nMerged sorted Element in the linked list 2nd method :\n";
    while(root3){
        cout << root3->data << " ";
        root3 = root3->next;
    }
}