//
// Question Link: 
// https://www.hackerrank.com/challenges/swap-nodes-algo/problem
//

#include <bits/stdc++.h>

using namespace std;


struct Node {
        unsigned int data;
        unsigned int layer;
        Node *left;
        Node *right;
        Node(unsigned int d, unsigned int l) {
            data = d;
            layer  = l;
            left = NULL;
            right = NULL;
        }
};

void InOrder_tree(Node *root, vector<int>& result){
        if (NULL != root->left){
            InOrder_tree(root->left, result);
        }
        
        result.push_back(root->data); 
        
        if (NULL != root->right){
            InOrder_tree(root->right, result);
        } 
}
/*
 * Complete the swapNodes function below.
 */
vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    vector<vector<int>> result;
    queue<Node *> nodeQ;

    // Build a tree
    Node *root = new Node(1,1);
    nodeQ.push(root);
    unsigned int thisLayerCount = 1, nextLayerCount = 0, currentLayerid = 2;
    for (unsigned int i = 0; i < indexes.size(); i++){
        if (thisLayerCount == 0){
            thisLayerCount = nextLayerCount;
            nextLayerCount = 0;
            currentLayerid++;
        }
        Node *chkpt = nodeQ.front();
        nodeQ.pop();
        thisLayerCount--;
        if (indexes[i][0] != -1){
            chkpt->left = new Node(indexes[i][0], currentLayerid);
            nodeQ.push(chkpt->left);
            nextLayerCount++;
        }
        if (indexes[i][1] != -1){
            chkpt->right = new Node(indexes[i][1], currentLayerid);
            nodeQ.push(chkpt->right);
            nextLayerCount++;
        }
    }


    //Referring to the second last layer
    currentLayerid -= 2;

    //Solve Queries
    for (unsigned int i = 0; i < queries.size(); i++){
        //for the H belongs to {K, 2K, 3K, ...} thing
        vector<int> intermitent_result;
        unordered_set<int> chkLayer;           // as the search operation is O[1]
        {
            //Scope limitation
            int tempQuery = queries[i];
            int tempCheck = tempQuery;
            int tempIncreament = 1;
            while (tempCheck <= currentLayerid){
                chkLayer.insert(tempCheck);
                tempCheck = tempQuery * (++tempIncreament);
            }
        }
        
        nodeQ.push(root);
        while(!nodeQ.empty()){
            Node *chkpt = nodeQ.front();
            if (chkLayer.end() != chkLayer.find(chkpt->layer)){
                Node *temp = chkpt->left;
                chkpt->left = chkpt->right;
                chkpt->right = temp;
            }
            
            if (chkpt->left != NULL){
                nodeQ.push(chkpt->left);
            }

            if (chkpt->right != NULL){
                nodeQ.push(chkpt->right);
            } 
            nodeQ.pop();           

        }

        InOrder_tree(root, intermitent_result);
        result.push_back(intermitent_result);
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> indexes(n);
    for (int indexes_row_itr = 0; indexes_row_itr < n; indexes_row_itr++) {
        indexes[indexes_row_itr].resize(2);

        for (int indexes_column_itr = 0; indexes_column_itr < 2; indexes_column_itr++) {
            cin >> indexes[indexes_row_itr][indexes_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int queries_itr = 0; queries_itr < queries_count; queries_itr++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[queries_itr] = queries_item;
    }

    vector<vector<int>> result = swapNodes(indexes, queries);

    for (int result_row_itr = 0; result_row_itr < result.size(); result_row_itr++) {
        for (int result_column_itr = 0; result_column_itr < result[result_row_itr].size(); result_column_itr++) {
            fout << result[result_row_itr][result_column_itr];

            if (result_column_itr != result[result_row_itr].size() - 1) {
                fout << " ";
            }
        }

        if (result_row_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
