#ifndef LISTLINKED_H
#define LISTLINKED_H
#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>

class ListLinked : public List<T>{
	private:
		Node<T>* first;
		int n;
		
	public:
		ListLinked(){
			first = nullptr;
			n = 0;
		}
		~ListLinked(){
			Node<T> *aux = first;
			while(aux != nullptr){
				first = aux->next;
				delete aux;
				aux = first;
			}

			n = 0;
		}

		T operator[](int pos){
			if(pos >= n || pos < 0){
				throw std::out_of_range("Posición fuera del rango de los nodos.");
			}

			Node<T> *aux = first;
			for(int i = 0; i < pos; i++){
				aux = aux->next;
			}

			return aux->data;	
		}

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &List){
			out << "List [ ";

			Node<T> *aux = List.first;
			for(int i = 0; i < List.n; i++){
				out << aux->data << " ";
				aux = aux->next;
			}

			out << "]" << std::endl;

			return out;
		}

		void insert(int pos, T e) override{
			if(pos > n || pos < 0){
                                throw std::out_of_range("Posición fuera del rango de los nodos.");
                        }

			Node<T> *aux = first;
			Node<T> *preaux = nullptr;

			if(pos == 0){
				first = new Node(e, aux);
			}else{
				for(int i = 0; i < pos; i++){
					preaux = aux;
					aux = aux->next;
				}
			
				preaux->next = new Node(e, aux);
			}
			n++;
		}

    		void append(T e) override{
			insert(n, e);
		}

    		void prepend(T e) override{
			insert(0, e);
		}

    		T remove(int pos) override{
			if(pos >= n || pos < 0){
                                throw std::out_of_range("Posición fuera del rango de los nodos.");
                        }

			Node<T> *aux = first;
			Node<T> *preaux = nullptr;

			for(int i = 0; i < pos; i++){
                       		preaux = aux;
                         	aux = aux->next;                                
			}

			if(pos == 0){
				first = aux->next;
			}else{
				preaux->next = aux->next;
			}

			T rem = aux->data;

			delete aux;
			
			n--;

			return rem;
		}

    		T get(int pos) override{
			if(pos >= n || pos < 0){
                                throw std::out_of_range("Posición fuera del rango de los nodos.");
                        }

                        Node<T> *aux = first;
                        for(int i = 0; i < pos; i++){
                                aux = aux->next;
                        }

                        return aux->data;
                }

    		int search(T e) override{
			Node<T> *aux = first;
			for(int i = 0; i < n; i++){
                                if(e == aux->data){
					return aux->data;
				}
				aux = aux->next;
                        }

			return -1;
		}

    		bool empty() override{
			if(n == 0){
				return true;
			}else{
				return false;
			}
		}

		int size() override{
			return n;
		}
};

#endif
