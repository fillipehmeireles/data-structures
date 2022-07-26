#include <iostream>

typedef int queue_element_value_type;

template <class T> struct Queue {
  T value;
  Queue *link;
  
  void push(Queue *queue, T value) {
    while(queue->link != NULL)
      queue = queue->link;

    Queue<T> *new_element;
    new_element = new Queue<T>;
    new_element->value = value;
    queue->link = new_element;
  }
  
  void pop(Queue *queue){ 
      *queue = *queue->link;
  }

  void show(Queue *queue) {
    Queue<queue_element_value_type> *tmp = queue;
    while(tmp != NULL) {
      std::cout<< tmp->value << "\n";
      tmp = tmp->link;
    } 
  }

};


int main() {
  Queue<queue_element_value_type> *first_element;
  first_element = new Queue<queue_element_value_type>; 
  
  first_element->value = 0;
  first_element->link = NULL;
  
  for(int i = 1; i < 11; i++)
    first_element->push(first_element,i); // Push 10 elements
    
  first_element->show(first_element); 

  for(int i = 0; i < 5; i ++)
    first_element->pop(first_element); // Pop five elements


  first_element->show(first_element);

  return EXIT_SUCCESS;
}
