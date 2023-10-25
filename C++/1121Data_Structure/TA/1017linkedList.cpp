#include <iostream>
using namespace std;

template <class T> class Chain;
template <class T>
class ChainNode {
	friend class Chain <T>; //this means Chain could use everything in clas ChainNode(private/public)
	private:
	T data;
	ChainNode <T> *link;

	public:
	ChainNode (const T& D) {
		this->data = D;
		this->link = NULL;
	}

	void setNextNode(ChainNode<T> *nextNode){
		this->link = nextNode;
	}

	void printNode(){
		cout << this-> data<<' ';
	}

};

template <class T>
class Chain {

	private:
		ChainNode <T> *first;

	public:
		Chain(){
			first=0;
		}
		// setFirstNode: this function is used to tell Chain who's the first Node
		void setFirstNode(ChainNode<T> *node){
			this->first = node;
		}
		// printList: print all Node's data one by one
		void printList(){
			ChainNode<T> *curNode = this->first;
			while(curNode){
				curNode->printNode();
				curNode = curNode->link;
			}
			cout<<endl;

		}

		// getNode: get(return) the Node at the specific position
		ChainNode <T> * getNode(int pos){
			ChainNode <T> *target = this->first;
			for(int i = 0;i < pos; i++){
				//if the pos is much bigger then Chain's len, we break and return the last node
				if(target->link == NULL){
					break;
				}
				target = target->link;
			}
			return target;
		}
		// insertNode: insert a new Node in the specific position
		void insertNode(int pos,T data){
			ChainNode <T> *newNode = new ChainNode <T> (data);
			ChainNode <T> *target = getNode(pos);
			if(pos == 0){
				newNode->link = target;
				this->first = newNode;
			}else{
				ChainNode <T> *prev = getNode(pos-1);
				ChainNode <T> *tmp = prev->link;
				prev->link = newNode;
				newNode->link = tmp;
			}
		}
		// deleteNode:delete the Node in the specific position
		void deleteNode(int pos){
			ChainNode <T> *target = getNode(pos);
			if((pos-1) < 0){// no beforeNode, we delete the first one
				this->first = this->first->link;
			}else{
				ChainNode <T> *prev = getNode(pos-1);
				prev->link = target->link;
			}
		}
		void deleteElements(T data){
			//your code here
			ChainNode<T>* currentNode = first;
			ChainNode<T>* previousNode = 0;
			while (currentNode){
				if (currentNode->data == data){
					if (previousNode){
						previousNode->link = currentNode->link;
						delete currentNode;
						currentNode = previousNode->link;
					}
					else{
						first = first->link;
						delete currentNode;
						currentNode = first;
					}
				}
				previousNode = currentNode;
				currentNode = currentNode->link;
			}
		}
};

int main(void){
	// create a new Node
	ChainNode <char> * fn = new ChainNode <char> ('h');
	// ChainNode <char> * sn = new ChainNode <char> ('s');
	// fn->setNextNode(sn);

	// Create a linked list named LS
	Chain <char> *LS = new Chain<char>;
	LS->setFirstNode(fn);
	// add 7 Node to LS
	LS->insertNode(1,'k');
	LS->insertNode(2,'i');
	LS->insertNode(3,'g');
	LS->insertNode(4,'s');
	LS->insertNode(5,'i');
	LS->insertNode(6,'h');
	LS->insertNode(7,'k');
	LS->insertNode(8,'s');
	LS->insertNode(9,'r');
	LS->printList(); //h k i g s i h k s r

	LS->deleteElements('h');
	LS->printList(); // k i g s i k s r
	LS->deleteElements('s');
	LS->printList(); // k i g i k r
	LS->deleteElements('i');
	LS->printList(); // k g k r
	return 0;
}
