/*

	ÁRBOL BINARIO DE BÚSQUEDA

*/

#include "basics.h"
#include "stack.h"

template <class T>
class bintree {
	private:
		class node{
			public:
				T _data;
				node * _left, *_right;

				node(T data, node *right, node *left) : _data(data), _left(left), _right(right){};
				~node(){};
		};

	void _destroy(node* current) {
		if(!current)
			return;
		this->_destroy(current->_left);
		this->_destroy(current->_right);
		delete(current);
	};

	void _insert(T elem, node *curr) {
		// Check the left child
		if(this->_cmp(curr->_data, elem) > 0) {
			if(!curr->_left)
				curr->_left = new node(elem, NULL, NULL);
			else {
				_insert(elem, curr->_left);
			}
		}// Check the right child
		else if(this->_cmp(curr->_data, elem) < 0){
			if(!curr->_right)
				curr->_right = new node(elem, NULL, NULL);
			else
				_insert(elem, curr->_right);
		}
	};

	// Fills the stack with the elements preorden
	void _remove(T elem, node* curr) {};

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

	// Fills the stack with the elements inorden
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
	int _num, _h;
	int (*_cmp)(T a, T b);

	public:
		bintree(int(*cmp)(T a, T b)) : _root(NULL), _num(0), _h(0), _cmp(cmp) {};
		~bintree() { this->_destroy(this->_root); };

		void insert (T elem) {
			if(!this->_root)
				this->_root = new node(elem, NULL, NULL);
			else
				this->_insert(elem, this->_root); };

		void remove (T elem) { this->_remove(elem, this->_root); };

		/* Se hacen los reocrrido opuestos ya que al
		   llenar la pila salen al revés */
		void preorden(stack<T> &dev) {
			_inorden(dev, this->_root);
		};

		void inorden(stack<T> &dev) {
			_preorden(dev, this->_root);
		};
};





