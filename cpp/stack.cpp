#include <iostream>

typedef int stack_element_value_type;

template <class T> struct Stack {
  T value;
  Stack *link;
  
  Stack<T> *push(Stack *stack, T value) {
    while(stack->link != NULL)
      stack = stack->link;

    Stack<T> *new_element;
    new_element = new Stack<T>;
    new_element->value = value;
    stack->link = new_element;

    return new_element;
  }
  
  void pop(Stack *stack){
    Stack<T> *tmp = new Stack<T>;
    
    do {
      tmp = stack->link;
      if(tmp->link == NULL)
        stack->link = NULL;
      else
        stack = stack->link;
    }while(tmp->link != NULL);
  }

  void show(Stack *stack) {
    Stack<stack_element_value_type> *tmp = stack;
    while(tmp != NULL) {
      std::cout<< tmp->value << "\n";
      tmp = tmp->link;
    } 
  }

};


int main() {
  Stack<stack_element_value_type> *first_element;
  first_element = new Stack<stack_element_value_type>; 
  
  first_element->value = 0;
  first_element->link = NULL;
  
  for(int i = 1; i < 11; i++)
    first_element->push(first_element,i); 
    
  first_element->show(first_element);
  
  first_element->pop(first_element);

  first_element->show(first_element);

  return EXIT_SUCCESS;
}
