
#ifndef _RED_BLACK_H
  #define _RED_BLACK_H

#include "basics.h"
#include "stack.h"

template <class T>
class red_black {
	private:
    // Node private class
		class node{
			public:
				T _data;
				node *_left, *_right;
        bool _color;

				node(T data, node* left, node* right, bool color) : _data(data), _left(left), _right(right), _color(color){};
				~node(){};
		};

    // Constants
    bool RED = true;
    bool BLACK = false;

    //  Member data
    node *_root;
    int _num;//  Number of elements
    int (*_cmp)(T a, T b);//  Comparation function

    /* Aux functions */
    void _destroy(node* current){
      if(!current)
        return;
      this->_destroy(current->_left);
      this->_destroy(current->_right);
      delete(current);
    }
  public:
    // Creates a new structure
    red_black((int(*cmp)(T a, T b)) : _root(NULL), _num(0), _cmp(cmp) {};
    ~red_black() { this->_destroy(this->_root); };

    // Destroys the structure
    void destroy(node* current){ _destroy(this->_root); }
    // Returns actual root
    T getRoot(){ return this->_root; }

    // Insert a new elements
    void insert(T elem){}

    // Delete an element from the structure if exist
    void deleteElem(T elem){}

    // Check if an element exist and return the cost to reach it
    int exist(T elem){ _exist(elem, this->_root);}

    // Returns a linked list with the elements in preorden
    void preorden(linked_list<T> &dev){}

    // Returns a linked list with the elements inorden
    void inorden(linked_list<T> &dev){}
};

#endif /* _RED_BLACK_H */
