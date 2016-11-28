
#ifndef _RED_BLACK_H
  #define _RED_BLACK_H

#include "basics.h"
#include "linked_list.h"

#define RED true
#define BLACK false

template <class T>
class red_black {
	private:
    // Node private class
		class node{
			public:
				T _data;
				node *_left, *_right;
        bool _color;

				node(T data) : _data(data), _left(NULL), _right(NULL), _color(RED) {};
				~node(){};
		};

    //  Member data
    node *_root;
    int _num;//  Number of elements
    int (*_cmp)(T a, T b);//  Comparation function

    /* Aux functions */
    // Destroys the structure recursively
    void _destroy(node* current) {
      if(!current)
        return;
      this->_destroy(current->_left);
      this->_destroy(current->_right);
      delete(current);
    }

    // Search fot an element
    void _exist(T elem, node *curr, int &i) {
      // Check for final
  		if(!curr){
  			i=-1;
  			return;
  		}
  		// Check witch path should i choose
  		if( (i!=-1) && (_cmp(elem, curr->_data)==1)){
  			_exist(elem, curr->_right, i);
  		}
  		if((i!=-1) && (_cmp(elem, curr->_data)==-1)){
  		  _exist(elem, curr->_left, i);
  		}
  		// Check for error (not found) and for red row
  		if(i!=-1 && (!curr->_color))
  			i++;
    }

    // Rotate left
    void _rotateLeft(node* &curr) {
      node* aux=NULL;

      std::cout<<"rotate left\n";
      aux = curr;
      curr = curr->_right;
      aux->_right = curr->_left;
      curr->_left = aux;
      curr->_color = curr->_left->_color;
      curr->_left->_color = RED;
    }

    // Rotate right
    void _rotateRight(node* &curr) {
      node* aux=NULL;

      std::cout<<"rotate right\n";
      aux = curr->_left;
      aux = curr;
      curr = curr->_left;
      aux->_left = curr->_right;
      curr->_right = aux;
      curr->_color = curr->_right->_color;
      curr->_right->_color = RED;
    }

    // Color flip
    void _colorFlip(node* &curr) {
      std::cout<<"color flip\n";
      curr->_color = !curr->_color;
      curr->_left->_color = !curr->_left->_color;
      curr->_right->_color = !curr->_right->_color;
    }

    // Inserts a new elements
    void _insert(node* &curr, T elem) {

      //Check for color flip
      if(curr->_left && curr->_right && \
        curr->_left->_color && curr->_right->_color)
          _colorFlip(curr);

      // Return if match
      if(!this->_cmp(elem, curr->_data)){
        std::cout<<"Match!\n";
        return;
      }

      // Check left
      if(this->_cmp(curr->_data, elem)>0)
        if(curr->_left)
          _insert(curr->_left, elem);
        else
          curr->_left = new node(elem);

      // Check right
      if(this->_cmp(curr->_data, elem)<0)
        if(curr->_right)
          _insert(curr->_right, elem);
        else
          curr->_right = new node(elem);

      // Fix right reds
      if(curr->_right && curr->_right->_color)
        _rotateLeft(curr);

      // Fix two reds in a row
      if(curr->_left && curr->_left->_left && \
      curr->_left->_color && curr->_left->_left->_color)
        _rotateRight(curr);
    }

    // Delete an existing elements

    // Returns a linked list with the elements inorden

    // Returns a linked list with the elements preordens

  public:
    // Creates a new structure
    red_black(int(*cmp)(T a, T b)) : _root(NULL), _num(0), _cmp(cmp) {};
    ~red_black() { this->_destroy(this->_root); };

    // Destroys the structure
    void destroy(node* current){ _destroy(this->_root->_data); }
    // Returns actual root
    T getRoot(){
      if(this->_root)
        return this->_root->_data;
      else
        throw empty();
    }

    // Insert a new elements
    void insert(T elem){
      if(!this->_root){
        std::cout<<"Inserto raiz\n";
				this->_root = new node(elem);
      }
			else
				this->_insert(this->_root, elem);
    }

    // Delete an element from the structure if exist
    void deleteElem(T elem){}

    // Check if an element exist and return the cost to reach it
    int exist(T elem){
      int i=0;

      _exist(elem, this->_root, i);
      return i;
    }

    // Returns a linked list with the elements in preorden
    void preorden(linked_list<T> &dev){}

    // Returns a linked list with the elements inorden
    void inorden(linked_list<T> &dev){}
};

#endif /* _RED_BLACK_H */
