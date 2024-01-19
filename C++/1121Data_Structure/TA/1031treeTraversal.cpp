#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Node
{
		public:
		string data;
		Node *leftchild;
		Node *rightchild;
		int level;

		Node(string d)
		{
				this->data = d;
				this->leftchild = NULL;
				this->rightchild = NULL;
				level = 0;
		}

		void insertLeft(Node *link)
		{
				if (!this->IsLeftNode()) {
						this->leftchild = link;
						this->leftchild->level = this->level + 1;
				}
		}

		void insertRight(Node *link)
		{
				if (!this->IsRightNode()) {
						this->rightchild = link;
						this->rightchild->level = this->level + 1;
				}
		}

		bool IsRightNode()
		{
				if (this->rightchild != NULL)
						return 1;
				else
						return 0;
		}

		bool IsLeftNode()
		{
				if (this->leftchild != NULL)
						return 1;
				else
						return 0;
		}
};

class Tree
{
		public:
		int hieght;
		Node *root;

		Tree()
		{
				this->root = NULL;
		}

		bool isRoot()
		{
				if (this->root != NULL)
						return 1;
				else
						return 0;
		}

		void setRoot(Node *N)
		{
				this->root = N;
		}

		void preorder(Node *N) // complete this function using recursive method
		{
				if (N == 0)
						return;
				cout << " " << N->data << " level: " << N->level << endl;
				preorder(N->leftchild);
				preorder(N->rightchild);
		}

		void inorder(Node *N) // complete this function using recursive method
		{
				if (N == 0)
						return;
				inorder(N->leftchild);
				cout << " " << N->data << " level: " << N->level << endl;
				inorder(N->rightchild);
		}

		void postorder(Node *N) // complete this function using recursive method
		{
				if (N == 0)
						return;
				postorder(N->leftchild);
				postorder(N->rightchild);
				cout << " " << N->data << " level: " << N->level << endl;
		}

		void levelorder(Node *N)
		{
				queue<Node *> q;
				q.push(N);
				while (!q.empty()) {
						Node *current = q.front();
						q.pop();
						cout << " " << current->data << " level: " << current->level << endl;
						if (current->leftchild != NULL)
								q.push(current->leftchild);
						if (current->rightchild != NULL)
								q.push(current->rightchild);
				}
		}
};

int main()
{
		string formulation[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
		Tree skillTree;
		Node *nodelist[10]; //存的是node的記憶體位址
		for (int i = 0; i < 10; i++) {
				nodelist[i] = new Node(formulation[i]);
				//cout <<"node"<< i << nodelist[i]->getdata()<<endl;
		}
		skillTree.setRoot(nodelist[0]);
		nodelist[0]->insertLeft(nodelist[1]);
		nodelist[0]->insertRight(nodelist[2]);
		nodelist[1]->insertLeft(nodelist[3]);
		nodelist[1]->insertRight(nodelist[4]);
		nodelist[2]->insertLeft(nodelist[5]);
		nodelist[3]->insertLeft(nodelist[6]);
		nodelist[3]->insertRight(nodelist[7]);
		nodelist[4]->insertRight(nodelist[8]);
		nodelist[5]->insertRight(nodelist[9]);

		cout << "Preorder: " << endl;
		skillTree.preorder(skillTree.root);
		cout << "\nInorder: " << endl;
		skillTree.inorder(skillTree.root);
		cout << "\nPostorder: " << endl;
		skillTree.postorder(skillTree.root);
		cout << "\nLevelorder: " << endl;
		skillTree.levelorder(skillTree.root);

		return 0;
}
