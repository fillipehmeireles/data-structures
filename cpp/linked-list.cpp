#include <iostream>

template <class T> struct Node {
  T value;
  Node *link;
  
 Node<T> *insert_front(Node *node, T value) {
    Node<T> *new_front_node;
    new_front_node = new Node<T>;

    new_front_node->value = value;
    new_front_node->link = node;
    return new_front_node;
 }

 Node<T> *insert_back(Node *node, T value) {
    while(node->link != NULL) {
        node = node->link;
    }

    Node<T> *new_back_node;
    new_back_node = new Node<T>;
    new_back_node->value = value;
    node->link = new_back_node;

    return new_back_node;
 }
};


int main() {
  typedef int node_value_type;
  Node<node_value_type> *genesis;
  genesis = new Node<node_value_type>; 
  
  genesis->value = 0;
  genesis->link = NULL;
  
  Node<node_value_type> *new_back_node = genesis->insert_back(genesis,1);
  
  Node<node_value_type> *new_front_node = genesis->insert_front(genesis,-1);
  Node<node_value_type> *tmp = new_front_node;
  
  do {
    std::cout << tmp ->value << "\t";
    tmp = tmp ->link;
  }while(tmp != NULL);

  return EXIT_SUCCESS;
}
