#include "tree_node.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>


class tree{


    public:

	node* root;

        tree(int);
        ~tree();
	string cadena;

	node* insert(int key);
        bool search(int key);
	void print();
	bool insert(int key, node*);
	
	


	
        


    private:

	
        bool search(int key, node *leaf);
	void print_search(node* leaf);
	node* devolver();
	void print_search();
	string to_string(int);
	void print_node(node* leaf);
	void coma();
	void flecha();
	void fin();
	
        
};
