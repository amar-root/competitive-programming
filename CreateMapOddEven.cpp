#include <iostream>
#include <stack>

using namespace std;

struct Node
{
    /* data */
    int data;
    Node* left, *right;

    Node() : data(0), left(nullptr), right(nullptr){}
    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

class Solution{
    public:
        void zigzag(Node* root){
            if(root == NULL) 
                return;

            stack<Node*> s1,s2;

            s1.push(root);

            while(!s1.empty() || !s2.empty()){
                while (!s1.empty())
                {
                    Node* curr = s1.top();
                    s1.pop();

                    cout << curr->data << " ";

                    if(curr->left)
                        s2.push(curr->left);

                    if(curr->right)
                        s2.push(curr->right);
                }
                while (!s2.empty())
                {
                    Node* curr = s2.top();
                    s2.pop();

                    cout << curr->data << " ";

                    if(curr->right)
                        s1.push(curr->right);

                    if(curr->left)
                        s1.push(curr->left);
                }    
                
            }
        }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution s;

    cout << "Spiral Traversal of tree : \n";

    s.zigzag(root);
}
