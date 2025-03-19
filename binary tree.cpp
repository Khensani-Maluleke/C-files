#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class TreeNode{
public:
    // Pointer to the left child
    //  Initialised to nullptr (this syntax is a new C++11 feature)
    TreeNode* left = nullptr;
    // Pointer to the right child
    //  Initialised to nullptr (this syntax is a new C++11 feature)
    TreeNode* right = nullptr;

    // Value in the node
    int value;

    // Constructor, sets the value
    TreeNode(int v) : value(v) {}
    // Destructor, nifty trick to recursively delete all the nodes
    //  be careful though, when you delete just a single node, make
    //  sure that you set left and right = nullptr first
    ~TreeNode() {
        delete left;
        delete right;
    }
};

class Tree{
private:
    TreeNode* root = nullptr;

public:
    // These functions do the actual work
    int nodenumber =0;
    void insert(int v, TreeNode* &subtree){
        if(subtree == nullptr){
           subtree = new TreeNode(v);
        }else if(v < subtree->value){
            insert(v, subtree->left);
        }else{
            insert(v, subtree->right);
        }
    }

    void preOrderTraversal(TreeNode* subtree) const{
        TreeNode * curr = subtree;
        if (curr== nullptr){
            return;
        }
        cout<<curr->value<<' ';
        preOrderTraversal(curr->left);
        preOrderTraversal(curr->right);




    }

    void inOrderTraversal(TreeNode* subtree) const{
        TreeNode * curr = subtree;
        if (curr == nullptr){
            return;
        }
        inOrderTraversal(curr->left);
        cout<<curr->value<<' ';
        inOrderTraversal(curr->right);



    }

    void postOrderTraversal(TreeNode* subtree) const{
        TreeNode * curr = subtree;
        if (curr == nullptr){
            return;
        }
        postOrderTraversal(curr->left);
        //cout<<curr->value<<' ';
        postOrderTraversal(curr->right);
        cout<<curr->value<<' ';





    }

    int min(TreeNode* subtree) const{
        TreeNode*curr = subtree;
        if (curr->left== nullptr){
            return curr->value;
        }

            min(curr->left);


    }
    void node(TreeNode* subtree) {
        TreeNode * curr = subtree;
        if (curr == nullptr){
            return;
        }
        node(curr->left);
        nodenumber +=1;
        node(curr->right);

    }
    int max(TreeNode* subtree) const{
        TreeNode*curr = subtree;
        if (curr->right== nullptr){
            cout<<curr->value<<endl;
        }
        else {
            max(curr->right);
        }

    }

    void deleteleaves(TreeNode *subtree){
        if (subtree == nullptr){
            return;
        }

        if (subtree->left == nullptr && subtree->right == nullptr){
            delete subtree;
            subtree = nullptr;
        }
        else if (subtree->right == nullptr){
            deleteleaves(subtree->left);

        }
        else if (subtree ->left == nullptr ){
            deleteleaves(subtree->right);

        }
        else {
            deleteleaves(subtree->left);
            deleteleaves(subtree->right);
        }



    }
    bool contains(int value, TreeNode* subtree) const{
        TreeNode *curr = subtree;
        if (curr == nullptr){
            return false;
        }
        else
            if (value > curr->value){
                contains(value,subtree->right);
            }
            else if (value < curr->value){
                contains(value,subtree->left);

            }
            else{
                return true;
            }


    }
    void remove(int value, TreeNode* &subtree){
        //TreeNode *curr = subtree;
        if (subtree == nullptr){
            return;
        }
        if (subtree->value == value) {
            if (subtree->left == nullptr && subtree->right == nullptr) {
                delete subtree;
                subtree = nullptr;
            } else if (subtree->left != nullptr && subtree->right == nullptr) {
                TreeNode *tmp = subtree->left;
                subtree->left = nullptr;
                delete subtree;
                subtree = tmp;
            } else if (subtree->left == nullptr && subtree->right != nullptr) {
                TreeNode *tmp = subtree->right;
                subtree->right = nullptr;
                delete subtree;
                subtree = tmp;
            } else {
                subtree->value = min(subtree->right);
                remove(subtree->value, subtree->right);
            }
        } else if (value < subtree->value){
            remove(value,subtree->left);
        }else{
            remove(value,subtree->right);
        }




    }



    void insert(int value){
        insert(value, root);
    }

    void preOrderTraversal(){
        preOrderTraversal(root);
        cout << endl;
    }
    void inOrderTraversal(){
        inOrderTraversal(root);
        cout << endl;
    }
    void postOrderTraversal(){
        postOrderTraversal(root);
        cout << endl;
    }
    int min(){
        return min(root);
    }
    int max(){
        return max(root);
    }
    bool contains(int value){
        return contains(value, root);
    }
    void remove(int value){
        remove(value, root);
    }
    void node(){
        node(root);
    }
    void deleteleaves(){
        deleteleaves(root);
    }
    ~Tree(){
        // This ends up deleting all the nodes recursively.
        delete root;
    }
};

int main(){
    Tree t;
    int value;
    //int root;
    // Sample code to read and construct the tree.
    while(cin >> value && value != -1){
        t.insert(value);
    }
    t.node();
    int height = log2(t.nodenumber+1)-1;//method 1 to calculate the height(using the number of nodes)


   // cout<<height;
   t.deleteleaves();
   t.inOrderTraversal();







}
