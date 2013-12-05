#include "MYtree.h"
#include <iostream>
using namespace std;

node* temp;

tree::tree(int key){

	root = new node;
	root->key_value[0]=key;
	root->key_value[1]=0;
	root->key_value[2]=0;
	root->parent=NULL;
	root->left=NULL;
	root->midleft=NULL;
	root->midright=NULL;
	root->right=NULL;
	temp = root;
	cadena="";

	cout<<"\n--------------------------------------------"<<endl;
	cout<<"Inicializando el Nodo Root del Arbol 2-3-4"<<endl;
	cout<<"--------------------------------------------\n"<<endl;


	cout<<"nodo root: "<<root-> key_value[0]<<"///"<<root-> key_value[1]<<"///"<<root-> key_value[2]<<endl;

	
  }

tree::~tree(){

free(root);

}



bool tree::insert(int key, node* leaf){



//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////NODOS/////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


if( (leaf->left==NULL) && (leaf->right==NULL) && (leaf-> key_value[0]!=0) && (leaf-> key_value[1]!=0) && (leaf-> key_value[2]!=0)){ 
		//root lleno y split

		
			leaf->left = new node;
			leaf->left->key_value[0]=leaf-> key_value[0];
			leaf->left->key_value[1]=0;
			leaf->left->key_value[2]=0;
			leaf->left->parent=temp;
			leaf->left->left=NULL;
			leaf->left->midleft=NULL;
			leaf->left->midright=NULL;
			leaf->left->right=NULL;

			leaf->right = new node;
			leaf->right->key_value[0]=leaf-> key_value[2];
			leaf->right->key_value[1]=0;
			leaf->right->key_value[2]=0;
			leaf->right->parent=temp;
			leaf->right->left=NULL;
			leaf->right->midleft=NULL;
			leaf->right->midright=NULL;
			leaf->right->right=NULL;
			
			leaf-> key_value[0]=leaf-> key_value[1];
			leaf-> key_value[1]=0; 
			leaf-> key_value[2]=0;

			cout<<"Separacion ROOT: "<<leaf-> key_value[0]<<"///"<<leaf-> key_value[1]<<"///"<<leaf-> key_value[2]<<endl;


		}


	if(leaf==NULL){

			leaf = new node;
			leaf->key_value[0]=key;
			leaf->key_value[1]=0;
			leaf->key_value[2]=0;
			leaf->parent=temp;
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

if((leaf-> key_value[1] == 0) || (leaf-> key_value[2] == 0) && (leaf->left == NULL) && (leaf->right == NULL) ){

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//si ya hay un elemento(ordena el 2ndo)

	if(leaf-> key_value[1] == 0  && (leaf->left == NULL) && (leaf->right == NULL)){

			if(key < leaf-> key_value[0]){

				leaf-> key_value[1]=leaf-> key_value[0]; //swap de posicion

				leaf-> key_value[0]=key;

				cout<<"1 elemnto y key menor: "<<leaf-> key_value[0]<<"///"<<leaf-> key_value[1]<<"///"<<leaf-> key_value[2]<<endl;

				return true;
			


			}

			if(key > leaf-> key_value[0]  && (leaf->left == NULL) && (leaf->right == NULL)){


				leaf-> key_value[1]=key;

				cout<<"1 elemnto y key mayor: "<<leaf-> key_value[0]<<"///"<<leaf-> key_value[1]<<"///"<<leaf-> key_value[2]<<endl;

				return true;

				

			}

		}//fin si ya hay un elemento(ordena el 2ndo)



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if((leaf-> key_value[1] == 0) || (leaf-> key_value[2] == 0) && ((leaf->left != NULL) || (leaf->right != NULL)) ){


			if(key < leaf-> key_value[0]){

	
			insert(key, leaf->left);

	
			}

			if(key > leaf-> key_value[0]){

	
			insert(key, leaf->right);

	
			}

		}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//si hay 2 elementos (ordena el 3ero) 
	if( (leaf-> key_value[2]== 0) && (leaf-> key_value[1]!= 0) && (leaf-> key_value[0]!= 0) ){


			if(leaf-> key_value[0]> key){

			leaf-> key_value[2]=leaf-> key_value[1];
			leaf-> key_value[1]=leaf-> key_value[0];
			leaf-> key_value[0]=key;

			cout<<"2 elementos y key menor: "<<leaf-> key_value[0]<<"///"<<leaf-> key_value[1]<<"///"<<leaf-> key_value[2]<<endl;

			return true;


			}

			if( (leaf-> key_value[0] < key) && (leaf-> key_value[1] > key) ){


			leaf-> key_value[2]=leaf-> key_value[1];
			leaf-> key_value[1]=key;

			cout<<"2 elementos y key <1>: "<<leaf-> key_value[0]<<"///"<<leaf-> key_value[1]<<"///"<<leaf-> key_value[2]<<endl;

			return true;


			}

			if(leaf-> key_value[1] < key){

			leaf-> key_value[2]=key;
		
			cout<<"2 elementos y key mayor: "<<leaf-> key_value[0]<<"///"<<leaf-> key_value[1]<<"///"<<leaf-> key_value[2]<<endl;

			return true;

			}

		}// fin si hay 2 elementos (ordena el 3ero)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	} // if(leaf-> key_value[1]==0 || leaf-> key_value[2]==0) Ordena el nodo

//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////NODO LLENO////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


	if( (leaf-> key_value[1]!=0) && (leaf-> key_value[2]!=0) && (leaf-> key_value[2]!=0) ){

		if(leaf->parent->midleft==NULL || leaf->parent->midright==NULL){

			if(leaf->parent->midleft==NULL){

				if(key < leaf->key_value[1]){

				insert(leaf->key_value[1], leaf->parent); //sube el del medio al padre

				insert(leaf->key_value[0],leaf->parent->midleft); // inserta  el valor menor en midleft del padre

				leaf->key_value[0]=leaf->key_value[2];// se acomoda el # a la posicion 0

				leaf->key_value[1]=0;leaf->key_value[2]=0; // se nullifican las demas posiciones

				insert(key, leaf->parent->left);

				cout<<"Separacion de nodo"<<endl;

				}


				if(key > leaf->key_value[1]){

				insert(leaf->key_value[1], leaf->parent); //sube el del medio al padre

				insert(leaf->key_value[0],leaf->parent->midleft); // inserta  el valor menor en midleft del padre

				leaf->key_value[0]=leaf->key_value[2];// se acomoda el # a la posicion 0

				leaf->key_value[1]=0;leaf->key_value[2]=0; // se nullifican las demas posiciones

				insert(key, leaf->parent->midleft);

				cout<<"Separacion de nodo"<<endl;

				}
				

			}//if(leaf->parent->midleft==NULL){


			if(leaf->parent->midright==NULL){


				if(key > leaf->key_value[1]){

				insert(leaf->key_value[1], leaf->parent); //sube el del medio al padre

				insert(leaf->key_value[0],leaf->parent->midright); // inserta  el valor menor en midleft del padre

				leaf->key_value[0]=leaf->key_value[2];// se acomoda el # a la posicion 0

				leaf->key_value[1]=0;leaf->key_value[2]=0; // se nullifican las demas posiciones

				insert(key, leaf->parent->right);

				cout<<"Separacion de nodo"<<endl;

				}


				if(key < leaf->key_value[1]){

				insert(leaf->key_value[1], leaf->parent); //sube el del medio al padre

				insert(leaf->key_value[0],leaf->parent->midright); // inserta  el valor menor en midrght del padre

				leaf->key_value[0]=leaf->key_value[2];// se acomoda el # a la posicion 0

				leaf->key_value[1]=0;leaf->key_value[2]=0; // se nullifican las demas posiciones

				insert(key, leaf->parent->midright);

				cout<<"Separacion de nodo"<<endl;

				}



			  }//if(leaf->parent->midright==NULL){


			}//if(leaf->parent->midleft==NULL || leaf->parent->midright==NULL){
		

	}//if(leaf-> key_value[1]!=0 && leaf-> key_value[2]!=0 && leaf-> key_value[2]!=0) NODO LLENO

}//end insert




bool tree::search(int key, node* leaf){




	if(leaf != NULL){

/*

	cout<<"key:"<<key<<endl;

	cout<<"0:" << leaf->key_value[0]<<"  //   1:" << leaf->key_value[1]<<"   //   2:" << leaf->key_value[2]<<endl;

	if(leaf->left == NULL){ cout<<"leaf->left:NULL" <<endl;}
	if(leaf->midleft == NULL){ cout<<"leaf->midleft:NULL" <<endl;}
	if(leaf->midright == NULL){ cout<<"leaf->midright:NULL" <<endl;}
	if(leaf->right == NULL){ cout<<"leaf->right:NULL" <<endl;}


/**/

	    if( (leaf->key_value[0]==key) || (leaf->key_value[1]==key) || (leaf->key_value[2]==key) ){return true;}
		
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


insert(key, root);

}


node* tree::devolver(){

return root;

}



//////////////////////////////////////////////////////////////////////////


////////////////////Prototipo Imprimir///////////////////////////////////

void tree::print(){
cout<<"\n--------------------------------------------"<<endl;
cout<<"Visualizacion Prototipo Usando Lenguaje DOT"<<endl;
cout<<"--------------------------------------------\n"<<endl;
print_search(root);
cout << cadena << endl;
cadena="";

}

void tree::print_search(){print_search(root);}

void tree::print_search(node* leaf){

int cont=0;



	if(leaf != NULL){


		print_node(leaf);
		
		
		if(leaf->left != NULL){print_search(leaf->left);flecha2();}
		
		
		if(leaf->midleft != NULL){print_search(leaf->midleft);}
		

		if(leaf->midright != NULL){print_search(leaf->midright);}
		

		if(leaf->right != NULL){print_search(leaf->right);}
		cadena+="\n";

		


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

cadena+="-->";

}

void tree::flecha2 () {

cadena+="\\---->";

}

void tree::fin () {

cadena+=";";

}

void tree::coma () {

cadena+=",";

}

string tree::to_string(int valor){

stringstream s1;
s1<<valor;
return s1.str();

}



