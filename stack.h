/*
	THIS FILE INCLUDES A COMPLETE FUNCTIONAL STACK SRTUCTURE
*/

#ifndef _STACKH
	#define _STACKH

	#include "basics.h"
//  Class declaration
template <class T>
class stack {
	private:
		class node{
			public:
				T __data;
				node * __next;

				node(T data, node* next){
					this->__data = data;
					this->__next = next;
				}
				~node(){};
		};


		int _num;
		node* _head;
	public:
		// Constructor
		stack(){
			this->_num = 0;
			this->_head = NULL;
		};

		// Destructor
		~stack(){
			// Pop all the elements remain
			while(this->_num > 0)
				this->pop();
		};

		// Extract the head of the stack
		T pop(){
			T aux;
			node* auxHead;

			// Check exceptios
			/*if(this->isEmpty())
				throw EPilaVacia;*/

			// Copy of the requested data
			aux = this->_head->__data;

			// Save the next element
			auxHead = this->_head->__next;
			// Delete the head
			delete(this->_head);

			// Set the new head
			this->_head = auxHead;

			// Update number of elements
			this->_num--;

			return aux;
		};

		// Insert on the head of the stack
		void push(T data){

			node* newNode = NULL;

			// Inicialize the stack
			if(this->isEmpty()){
				this->_head = new node(data, NULL);
			} else {
				newNode = new node(data, this->_head);
				this->_head = newNode;
			}

			// Update number of elements
			this->_num++;
		};

		// Returns the number of elements in the stack
		int numElem(){
			return this->_num;
		};

		// Returns if the stack is empty
		bool isEmpty(){
			return (this->_num == 0);
		};
};

#endif /* _STACKH */