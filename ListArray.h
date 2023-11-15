#ifndef LISTARRAY_H
#define LISTARRAY_H
#include <ostream>
#include "List.h"

template <typename T>

class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		void resize(int new_size){
			T* aux = new T[new_size];

			for(int i = 0; i < n; i++){
				aux[i] = arr[i];
			}

			delete []arr;

			arr = aux;

			max = new_size;
		}
		
	public:
		ListArray(){
			arr = new T(MINSIZE);
			max = MINSIZE;
			n = 0;	
		}

		~ListArray(){
			delete []arr;
		}

		T operator[](int pos){
			if(pos >= n || pos < 0){
				throw std::out_of_range("Posición fuera del rango del array.");
			}

			return arr[pos];
		}

		// Declaración de la función amiga
    		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			out << "List [ ";

			for(int i = 0; i < list.n; i++){
				out << list.arr[i] << " ";
			}

			out << "]" << std::endl;

			return out;
		}

		void insert(int pos, T e) override{
			if(pos > n || pos < 0){
                                throw std::out_of_range("Posición fuera del rango del array.");
                        }
			
			if(n == max){
				resize(n + 20);
			}
			
			for(int i = n - 1; i >= pos; i--){
				arr[i + 1] = arr[i];
			}

			arr[pos] = e;

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
                                throw std::out_of_range("Posición fuera del rango del array.");
                        }

			T aux = arr[pos];

			for(int i = pos; i < n; i++){
                                arr[i] = arr[i + 1];
                        }

			n--;

			return aux;

		}

    		T get(int pos) override{
			if(pos >= n || pos < 0){
                                throw std::out_of_range("Posición fuera del rango del array.");
                        }

                        return arr[pos];
		}

    		int search(T e) override{
			for(int i = 0; i < n; i++){
				if(e == arr[i]){
					return i;
				}
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
