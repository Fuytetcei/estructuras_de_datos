/*
	LINKED LIST
*/

#include "basics.h"

template <class T>
class linked_list{
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

	public:

		// Constructor
		linked_list(){
			this->_num = 0;
			this->_head = NULL;
			this->_it = NULL;
		}

		// Destructor
		~linked_list(){
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
		void insert(T data){
			node* newNode = NULL;

			newNode = new node(data, this->_head);
			this->_head = newNode;
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

			// Cheack the list tail
			if((compare(data, current->__next->__data)) == 0){
				delete(current->__next);
				this->_num--;
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
};