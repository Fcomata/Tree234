#include "MYtree.h"
#include <iostream>
using namespace std;



tree::tree(int key){

	root = new node;
	root->key_value[0]=0;
	root->key_value[1]=key;
	root->key_value[2]=0;
	root->parent=NULL;
	root->left=NULL;
	root->midleft=NULL;
	root->midright=NULL;
	root->right=NULL;

	//node* father = root;

	cadena="";
  }

tree::~tree(){

free(root);

}



bool tree::insert(int key, node* leaf){



//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////NODOS/////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


	if(leaf->parent == NULL && leaf->left==NULL && leaf->midleft==NULL && leaf->midright==NULL && leaf->right==NULL && leaf-> key_value[1]!=0 && leaf-> key_value[2]!=0){ //root lleno y split

		
			leaf->left = new node;
			leaf->left->key_value[0]=leaf-> key_value[0];
			leaf->left->key_value[1]=0;
			leaf->left->key_value[2]=0;
			leaf->left->parent=leaf;
			leaf->left->left=NULL;
			leaf->left->midleft=NULL;
			leaf->left->midright=NULL;
			leaf->left->right=NULL;

			leaf->right = new node;
			leaf->right->key_value[0]=leaf-> key_value[2];
			leaf->right->key_value[1]=0;
			leaf->right->key_value[2]=0;
			leaf->right->parent=leaf;
			leaf->right->left=NULL;
			leaf->right->midleft=NULL;
			leaf->right->midright=NULL;
			leaf->right->right=NULL;
			
			leaf-> key_value[0]=leaf-> key_value[1];
			leaf-> key_value[1]=0; 
			leaf-> key_value[2]=0;


		}


	if(leaf==NULL){

			leaf = new node;
			leaf->key_value[0]=key;
			leaf->key_value[1]=0;
			leaf->key_value[2]=0;
			//leaf->parent=leaf->father;
			leaf->left=NULL;
			leaf->midleft=NULL;
			leaf->midright=NULL;
			leaf->right=NULL;

			cout<<"Se creo un nuevo ********NODO*****"<<endl;

			cout<<"0: "<<leaf->key_value[0]<<"    ///   1: "<<leaf->key_value[1]<<"     ///   2: "<<leaf->key_value[2]<<endl;

			if(leaf->left == NULL){ cout<<"leaf->left:NULL" <<endl;}
			if(leaf->midleft == NULL){ cout<<"leaf->midleft:NULL" <<endl;}
			if(leaf->midright == NULL){ cout<<"leaf->midright:NULL" <<endl;}
			if(leaf->right == NULL){ cout<<"leaf->right:NULL" <<endl;}
			

			return true;

		}



//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////ORDENA EL NODO////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

if(leaf-> key_value[1]==0 || leaf-> key_value[2]==0){

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//si ya hay un elemento(ordena el 2ndo)
	if(leaf-> key_value[1]== 0){

			if(key < leaf-> key_value[0]){

				leaf-> key_value[1]=leaf-> key_value[0]; //swap de posicion

				leaf-> key_value[0]=key;

				return true;


			}

			if(key > leaf-> key_value[0]){


				leaf-> key_value[1]=key;

				return true;

			}

		}//fin si ya hay un elemento(ordena el 2ndo)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//si hay 2 elementos (ordena el 3ero)
	if(leaf-> key_value[2]== 0 && leaf-> key_value[1]!= 0){


			if(leaf-> key_value[0]> key){

			leaf-> key_value[2]=leaf-> key_value[1];
			leaf-> key_value[1]=leaf-> key_value[0];
			leaf-> key_value[0]=key;

			return true;


			}

			if(leaf-> key_value[0] < key && leaf-> key_value[1] > key){


			leaf-> key_value[2]=leaf-> key_value[1];
			leaf-> key_value[1]=key;

			return true;


			}

			if(leaf-> key_value[1] < key){

			leaf-> key_value[2]=key;

			return true;

			}

		}// fin si hay 2 elementos (ordena el 3ero)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	} // if(leaf-> key_value[1]==0 || leaf-> key_value[2]==0) Ordena el nodo

//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////NODO LLENO////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


	if(leaf-> key_value[1]!=0 && leaf-> key_value[2]!=0 && leaf-> key_value[2]!=0){

		if(leaf->parent->midleft==NULL || leaf->parent->midright==NULL){

			if(leaf->parent->midleft==NULL){

				if(key < leaf->key_value[1]){

				insert(leaf->key_value[1], leaf->parent); //sube el del medio al padre

				insert(leaf->key_value[0],leaf->parent->midleft); // inserta  el valor menor en midleft del padre

				leaf->key_value[0]=leaf->key_value[2];// se acomoda el # a la posicion 0

				leaf->key_value[1]=0;leaf->key_value[2]=0; // se nullifican las demas posiciones

				insert(key, leaf->parent->left);

				}


				if(key > leaf->key_value[1]){

				insert(leaf->key_value[1], leaf->parent); //sube el del medio al padre

				insert(leaf->key_value[0],leaf->parent->midleft); // inserta  el valor menor en midleft del padre

				leaf->key_value[0]=leaf->key_value[2];// se acomoda el # a la posicion 0

				leaf->key_value[1]=0;leaf->key_value[2]=0; // se nullifican las demas posiciones

				insert(key, leaf->parent->midleft);

				}
				

			}//if(leaf->parent->midleft==NULL){


			if(leaf->parent->midright==NULL){


				if(key > leaf->key_value[1]){

				insert(leaf->key_value[1], leaf->parent); //sube el del medio al padre

				insert(leaf->key_value[0],leaf->parent->midright); // inserta  el valor menor en midleft del padre

				leaf->key_value[0]=leaf->key_value[2];// se acomoda el # a la posicion 0

				leaf->key_value[1]=0;leaf->key_value[2]=0; // se nullifican las demas posiciones

				insert(key, leaf->parent->right);

				}


				if(key < leaf->key_value[1]){

				insert(leaf->key_value[1], leaf->parent); //sube el del medio al padre

				insert(leaf->key_value[0],leaf->parent->midright); // inserta  el valor menor en midrght del padre

				leaf->key_value[0]=leaf->key_value[2];// se acomoda el # a la posicion 0

				leaf->key_value[1]=0;leaf->key_value[2]=0; // se nullifican las demas posiciones

				insert(key, leaf->parent->midright);

				}



			  }//if(leaf->parent->midright==NULL){


			}//if(leaf->parent->midleft==NULL || leaf->parent->midright==NULL){
		

	}//if(leaf-> key_value[1]!=0 && leaf-> key_value[2]!=0 && leaf-> key_value[2]!=0) NODO LLENO

}//end insert




bool tree::search(int key, node* leaf){




	if(leaf != NULL){

/**/

	cout<<"key:"<<key<<endl;

	cout<<"0:" << leaf->key_value[0]<<"  //   1:" << leaf->key_value[1]<<"   //   2:" << leaf->key_value[2]<<endl;

	if(leaf->left == NULL){ cout<<"leaf->left:NULL" <<endl;}
	if(leaf->midleft == NULL){ cout<<"leaf->midleft:NULL" <<endl;}
	if(leaf->midright == NULL){ cout<<"leaf->midright:NULL" <<endl;}
	if(leaf->right == NULL){ cout<<"leaf->right:NULL" <<endl;}


/**/

	    if(leaf->key_value[0]==key || leaf->key_value[1]==key || leaf->key_value[2]==key){return true;}
		
			//busqueda recursiva

		if(key < leaf->key_value[0])
			return search(key, leaf->left);
		if(key > leaf->key_value[0] && key < leaf->key_value[1])
			return search(key, leaf->midleft);
		if(key > leaf->key_value[1] && key < leaf->key_value[2])
			return search(key, leaf->midright);
		if(key > leaf->key_value[2])
			return search(key, leaf->right);

		
	}

	if(leaf == NULL){return false;}
}




bool tree::search(int key){

	return search(key, root);
}

node* tree::insert(int key){ 

bool cond;

cond = insert(key, root);

if (cond==true){cout<<"true->"<< to_string(key)<<endl;}
else{cout<<"false"<<endl;}

}


node* tree::devolver(){

return root;

}



//////////////////////////////////////////////////////////////////////////


////////////////////Prototipo Imprimir///////////////////////////////////

void tree::print(){

print_search(root);
cout << cadena << endl;
cadena="";

}

void tree::print_search(){print_search(root);}

void tree::print_search(node* leaf){



	if(leaf == NULL){

		fin();

	}


	if(leaf != NULL){

		print_node(leaf);
		print_search(leaf->left);
		print_node(leaf);
		print_search(leaf->midleft);
		print_node(leaf);
		print_search(leaf->midright);
		print_node(leaf);
		print_search(leaf->right);


	}

   }

void tree::print_node(node* leaf){

cadena+=to_string(leaf->key_value[0]); 
coma(); 
cadena+=to_string(leaf->key_value[1]);
coma(); 
cadena+=to_string(leaf->key_value[2]); 
flecha();


}


void tree::flecha () {

cadena+=" --> ";

}

void tree::fin () {

cadena+="; \n";

}

void tree::coma () {

cadena+=" , ";

}

string tree::to_string(int valor){

stringstream s1;
s1<<valor;
return s1.str();

}



