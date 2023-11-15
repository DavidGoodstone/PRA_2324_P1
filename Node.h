#ifndef NODE_H
#define NODE_H
#include <ostream>

template <typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node(T data, Node<T>* next=nullptr){
			this->data = data;
			this->next = next;
		}

		// Declaración de la función amiga
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &Node){
			out << Node.data;
			
			return out;
		}
};

#endif
