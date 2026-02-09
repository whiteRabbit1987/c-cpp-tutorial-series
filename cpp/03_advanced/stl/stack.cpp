#include <iostream>

class Stack{
  private:
  int stackStore[100];
  int SP;

  public:
       Stack() { SP = 0; }
  void push(int value){
    stackStore[SP++] = value;
  }
  int pop(){
    return stackStore[--SP];
  }
};

class AddingStack : Stack {
  private:
  int sum;

  public:
      AddingStack() : Stack() { sum = 0; }
  void push(int value){
    sum += value;
    Stack::push(value);
  }
  int pop(){
    int val = Stack::pop();
    sum -= val;
    return val;
  }
  int getSum(){
    return sum;
  }
};

int main(){
  AddingStack big_stack;

  for(int i = 0; i < 100; i++)
    big_stack.push(i);
  std::cout << big_stack.getSum() << std::endl;

  for(int i = 0; i < 100; i++)
    big_stack.pop();
  std::cout << big_stack.getSum() << std::endl;

  return 0;
}