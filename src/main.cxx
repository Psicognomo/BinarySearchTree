#include "iostream"
#include "../pkg/binarySearchTree.h"

#include "TRandom3.h"

int main() {

  TRandom3 rdm(0);

  binarySearchTree< int > prova;
  prova.setUnique( false );
  for ( long int i(0); i<5; i++ ) {
    int value = rdm.Integer(20) - 10;
    std::cout<<"Adding : "<< value<<std::endl;
    prova.add( value );
  }


  std::cout<<"### Size = "<<prova.size() << std::endl;
  prova.print();
  std::cout << " min : "<< prova.min() << std::endl;
  std::cout << " max : "<< prova.max() << std::endl;
}
