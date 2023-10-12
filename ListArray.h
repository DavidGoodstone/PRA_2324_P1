#include <ostream>
#include "List.h"

template <typename T>

class ListArray : public List<T>{
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE;//ListArray();
		void resize(int new_size);
		
	public:
		ListArray();
		~ListArray();
		T operator[](int pos);
		// Declaración de la función amiga
    		template <typename U>
    		friend std::ostream& operator<<(std::ostream &out, const ListArray<U> &list);

};
