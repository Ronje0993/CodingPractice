//
// Question Link:
// https://www.hackerrank.com/challenges/is-binary-search-tree/copy-from/145975104
//


/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
	bool checkNext(Node* node, const int& min, const int& max) {
        if (node->data >= max || node->data <= min){
            return false;
        }
        bool result = true;
        if (node->left != NULL){
            result = checkNext(node->left, min, node->data);
        }
        
        if (node->right != NULL){
            result = result && checkNext(node->right, node->data, max);
        }
        
        return result;
	}

    bool checkBST(Node* root) {    
        if (root != NULL){
            return checkNext(root, -1, 10001);
        }
        return(false);
    }
