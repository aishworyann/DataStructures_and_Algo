#include <bits/stdc++.h>
using namespace std;

struct Queue{
stack <int> s1,s2;      // will use two stack , time comp- O(n)

void enqueue(int x){

  //will transfer the elements of stact s1 to stack to insert element at last as happens in queue
  while(!s1.empty()){
    s2.push(s1.top());
    s1.pop();
  }

  //push the element at last of the stack
  s1.push(x);

  //push back all element back to stack s1
  while(!s2.empty()){
    s1.push(s2.top());
    s2.pop();
  }
 }


int deQueue(){
  
  if(s1.empty())
    cout<<"Queue is empty"<<endl;
  
  int x=s1.top();
  s1.pop();  //  here  top == front , so pop element of the top 
  return x;
}

};
int main() {
  Queue q;
  q.enqueue(1);  //front 
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);  //rear

  cout<<q.deQueue()<<endl;   //front pop
  cout<<q.deQueue()<<endl;
  
  
  

}