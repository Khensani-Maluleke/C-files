#include <iostream>
#include<queue>
//BY KHENSANI TIYANI MALULEKE
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
    //BY KHENSANI TIYANI MALULEKE
    //  be careful though, when you delete just a single node, make
    //  sure that you set left and right = nullptr first
    ~TreeNode() {
        delete left;
        delete right;
    }
};

//BY KHENSANI TIYANI MALULEKE
class Tree{
private:
    TreeNode* root = nullptr;

public:
    // These functions do the actual work
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

        if(subtree==nullptr){
            return;
        }
        cout<<subtree->value<<" ";
        preOrderTraversal(subtree->left);
        preOrderTraversal(subtree->right);



    }

    void inOrderTraversal(TreeNode* subtree) const{
        if(subtree==nullptr){
            return;

        }

        inOrderTraversal(subtree->left);
        cout<<subtree->value<<" ";
        inOrderTraversal(subtree->right);


    }

    void postOrderTraversal(TreeNode* subtree) const{
        if(subtree==nullptr){
            return;

        }

        postOrderTraversal(subtree->left);
        postOrderTraversal(subtree->right);
        cout<<subtree->value<<" ";

    }


    void levelOrderTraversal(TreeNode* subtree) const{
        if(subtree==nullptr){
            return;
        }
        queue<TreeNode*>q;
        q.push(subtree);

        while(q.size()>0){
            TreeNode*curr=q.front();
            q.pop();
            cout<<curr->value<<" ";

            if(curr->left!=nullptr){
                q.push(curr->left);
            }
            if(curr->right!=nullptr){
                q.push(curr->right);
            }


        }
    }




    int node(TreeNode* subtree) {

            if (subtree == nullptr){
                return 0;
            }
            int leftcount=node(subtree->left);
            int rightcount=node(subtree->right);
            return 1+leftcount+rightcount;
        }




    int min(TreeNode* subtree) const{
        if(subtree==nullptr){
            return 0;
        }
        while(subtree->left!=nullptr){
            subtree=subtree->left;
        }
        cout<<subtree->value<<endl;
        //return subtree->value;

    }
    int max(TreeNode* subtree) const{
        if(subtree==nullptr){
            return 0;
        }

        while(subtree->right!=nullptr){
            subtree=subtree->right;
        }
        cout<<subtree->value<<endl;
        //return subtree->value;

    }
    int height(TreeNode* subtree) const{
        if(subtree==nullptr){
            return -1;
        }
        int lheight=height(subtree->left);
        int rheight=height(subtree->right);

        if(lheight > rheight){ //if the height of the left subtree is greater than the height of the right subtree.
            //BY KHENSANI TIYANI MALULEKE
            return 1 + lheight; //Then return 1 + the height of the left subtree.
        } else {
            return 1 + rheight;//Otherwise return 1 + the height of the right subtree.
        }
    }

    int depth(int value, TreeNode* subtree) const
    {
        int count=0;
        while(subtree!=nullptr)
        {
            if(subtree->value==value){
                break;
            }
            else if(subtree->value>value){
                    subtree=subtree->left;
                    count=count +1;
            }
            else{
                subtree=subtree->right;
                count=count +1;

            }
        }

        return count;
    }

    bool contains(int value, TreeNode* subtree) const
    {
        while(subtree!=nullptr)
        {
            if(subtree->value==value){
                cout<<"true"<<endl;
                return true;
            }
            else if(subtree->value>value){
                    subtree=subtree->left;
            }
            else{
                subtree=subtree->right;
            }
        }
           cout<<"false"<<endl;

        return false;
   }


    void printleaves(TreeNode *subtree){
        if(subtree==nullptr){
            return;
        }
        if(subtree->left==nullptr && subtree->right==nullptr){
            cout<<subtree->value<<" ";
            return;
        }
            printleaves(subtree->left);
            printleaves(subtree->right);
        }

    void deleteleaves(TreeNode* &subtree){
        if(subtree==nullptr){
            return;
        }
        if(subtree->left==nullptr && subtree->right==nullptr){
            delete subtree;
            subtree=nullptr;
            return;
        }
           deleteleaves(subtree->left);
           deleteleaves(subtree->right);
        }


    //GET THE NEXT  BIGGEST NODE
    int getSuccessor(TreeNode* subtree)
    {
        subtree = subtree->right;
        while (subtree != nullptr && subtree->left != nullptr)
            subtree = subtree->left;
            return subtree->value;
    }


     void remove(int value, TreeNode* &subtree){
             //TreeNode *curr = subtree;
             if (subtree == nullptr){
                 return;
             }
             if (value < subtree->value){
                remove(value,subtree->left);
                return;
            }else if(value > subtree->value){
                remove(value,subtree->right);
                return;
            }
             else{
                 //0 children

                 if (subtree->left == nullptr && subtree->right == nullptr) {
                     delete subtree;
                     subtree = nullptr;
                     return;
                 }
                 //1 child
                 if (subtree->left == nullptr ) {
                     TreeNode *tmp = subtree;
                     subtree=subtree->right;
                     tmp->left=nullptr;
                     tmp->right=nullptr;
                     delete tmp;
                     return;

                 }
                 //1 child

                 if (subtree->right == nullptr ) {
                     TreeNode *tmp = subtree;
                     subtree=subtree->left;
                     tmp->left=nullptr;
                     tmp->right=nullptr;
                     delete tmp;
                     return;

                 }
                //2 children
                  else {
                     int numb= min(subtree->right);
                     subtree->value=numb;
                     remove(numb, subtree->right);
                 }

         }
     }



     TreeNode* lowestCommonAncestor(TreeNode* subtree, int value1, int value2) {
             if (subtree == nullptr || !contains(value1, root) || !contains(value2, root)) {
                 return nullptr;
             }

             // If both values are less than current node, LCA is in left subtree
             if (value1 < subtree->value && value2 < subtree->value) {
                 //BY KHENSANI TIYANI MALULEKE
                 return lowestCommonAncestor(subtree->left, value1, value2);
             }

             // If both values are greater than current node, LCA is in right subtree
             if (value1 > subtree->value && value2 > subtree->value) {
                 return lowestCommonAncestor(subtree->right, value1, value2);
             }

             // If one value is less and other is greater, or one of the values equals current node,
             // current node is the LCA
             return subtree;
         }

     // Helper function to calculate the diameter of the tree
//      int diameterHelper(TreeNode* subtree, int& maxDiameter) {
//          if (subtree == nullptr)
     //return 0;


//          // Get the height of the left and right subtrees
//          int leftHeight = diameterHelper(subtree->left, maxDiameter);
//          int rightHeight = diameterHelper(subtree->right, maxDiameter);

//          // Calculate the diameter through the current node
//          maxDiameter = max(maxDiameter, leftHeight + rightHeight);

//          // Return the height of the current node
//          return 1 + max(leftHeight, rightHeight);
//      }
//  };





         // Returns true if the binary tree is a BST
         bool isBST(TreeNode* subtree) {
             if (subtree == nullptr)
                 return true;

             // Check if  left subtree
             //BY KHENSANI TIYANI MALULEKE
             // is greater than current node
             if (subtree->left != nullptr && subtree->left->value > subtree->value)
                 return false;

             // Check if right subtree
             // is smaller than  to current node
             if (subtree->right != nullptr && subtree->right->value < subtree->value)
                 return false;

             // Recursively check if left and right subtrees are BSTs
             return isBST(subtree->left) && isBST(subtree->right);
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

    void levelOrderTraversal(){
        levelOrderTraversal(root);
        cout << endl;
    }

    void node(){
        node(root);
    }
    int min(){
        return min(root);
    }
    int max(){
        return max(root);
    }
    int height(){
        return height(root);
    }
    int depth(int value){
        return depth(value,root);
    }
    bool contains(int value){
        return contains(value, root);
    }

    void remove(int value){
        remove(value, root);
    }
    void printleaves(){
            printleaves(root);
        }

    void deleteleaves(){
            deleteleaves(root);
        }

    int getSuccessor(){
        return getSuccessor(root);
    }
    int Node(){
        return node(root);
     }

//    int diameter() {
//           int maxDiameter = 0;
//           diameterHelper(root, maxDiameter);
//           return maxDiameter;
//       }


    bool isBST(){
        return isBST(root);
    }
    ~Tree(){
        // This ends up deleting all the nodes recursively.
        delete root;
    }
};

int main(){
    Tree t;
    int value;
    // Sample code to read and construct the tree.
    while(cin >> value && value != -1){
        t.insert(value);
    }
    cout<<"preorder"<<endl;
    t.preOrderTraversal();
    cout<<"inorder"<<endl;

    t.inOrderTraversal();
    cout<<"postorder"<<endl;

    t.postOrderTraversal();
    //BY KHENSANI TIYANI MALULEKE
    cout<<"levelorder"<<endl;

    t.levelOrderTraversal();
    cout<<"minimum value"<<endl;

    t.min();
    cout<<"maximum value"<<endl;

    t.max();
    cout<<"height"<<endl;
    cout << t.height() << endl;

    cout<<"depth"<<endl;
    cout << t.depth(7) << endl;

    cout<<"print leaves"<<endl;

    t.printleaves();
    cout<<endl;

    cout<<"numberof nodes"<<endl;
    cout<<t.Node()<<endl;



   cout<<"delete leafnodes"<<endl;

    t.deleteleaves();
    cout<<"postorder after deleting leaves"<<endl;
    t.postOrderTraversal();

    cout<<"get the successor of the root"<<endl;

    cout << t.getSuccessor() << endl;
    cout<<"number of nodes after deleting"<<endl;

    cout << t.Node() << endl;
   // cout<<"diameter"<<endl;

   // t.diameter();

    cout<<"checking if its a bst"<<endl;

    cout << t.isBST() << endl;

//    t.contains(int value, TreeNode* subtree);
//    while(cin >> value && value != -1){
//        t.contains(value);

//}
   int num;
    while (cin >> num && num != -1)
        {       cout<<"remove "<<num<<endl;
                //BY KHENSANI TIYANI MALULEKE
                t.remove(num);
                cout<<"preorder after remove num"<<endl;
                t.preOrderTraversal();
                cout<<"inorder after remove num"<<endl;
                t.inOrderTraversal();
                cout<<"postorder after remove num"<<endl;
                t.postOrderTraversal();
                cout << endl;

            }

}
