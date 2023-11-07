// C++ code
#include <iostream>
#include <string>
#include <queue>

using std::string;
using std::cout;
using std::endl;

class BST;
class TreeNode{
private:
    TreeNode *leftchild;
    TreeNode *rightchild;
    TreeNode *parent;
    int key;
    string element;
public:
    TreeNode():leftchild(0),rightchild(0),parent(0),key(0),element(""){};
    TreeNode(int a, string b):leftchild(0),rightchild(0),parent(0),key(a),element(b){};

    int GetKey(){return key;}              // ���F�bmain()�n����˵�node�O�_���T
    string GetElement(){return element;}   // �~�ݭn�o���member functionŪ��private data

    // ��l���p, �]��class BST�Oclass TreeNode��friend class
    // �bclass BST��member function��, �i�H�����s��class TreeNode��private data

    friend class BST;   // ��b private �� public ���i�H
};

class BST{
private:
    TreeNode *root;
    TreeNode* Leftmost(TreeNode *current);
    TreeNode* Successor(TreeNode *current);

public:
    BST():root(0){};
    TreeNode* Search(int key);
    void InsertBST(int key, string element);
    void InorderPrint();
    void Levelorder();
};
TreeNode* BST::Search(int KEY){

    TreeNode *current = root;               // �Ncurent���Vroot�@��traversal�_�I

    while (current != NULL && KEY != current->key) {  // ��ر��p���X�j��G
    	                                              // 1.�S��� 2.�����
        if (KEY < current->key){
            current = current->leftchild;   // �V����
        }
        else {
            current = current->rightchild;  // �V�k��
        }
    }
    return current;
}
void BST::InsertBST(int key, string element){

    TreeNode *y = 0;
    TreeNode *x = 0;
    TreeNode *insert_node = new TreeNode(key, element);

    x = root;
    while (x != NULL) {                // ����Search���覡�M��A���O�J��m
        y = x;
        if (insert_node->key < x->key){
            x = x->leftchild;
        }
        else{
            x = x->rightchild;
        }
    }                                  // ���X�j���, x�Y��NULL�A��y�h�Oinsert_node��parent

    insert_node->parent = y;           // �Ninsert_node��parent pointer���Vy

    if (y == NULL){                    // �U���@��if-else, ��insert_node���WBST
       //
    }
    else if (insert_node->key < y->key){
        //

    }
    else{
       //
    }
}
TreeNode* BST::Leftmost(TreeNode *current){

    while (current->leftchild != NULL){
        current = current->leftchild;
    }
    return current;
}
TreeNode* BST::Successor(TreeNode *current){

    if (current->rightchild != NULL){
        return Leftmost(current->rightchild);
    }

    TreeNode *new_node = current->parent;

    while (new_node != NULL && current == new_node->rightchild) {
        current = new_node;
        new_node = new_node->parent;
    }

    return new_node;
}
void BST::InorderPrint(){
    TreeNode *current = new TreeNode;
    current = Leftmost(root);
    while(current){
        cout << current->element << "(" << current->key << ")" << " ";
        current = Successor(current);
    }
}

void BST::Levelorder(){

    std::queue<TreeNode*> q;
    q.push(this->root);					    // ��root�@��level-order traversal���_�I
    								        // ���iqueue��
    while (!q.empty()){                     // �Yqueue���O�Ū�, ����٦�node�S��visiting

    	TreeNode *current = q.front();      // ���X���i�Jqueue��node
    	q.pop();
    	cout << current->element << "(" << current->key << ")" << " ";

    	if (current->leftchild != NULL){    // �Yleftchild�����, �N����iqueue
            q.push(current->leftchild);
        }
        if (current->rightchild != NULL){   // �Yrightchild�����, �N����iqueue
            q.push(current->rightchild);
        }
    }
}

int main(){
    BST T;

    T.InsertBST(8,"��");
    T.InsertBST(1000,"�y�H");
    T.InsertBST(2,"����");
    T.InsertBST(513,"����");
    T.InsertBST(245,"�s�l");
    T.InsertBST(5,"�u");
    T.InsertBST(1,"�í�");


    cout << "Inorder Traversal:\n";
    T.InorderPrint();
    cout << endl;
    cout << "Level-order Traversal:\n";
    T.Levelorder();
    cout << endl;

    TreeNode *node = T.Search(1000);
    if(node != NULL){
    	cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
    	cout << "no element with Key(1000)" << endl;
    }

    node = T.Search(73);
    if(node != NULL){
    	cout << "There is " << node->GetElement() << "(" << node->GetKey() << ")" << endl;
    }
    else {
    	cout << "no element with Key(73)" << endl;
    }

    return 0;
};
