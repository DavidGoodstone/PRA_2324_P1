#include <ostream>
#include "List.h"

template <typename T>

class Node : public List<T>{
	public:
		T data;
		Node<T>* next;
		Node(T data, Node<T>* next=nullptr);
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &Node);
};
