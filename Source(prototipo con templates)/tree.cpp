#include "MYtree.h"
#include <iostream>

using namespace std;

template<typename T, typename A,typename B>

tree<T,A,B>::tree(T value, A max, B min) {

	root = new node<value,max,min>;
/*
	for (int i=0; i<= 2; i++){
	root->key_value<T>[i]=0;
	}
	root->key_value<T>[0]=key;

	for (int i=0; i<= dif; i++){
	root->key<T>[i]=NULL;
	}*/
	
  }



/*

bool tree<T,B,A>::search(T key, node* leaf){

   bool cond=false;

 if (leaf =! NULL){

    for (int =0; i<= dif+1; i++){

 	cond =	busquedaNodo (leaf);

		if (cond == true){return true;}

		else{
			return busquedaNodo (leaf->key[i]);
			}
		
	}//end for

	}//end if NULL
   }


bool tree::search(T key){


	return search(key, root);

	}

bool busquedaNodo (node<A,B>* leaf){

	

	for (int i=0; i<= dif; i++){
	
	if(key == leaf->key_value[i]){return true;}

	}

}*/

