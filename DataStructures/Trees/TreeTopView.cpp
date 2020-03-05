//
// Question link:
// https://www.hackerrank.com/challenges/tree-top-view/copy-from/120517510
//


#include<bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/


    void topView(Node * root) {
        Q.push(make_pair(root, 0));
        sequence.insert({0, root->data});
        while (!Q.empty()){
            Node* chkpt = Q.front().first;
            int hd = Q.front().second;
            if (chkpt->left != NULL){
                Q.push(make_pair(chkpt->left, hd - 1));
                if (sequence.find(hd - 1) == sequence.end()){
                    sequence.insert({hd - 1, chkpt->left->data});
                }
            }
            if (chkpt->right != NULL){
                Q.push(make_pair(chkpt->right, hd + 1));
                if (sequence.find(hd + 1) == sequence.end()){
                    sequence.insert({hd + 1, chkpt->right->data});
                }
            }
            Q.pop();
        }

        for (map<int, int>::iterator it = sequence.begin(); it != sequence.end(); it++){
            cout << it->second << " ";
        }
    }

    queue<pair<Node *, int>> Q;
    map<int, int> sequence;

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.topView(root);
    return 0;
}
