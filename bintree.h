/*

	ÁRBOL BINARIO DE BÚSQUEDA EQUILIBRADO

*/

#ifndef _BINTREE_H
	#define _BINTREE_H

#include "basics.h"
#include "stack.h"

template <class T>
class bintree {
	private:
		class node{
			public:
				T _data;
				int _h;
				node * _left, *_right;

				node(T data) : _data(data), _left(NULL), _right(NULL){};
				~node(){};
		};

	int maximo(int a, int b) {
		if(a>b)
			return a;
		return b;
	}

	void _destroy(node* current) {
		if(!current)
			return;
		this->_destroy(current->_left);
		this->_destroy(current->_right);
		delete(current);
	};

	void _equil(node* &curr){
		node *aux, *aux1;
		int hL=0, hR=0;

		// LR
		if(curr->_left){
			if(curr->_right)
			if(curr->_left->_right && curr->_right->_right)
			if(curr->_left->_right->_left && curr->_left->_right->_right){
				if(curr->_right)
					hR = curr->_right->_h;
				if((curr->_left->_right->_left->_h == hR)||(curr->_left->_right->_right->_h == hR)) {
					std::cout<<"\n	LR detectada\n";
					// Change pointers
					aux = curr;
					aux1 = curr->_left;
					curr = aux1->_right;
					aux1->_right= curr->_left;
					aux->_left = curr->_right;
					curr->_left = aux1;
					curr->_right = aux;

					// Update _h
					if(!curr->_left->_left) hL=0;
					else hL=curr->_left->_left->_h;
					if(!curr->_left->_right) hR=0;
					else hR=curr->_left->_right->_h;
					curr->_left->_h = maximo(hL, hR) + 1;
					if(!curr->_right->_left) hL=0;
					else hL=curr->_right->_left->_h;
					if(!curr->_right->_right) hR=0;
					else hR=curr->_right->_right->_h;
					curr->_right->_h = maximo(hL, hR) + 1;
					hR=curr->_right->_h;
					hL=curr->_left->_h;
					curr->_h = maximo(hL, hR) + 1;
					return;
				}
			}
		// LL
			if(curr->_right)
				hR = curr->_right->_h;
			else
				hR = 0;
			hL = curr->_left->_h;
			if(hL-hR>1){
				std::cout<<"\n	LL detectada\n";
				// Change pointers
					aux = curr;
					aux1 = curr->_left->_right;
					curr = curr->_left;
					curr->_right = aux;
					curr->_right->_left = aux1;
				// Update _h
					if(!curr->_right->_right)
						hL=0;
					else
						hL = curr->_right->_right->_h;
					if(!curr->_right->_left)
						hR=0;
					else
						hR = curr->_right->_left->_h;
					curr->_right->_h = maximo(hL, hR)+1;
					if(!curr->_right)
						hL=0;
					else
						hL = curr->_right->_h;
					if(!curr->_left)
						hR=0;
					else
						hR = curr->_left->_h;
					curr->_h = maximo(hR, hL)+1;
					return;
			}
		}
		// RL
		if(curr->_right){
		if(curr->_left)
		if(curr->_right->_left && curr->_left->_left)
			if(curr->_right->_left->_right && curr->_right->_left->_left){
				if(curr->_left)
					hL = curr->_left->_h;
				if((curr->_right->_left->_right->_h == hL)||(curr->_right->_left->_left->_h == hL)) {
					std::cout<<"\n	RL detectada\n";
					// Change pointers
					aux = curr;
					aux1 = curr->_right;
					curr = aux1->_left;
					aux1->_left = curr->_right;
					aux->_right = curr->_left;
					curr->_right = aux1;
					curr->_left = aux;
					// Update _h
					if(!curr->_left->_left) hL=0;
					else hL=curr->_left->_left->_h;
					if(!curr->_left->_right) hR=0;
					else hR=curr->_left->_right->_h;
					curr->_left->_h = maximo(hL, hR) + 1;
					if(!curr->_right->_left) hL=0;
					else hL=curr->_right->_left->_h;
					if(!curr->_right->_right) hR=0;
					else hR=curr->_right->_right->_h;
					curr->_right->_h = maximo(hL, hR) + 1;
					hR=curr->_right->_h;
					hL=curr->_left->_h;
					curr->_h = maximo(hL, hR) + 1;
					return;
				}
			}
			// RR
			if(!curr->_left)
			  hL = 0;
			else
				hL = curr->_left->_h;
			hR = curr->_right->_h;
			if(hR-hL>1){
				std::cout<<"\n   RR detectada\n";
				// Change pointers
					aux = curr;
					aux1 = curr->_right->_left;
					curr = curr->_right;
					curr->_left = aux;
					curr->_left->_right = aux1;
				// Update _h
					if(!curr->_left->_left)
						hL=0;
					else
						hL = curr->_left->_left->_h;
					if(!curr->_left->_right)
						hR=0;
					else
						hR = curr->_left->_right->_h;
					curr->_left->_h = maximo(hL, hR)+1;
					if(!curr->_left)
						hL=0;
					else
						hL = curr->_left->_h;
					if(!curr->_right)
						hR=0;
					else
						hR = curr->_right->_h;
					curr->_h = maximo(hR, hL)+1;
					return;
			}
		}
	}

	void _insert(T elem, node* &curr) {
		int hL, hR;

		// Check the left child
		if(this->_cmp(curr->_data, elem) > 0) {
			if(!curr->_left){
				curr->_left = new node(elem);
				this->_num++;
				curr->_left->_h=1;
				if(!curr->_right)
					curr->_h = 2;
				else
					curr->_h = maximo(curr->_left->_h, curr->_right->_h)+1;
			}else {
				_insert(elem, curr->_left);
				if(!curr->_right)
					hR = 0;
				else
					hR = curr->_right->_h;
				curr->_h = maximo(curr->_left->_h, hR)+1;
			}
		}// Check the right child
		else if(this->_cmp(curr->_data, elem) < 0){
			if(!curr->_right){
				curr->_right = new node(elem);
				this->_num++;
			  curr->_right->_h = 1;
				if(!curr->_left)
					curr->_h = 2;
				else
					curr->_h = maximo(curr->_left->_h, curr->_right->_h)+1;
			}else
				_insert(elem, curr->_right);
				if(!curr->_left)
					hL = 0;
				else
					hL = curr->_left->_h;
				curr->_h = maximo(hL, curr->_right->_h)+1;
		}

		// Check for equil
		this->_equil(curr);
	};

	// Exchanges the value of an element and the min of a tree
	void _deleteMin(node* &f, node* &curr, node* &arb){
		int hL, hR;
		// check if i found the min
		if(!curr->_left){
			std::cout<<curr->_data<<"\n";
			arb->_data = curr->_data;
			std::cout<<arb->_data<<"\n";
			// check for right child
			if(curr->_right){
				f->_right = curr->_right;
				hL = f->_right->_h;
			} else {
				f->_right = NULL;
				hL=0;
			}
			if(!f->_left)hR=0;
			else hR = f->_left->_h;
			f->_h = maximo(hL, hR) + 1;

			delete(curr);

			// equil
			this->_equil(f);
			return;
		}
		// continuing searching
		_deleteMin(curr, curr->_left, arb);
	}

	void _deleteMax(node* &f, node* &curr, node* &arb){
		int hL, hR;
		// check if i found the min
		std::cout<<arb->_data<<"\n";
		if(!curr->_left){
			arb->_data = curr->_data;
			// check for right child
			if(curr->_left){
				f->_left = curr->_left;
				hL = f->_left->_h;
			} else {
				f->_left = NULL;
				hL=0;
			}
			if(!f->_right)hR=0;
			else hR = f->_right->_h;
			f->_h = maximo(hL, hR) + 1;

			delete(curr);
			curr = NULL;

			// equil
			this->_equil(f);
			return;
		}
		// continuing searching
		_deleteMax(curr, curr->_right, arb);
	}

	// finds the element to delete
	void _delete(T elem, node* &curr, node* &f, bool child) {
		node *aux=NULL, *aux1=NULL;
		// check for final
		if(!_cmp(curr->_data, elem)){

			// check for leaf -------------
			if((!curr->_right) && \
				(!curr->_left)){
				if(f){// check for root
					if(child)// check what child is curr
						f->_left = NULL;
					else
						f->_right = NULL;
				}
				delete(curr);
			}
			else if(!curr->_right){// check for left child
				_deleteMax(curr, curr->_right, curr);
			}
			else{// exchange with min of right child
				_deleteMin(curr, curr->_right, curr);
			}

			std::cout<<"Elemento eliminado\n";
			return;
		}

		// check for childs
		if(_cmp(curr->_data, elem)>0)
			_delete(elem, curr->_left, curr, true);
		if(_cmp(curr->_data, elem)<0)
			_delete(elem, curr->_right, curr, false);

		// equil
		this->_equil(curr);
	};

	void _exist(node *curr, T elem, int &i) {
		// Check for final
		if(!curr){
			i=-1;
			return;
		}
		// Check witch path should i choose
		if( (i!=-1) && (_cmp(elem, curr->_data)==1)){
			_exist(curr->_right, elem, i);
		}
		if((i!=-1) && (_cmp(elem, curr->_data)==-1)){
		  _exist(curr->_left, elem, i);
		}
		// Check for error (not found)
		if(i!=-1)
			i++;
	}

	// Fills the stack with the elements inorden
	void _inorden(stack<T> &s, node *curr) {
		if(!curr)
			return;
		// Push left child
		_inorden(s, curr->_left);
		// Push current
		s.push(curr->_data);
		// Push right child
		_inorden(s, curr->_right);
	};

	// Fills the stack with the elements preorden
	void _preorden(stack<T> &s, node *curr) {
		if(!curr)
			return;
		// Push right child
		_preorden(s, curr->_right);
		// Push current
		s.push(curr->_data);
		// Push left child
		_preorden(s, curr->_left);
	};

	// Member data
	node *_root;
	int _num;
	int (*_cmp)(T a, T b);

	public:
		bintree(int(*cmp)(T a, T b)) : _root(NULL), _num(0), _cmp(cmp) {};
		~bintree() { this->_destroy(this->_root); };

		void insert (T elem) {
			if(!this->_root)
				this->_root = new node(elem);
			else
				this->_insert(elem, this->_root);
		};

		void deleteElem (T elem) { node* f=NULL; this->_delete(elem, this->_root, f, true); };

		/* Check if an element is in the structure:
				- -1 in negative case
				- A positive number with the cost in affirmative case
		*/
		int exist(T elem) {
			int i=0;

			_exist(this->_root, elem, i);

			return i;
		};

		const T getRoot(){
			if(this->_root)
				return (const T)this->_root->_data;
			else
				throw empty();
		}


		void preorden(stack<T> &dev) {
			_inorden(dev, this->_root);
		};

		void inorden(stack<T> &dev) {
			_preorden(dev, this->_root);
		};
};

#endif /* _BINTREE_H */
