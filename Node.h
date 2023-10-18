#include <ostream>

template <typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node(T data, Node<T>* next=nullptr);
		// Declaración de la función amiga
    		template <typename U>
		friend std::ostream& operator<<(std::ostream &out, const Node<T> &Node);
};
