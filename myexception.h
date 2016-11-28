/*
	TRATAMIENTO DE EXCEPCIONES
*/


#ifndef _MYEXCEPTIONH
	#define _MYEXCEPTIONH

#include <exception>

//using namespace std;

class empty_stack : public std::exception {
	public:
		const char* what() const throw() {
	        return "Error: Pila vacía.\n";
	    };
};

class empty : public std::exception {
	public:
		const char* what() const throw() {
			return "Error: estructura vacía";
		}
};

#endif /* _MYEXCEPTIONH */
