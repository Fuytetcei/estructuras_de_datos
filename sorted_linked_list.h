/*
	SORTED LINKED LIST
*/

#include "basics.h"

template <class T>
class sorted_linked_list{
	private:
		class node{
			public:
				T __data;
				node *__next;

				node(T data, node *next) : __data(data), __next(next){};
				~node(){};
		};

	node *_head, *_it;
	int _num;
	T _max;

	public:

		// Constructor
		sorted_linked_list() : _num(0), _head(NULL), _it(NULL){};

		// Destructor
		~sorted_linked_list(){
			node* aux;

			// Deleting all the elements remain
			while(this->_num > 0){
				aux = this->_head->__next;
				delete(this->_head);
				this->_head = aux;
				this->_num--;
			}
		}

		// Insert
		void insert(T data, int(*compare)(T, T)){
			node* newNode = NULL;

			//Check if first element
			if(this->_head == NULL){
				this->_head = new node(data, NULL);
				this->_num++;
				return;
			}
			// Init iterator
			this->_it = this->_head;

			// Searching position
			while((this->_it->__next != NULL) && (compare(data, this->_it->__next->__data) == 1))
				this->_it = this->_it->__next;

			// Check case
			if(this->_it->__next != NULL){
				newNode = new node(data, this->_it->__next);
				this->_max = newNode->__data;
			}
			else
				newNode = new node(data, NULL);
			this->_it->__next = newNode;

			// Init iterator again
			this->_it = this->_head;
			this->_num++;
		};

		// Remove all occurrences of T data
		void remove(T data, int(*compare)(T, T)){

			node *aux, *current;

			// Check the head element
			while((compare(data, this->_head->__data)) == 0){
				aux = this->_head->__next;
				delete(this->_head);
				this->_head = aux;
				this->_num--;
			}

			current = this->_head;
			// Check the other elements
			while(current->__next->__next != NULL){
				// Delete the next element
				if((compare(data, current->__next->__data)) == 0){
					aux = current->__next->__next;
					delete(current->__next);
					current->__next = aux;
					this->_num--;
				}
				else // Increment the list pointer position
					current = current->__next;
			}

			// Init iterator again
			this->_it = this->_head;
		}
		// Query
		bool query(T data, int(*compare)(T, T)){
			node *current;
			bool res = false;

			current = this->_head;
			while((current != NULL) && !res){
				res = (compare(data, current->__data) == 0);
				current = current->__next;
			}

			return res;
		}

		// Get all elements through an iterator
		void initIterator(){
			this->_it = this->_head;
		}

		T getElem(){
			T data = this->_it->__data;

			if(this->_it->__next != NULL)
				this->_it = this->_it->__next;
			else
				this->_it = this->_head;
			return data;
		}

		// Aux functions
		bool isEmpty(){
			return (this->_num == 0);
		}

		int numElem(){
			return this->_num;
		}

		T max(){
			return this->_max;
		}

		T min(){
			return this->_head->__data;
		}
};