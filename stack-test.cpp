#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
#include "stack.h"
using namespace std;
int main(){
  Stack<int> test1;
  test1.push(1);
  test1.pop();
  cout << "Size: " << test1.size() << endl;
  test1.push(2);
  test1.push(3);  
  cout << test1.top() << endl;
  test1.pop();
  cout << test1.top() << endl;
  test1.pop();
  test1.push(10);
  cout << test1.top() << endl;



  

  return 0;
}