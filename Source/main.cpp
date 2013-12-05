#include "MYtree.h"

int main (){
bool cond;
tree* Mytree = new tree(5);


Mytree->insert(2);
Mytree->insert(3);
Mytree->insert(6);
Mytree->insert(8);
Mytree->insert(1);
Mytree->insert(4);
Mytree->insert(10);
Mytree->insert(15);
Mytree->insert(7);
/**/
Mytree->insert(50);
Mytree->insert(35);
Mytree->insert(9);
Mytree->insert(27);
Mytree->insert(42);
Mytree->insert(37);
Mytree->insert(49);
Mytree->insert(12);
/**/
Mytree->print();

cout<<"\n--------------------------------------------"<<endl;
cout<<"Inicializando Busqueda de Elementos Desde Root"<<endl;
cout<<"--------------------------------------------\n"<<endl;

for(int i =1; i<51; i++){

cond = Mytree->search(i);

cout<<i<<": ";

if (cond==true){cout<<"true"<<endl;}
else{cout<<"false"<<endl;}

}


}
