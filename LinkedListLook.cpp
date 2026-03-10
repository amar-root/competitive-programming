#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};
class llLoop{
    public:
        Node* head;
        llLoop(){
            head = nullptr;
        }

        void insertAtHead(int val){
            Node* nn = new Node(val);
            if(head == NULL){
                head = nn;
                return;
            }
            nn->next = head;
            head = nn;
        }
        
        void createLoop(int pos){
            if(head == NULL) return;

            Node* loopNode = nullptr;
            Node* temp = head;
            int count = 1;

            while(temp->next){
                if(count == pos){
                    loopNode = temp;
                    break;
                }
                temp = temp->next;
                count++;
            }
            if (loopNode)
                temp->next = loopNode;
        }
        Node* detectLoop(){
            if(!head) return nullptr;

            Node* slow = head;
            Node* fast = head;

            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;

                cout << "slow data : " << slow->data << " ";
                cout << "fast data : " << fast->data << endl;
                if(slow == fast){
                    return slow;
                }
            }
            return nullptr;
        }

        Node* findLoop(){
            Node* mp = detectLoop();

            Node* ptr1 = head;
            Node* ptr2 = mp;

            while (ptr1 != ptr2)
            {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return ptr1;
        }
        void display(){
            Node* temp = head;
            while(temp != nullptr){
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
};
int main(){
    llLoop root;
    root.insertAtHead(9);
    root.insertAtHead(8);
    root.insertAtHead(7);
    root.insertAtHead(6);
    root.insertAtHead(5);
    root.insertAtHead(4);
    root.insertAtHead(3);
    root.insertAtHead(2);
    root.insertAtHead(1);

    cout << "Linked list is : \n";
    root.display();

    root.createLoop(5);
    
    cout << endl;
    Node* startNode = root.findLoop();

    if(startNode){
        cout << "\nLoop detected at node : " << startNode->data;
    } else {
        cout << "\nLoop not detected\n";
    }
}