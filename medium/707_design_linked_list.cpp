/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

using namespace std;

// @lc code=start
struct Node
{
	Node* next;
	//Node* prev;

	int val;

	Node() : next(0), val(0) {}
	Node(int v) : next(0), val(v) {}

	Node(int v, Node* next) : next(next), val(v) {}

	// Node(int v, Node* next, Node* prev) : next(next), prev(prev), val(v) {}

	// Node(Node& node) : next(node.next), prev(node.prev), val(node.val) {}
};



class MyLinkedList {
	int size;
	Node* head;
	Node* tail;

	Node* at(int index) {
		Node* node = head;

		while(index--)
			node = node->next;

		return node;
	}

	bool isValidIndex(int index) {
		return (0 <= index && index < size);
	}

public:
	MyLinkedList() {
		size = 0;
		head = nullptr;
		tail = nullptr;
	}

	int get(int index) {
		if(isValidIndex(index))
			return at(index)->val;
		else return -1;
	}

	void addAtHead(int val) {
		head = new Node(val, head);

		if(tail == nullptr)
			tail = head;

		size++;
	}

	void addAtTail(int val) {
		// not first element
		if(tail != nullptr) {
			tail->next = new Node(val, 0);
			tail = tail->next;
		}
		else // first element
			head = tail = new Node(val, 0);

		size++;
	}

	void addAtIndex(int index, int val) {
		if(index == 0)
			addAtHead(val);
		else if(index == size)
			addAtTail(val);
		else if(isValidIndex(index)) {

			Node* prec = at(index - 1);
			prec->next = new Node(val, prec->next);
			size++;
		}
	}

	void deleteAtIndex(int index) {
		if(!isValidIndex(index) || size == 0)
			return;
		else if(index == 0) {
			auto next = head->next;
			delete head;
			head = next;

			if(--size == 0)
				tail = nullptr;

		}
		else if(index == size - 1) {
			delete tail;
			if(--size == 0)
				tail = head = nullptr;
			else
				tail = at(index - 1);
		}
		else {
			auto prev = at(index - 1);
			auto next = prev->next->next;
			delete prev->next;
			prev->next = next;
			size--;
		}

	}
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

int main(int argc, char const* argv[])
{
	MyLinkedList list;
	list.addAtHead(2);
	list.deleteAtIndex(1);
	list.addAtHead(2);
	list.addAtHead(7);
	list.addAtHead(3);
	list.addAtHead(2);
	list.addAtHead(5);
	list.addAtTail(5);
	list.get(5);
	list.deleteAtIndex(6);
	list.deleteAtIndex(4);

	// list.addAtHead(7);
	// list.addAtHead(2);
	// list.addAtHead(1);
	// list.addAtIndex(3, 0);
	// list.deleteAtIndex(2);
	// list.addAtHead(6);
	// list.addAtTail(4);
	// list.get(4);
	// list.addAtHead(4);
	// list.addAtIndex(5, 0);
	// list.addAtHead(6);

	return 0;
}


