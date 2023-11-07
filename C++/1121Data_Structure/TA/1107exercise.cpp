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

		int GetKey(){return key;}              // 為了在main()要能夠檢視node是否正確
		string GetElement(){return element;}   // 才需要這兩個member function讀取private data

		// 其餘情況, 因為class BST是class TreeNode的friend class
		// 在class BST的member function中, 可以直接存取class TreeNode的private data

		friend class BST;   // 放在 private 或 public 都可以
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

	TreeNode *current = root;               // 將curent指向root作為traversal起點

	while (current != NULL && KEY != current->key) {  // 兩種情況跳出迴圈：
		// 1.沒找到 2.有找到
		if (KEY < current->key){
			current = current->leftchild;   // 向左走
		}
		else {
			current = current->rightchild;  // 向右走
		}
	}
	return current;
}
void BST::InsertBST(int key, string element){

	TreeNode *parent_node = 0;
	TreeNode *insert_position = 0;
	TreeNode *new_node = new TreeNode(key, element);

	insert_position = root;
	while (insert_position != NULL) {                // 類似Search的方式尋找適當的嵌入位置
		parent_node = insert_position;
		if (new_node->key < insert_position->key){
			insert_position = insert_position->leftchild;
		}
		else{
			insert_position = insert_position->rightchild;
		}
	}                                  // 跳出迴圈後, insert_position即為NULL，而parent_node則是new_node的parent

	new_node->parent = parent_node;           // 將new_node的parent pointer指向parent_node

	if (parent_node == NULL){                    // 下面一組if-else, 把new_node接上BST
		// your code here
		root = new_node;
	}
	else if (new_node->key < parent_node->key){
		// your code here
		parent_node->leftchild = new_node;
	}
	else{
		// your code here
		parent_node->rightchild = new_node;
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
	q.push(this->root);					    // 把root作為level-order traversal之起點
	// 推進queue中
	while (!q.empty()){                     // 若queue不是空的, 表示還有node沒有visiting

		TreeNode *current = q.front();      // 取出先進入queue的node
		q.pop();
		cout << current->element << "(" << current->key << ")" << " ";

		if (current->leftchild != NULL){    // 若leftchild有資料, 將其推進queue
			q.push(current->leftchild);
		}
		if (current->rightchild != NULL){   // 若rightchild有資料, 將其推進queue
			q.push(current->rightchild);
		}
	}
}

int main(){
	BST T;

	T.InsertBST(8,"陸");
	T.InsertBST(1000,"悠人");
	T.InsertBST(2,"伊藤");
	T.InsertBST(513,"神木");
	T.InsertBST(245,"御子");
	T.InsertBST(5,"優");
	T.InsertBST(1,"藤原");


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
}
