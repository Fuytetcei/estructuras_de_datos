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

#endif /* _MYEXCEPTIONH */