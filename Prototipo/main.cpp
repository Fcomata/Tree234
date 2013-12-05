#include "MYtree.h"

int main (){
bool cond;
tree* Mytree = new tree(5);


node* a = Mytree->insert(2);
Mytree->insert(3, a);
Mytree->insert(6, a);
Mytree->insert(8, a);
Mytree->insert(7, a);
Mytree->insert(10, a);
Mytree->insert(1, a);
/*
for(int i =1; i<11; i++){

cond = Mytree->search(i);

cout<<i<<": ";

if (cond==true){cout<<"true"<<endl;}
else{cout<<"false"<<endl;}

}


Mytree->print();

*/
}
