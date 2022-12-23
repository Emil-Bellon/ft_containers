#include "../stack.hpp"


#include <iostream>       // std::cout         
        // std::vector
#include <deque>          // std::deque


int main ()
{
    std::cout<<"-------------TEST CONSTRUCTOR------------"<<std::endl;
  {
  std::deque<int> mydeque (3,100);          // deque with 3 elements
  ft::vector<int> myvector (2,200);        // vector with 2 elements

  ft::stack<int> first;                    // empty stack
  ft::stack<int,std::deque<int> > second (mydeque);         // stack initialized to copy of deque

  ft::stack<int> third;  // empty stack using vector
  ft::stack<int> fourth (myvector);

  std::cout << "size of first: " << first.size() << '\n';
  std::cout << "size of second: " << second.size() << '\n';
  std::cout << "size of third: " << third.size() << '\n';
  std::cout << "size of fourth: " << fourth.size() << '\n';
  }
    std::cout<<"-------------TEST EMPTY------------"<<std::endl;
  {
  ft::stack<int> mystack;
  int sum (0);

  for (int i=1;i<=10;i++) mystack.push(i);

  while (!mystack.empty())
  {
     sum += mystack.top();
     mystack.pop();
  }

  std::cout << "total: " << sum << '\n';

  
  }
    std::cout<<"-------------TEST SIZE------------"<<std::endl;
  {
  ft::stack<int> myints;
  std::cout << "0. size: " << myints.size() << '\n';

  for (int i=0; i<5; i++) myints.push(i);
  std::cout << "1. size: " << myints.size() << '\n';

  myints.pop();
  std::cout << "2. size: " << myints.size() << '\n';


}
  std::cout<<"-------------TEST TOP------------"<<std::endl;
{
  ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

  mystack.top() -= 5;

  std::cout << "mystack.top() is now " << mystack.top() << '\n';


}
std::cout<<"-------------TEST PUSH/POP------------"<<std::endl;
{
  ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
     std::cout << ' ' << mystack.top();
     mystack.pop();
  }
  std::cout << '\n';


}
std::cout<<"-------------TEST OPERATOR BOOL------------"<<std::endl;
{
ft::vector<int> f(3,100);   // three ints with a value of 100
ft::vector<int> b (2,200);   // two ints with a value of 200
ft::stack<int> foo(f);
ft::stack<int> bar(f);
  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}
  return 0;
}