#include "tree_node.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

template<typename T, typename A, typename B>

class tree{


    public:

	node<T, A, B>* root;
        tree(T value, A max, B min);
        bool search(T key);
	
	
	

    private:

	
        bool search(T key, node<T, A, B>* leaf);
	void print_search();

	
        
};
