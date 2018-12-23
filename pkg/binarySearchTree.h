
#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>


template < class T >
class node {
 public:
  node(T);
  ~node();

  void setFatherNode(node*);
  void setRightChildNode(node*);
  void setLeftChildNode(node*);

  inline T value() const;
  inline node*& father();
  inline node*& rightChild();
  inline node*& leftChild();

  void print() const;

 private:
  node();

 private:
  T m_value;
  node *m_father;
  node *m_leftChild;
  node *m_rightChild;
};

template < class T >
void node< T >::print() const { std::cout<<m_value<<" "; }

template < class T >
node< T >::node() 
: m_value( 0 ),
  m_father( nullptr ),
  m_leftChild( nullptr ),
  m_rightChild( nullptr ) {}

template < class T >
node< T >::node( T value ) 
: m_value( value ),
  m_father( nullptr ),
  m_leftChild( nullptr ),
  m_rightChild( nullptr ) {}

template < class T >
node< T >::~node() {
  if ( m_leftChild != nullptr ) 
    delete m_leftChild;
  if ( m_rightChild != nullptr ) 
    delete m_rightChild;
}

template < class T >
void node< T >::setFatherNode( node *father ) { 
  if ( m_father != nullptr ) return;
  if ( father == nullptr ) return;
  m_father = father; 
}

template < class T >
void node< T >::setRightChildNode( node *child ) {
  if ( m_rightChild != nullptr ) return;
  if ( child == nullptr ) return;
  m_rightChild = child;
}

template < class T >
void node< T >::setLeftChildNode( node *child ) {
  if ( m_leftChild != nullptr ) return;
  if ( child == nullptr ) return;
  m_leftChild = child;
}

template < class T >
T node< T >::value() const { return m_value; }

template < class T >
node< T >*& node< T >::father() { return m_father; }

template < class T >
node< T >*& node< T >::rightChild() { return m_rightChild; }

template < class T >
node< T >*& node< T >::leftChild() { return m_leftChild; }

/* ==================================================== */

template < class T >
class binarySearchTree {
 public:
  binarySearchTree();
  ~binarySearchTree();

  void setUnique(bool unique = true);
  const unsigned int size() const;

  void add(T);
  void print();

  const T min();
  const T max();

 private:
  bool add(node< T >*&,T);
  void print(node< T >*&);

  const T min(node< T >&);
  const T max(node< T >&);

 private:
  node< T > *m_node;

 private:
  bool m_unique;
  unsigned int m_size;

  /* ==================================================== */
 private:

};

template < class T >
binarySearchTree< T >::binarySearchTree() 
: m_unique( true ),
  m_size( 0 ),
  m_node( nullptr ) {};

template < class T >
binarySearchTree< T >::~binarySearchTree() { if ( m_node != nullptr ) delete m_node; };

template < class T >
void binarySearchTree< T >::setUnique( bool unique ) { m_unique = unique; }

template < class T >
const unsigned int binarySearchTree< T >::size() const { return m_size; }

template < class T >
void binarySearchTree< T >::add( T value ) {
  if ( this->add( m_node,value ) == true )
    m_size++;
}

template < class T >
bool binarySearchTree< T >::add( node< T > *&thisNode,T value ) {
  if ( thisNode == nullptr ) {
    thisNode = new node< T >( value );
    return true;
  }

  if ( value < thisNode->value() ) 
    return this->add( thisNode->leftChild(),value );
  if ( value > thisNode->value() ) 
    return this->add( thisNode->rightChild(),value );
  if ( m_unique == true )
    return false;
  return this->add( thisNode->leftChild(),value );
}

template < class T >
void binarySearchTree< T >::print() {
  if ( m_node == nullptr )
    std::cout<<"No Elements in the tree";
  else 
    this->print( m_node );
  std::cout<<std::endl;
}

template < class T >
void binarySearchTree< T >::print( node< T > *&thisNode ) {
  if ( thisNode == nullptr ) return;
  this->print( thisNode->leftChild() );
  thisNode->print();
  this->print( thisNode->rightChild() );
}

template < class T >
const T binarySearchTree< T >::min() { return min( *m_node ); }

template < class T >
const T binarySearchTree< T >::max() { return max( *m_node ); }

template < class T >
const T binarySearchTree< T >::min( node< T > &thisNode ) {
  if ( thisNode.leftChild() == nullptr ) return thisNode.value();
  return min( *thisNode.leftChild() );
}

template < class T >
const T binarySearchTree< T >::max( node< T > &thisNode ) {
  if ( thisNode.rightChild() == nullptr ) return thisNode.value();
  return max( *thisNode.rightChild() );
}

/* ==================================================== */

#endif

