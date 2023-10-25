#include <iostream>
using namespace std;

template <class T> class DoubleLinkedList;
template <class T> class dChainNode {
    friend class DoubleLinkedList<T>; // this means DoubleLinkedList could use
                                      // everything in class
                                      // dChainNode(private/public)
  private:
    T data;
    dChainNode<T>* next;
    dChainNode<T>* prev;

  public:
    dChainNode(const T& D) {
        this->data = D;
        this->next = NULL;
        this->prev = NULL;
    }
    void printNode() { cout << this->data << ' '; }
};

template <class T> class DoubleLinkedList {
  private:
    dChainNode<T>* first;
    dChainNode<T>* last;

  public:
    DoubleLinkedList() { this->first = this->last = NULL; }

    // Print the entire list
    void printList() {
        dChainNode<T>* curNode = this->first;
        while (curNode) {
            curNode->printNode();
            curNode = curNode->next;
        }
        cout << endl;
    }

    // get the Node at a specific position
    dChainNode<T>* getNode(int pos) {
        if (pos < 0) {
            cout << "invalid position\n";
            return NULL;
        }
        dChainNode<T>* target = this->first;
        for (int p = 0; p < pos && target != NULL; p++) {
            target = target->next;
        }
        if (target == NULL) {
            cout << "cannot find the node at this position: " << pos << "\n";
        }
        return target;
    }

    // Append a node to the end of the list
    void appendNode(T data) {
        dChainNode<T>* newNode = new dChainNode<T>(data);
        if (last == NULL) {
            first = last = newNode;
        } else {
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
    }

    // Delete a node at a specific position
    void deleteNode(int pos) {
        dChainNode<T>* target = getNode(pos);
        if (!target) {
            return;
        }
        // There is the only one node in DL
        if (target == first && target == last) {
            last = first = NULL;
        }
        // the deleteNode is the first node
        else if (target == first) {
            this->first = target->next;
            target->next->prev = NULL;
        }
        // the deleteNode is the last node
        else if (target == last) {
            this->last = target->prev;
            target->prev->next = NULL;
        }
        // the deleteNode is the middle node
        else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }
        delete target;
    }

    // insertNode: insert a new Node in the specific position
    void insertNode(int pos, T data) {
        // your code goes here
		if (pos == 0){
			dChainNode<T>* newNode = new dChainNode<T>(data);
			newNode->prev = 0;
			first->prev = newNode;
			newNode->next = first;
			first = newNode;
			return;
		}
		dChainNode<T>* insertNode = getNode(pos);
		if (insertNode == 0)
			return;
		dChainNode<T>* newNode = new dChainNode<T>(data);
		newNode->prev = insertNode->prev;
		insertNode->prev = newNode;
		newNode->next = insertNode;
		newNode->prev->next = newNode;
    }
};

int main(void) {
    DoubleLinkedList<char>* DLL = new DoubleLinkedList<char>;

    DLL->appendNode('d');
    DLL->appendNode('s');
    DLL->appendNode('t');
    DLL->appendNode('a');

    DLL->deleteNode(5); // cannot find the node at this position: 5
    DLL->printList();   // d s t a
    DLL->deleteNode(3);
    DLL->printList(); // d s t
    DLL->insertNode(0, '!');
    DLL->printList(); // ! d s t
    DLL->insertNode(1, '*');
    DLL->printList();        // ! * d s t
    DLL->insertNode(6, '/'); // cannot find the node at this position: 6
    DLL->printList();        // ! * d s t

    return 0;
}
