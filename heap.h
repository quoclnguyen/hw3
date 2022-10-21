#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>
#include <cmath>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> items;
  int d;
  PComparator compare;
};

/*/
template <typename T, typename PComparator=std::less<T> >
Heap<T,PComparator>::Heap(int m=2, PComparator c = PComparator())
{
  d = 2;
  compare = c;
}
/*/
template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c)
{
  d = m;
  compare = c;
} 
template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap(){}



// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // d *i +1
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is Empty!");
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return items[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Heap is Empty!");
  }

  items[0]=items[items.size()-1];
  items.pop_back();
  int treeHeight= (int)(log(items.size()+1)/log(d));
  int currentNode = 0;
  //for each level
  for (int i =1; i<=treeHeight+1; i++){
    int currentBest = currentNode;
    bool outofBounds = false;
    //for each child
    for (int j =1; j<=d; j++){
      // m *i +1 to get child
      if ((d*currentNode)+j >= (int)items.size()){
        outofBounds = true;
        break;
      }
      if (compare(items[(d*currentNode)+j],items[currentBest])){
        currentBest = (d*currentNode)+j;
      }
    }
    if (currentBest == currentNode){
        //if none of the children are better than current
        break;
    }
    T temp = items[currentBest];
    items[currentBest]=items[currentNode];
    items[currentNode]=temp;
    currentNode = currentBest; 
    if (outofBounds==true) {break;}
  } 
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  items.push_back(item);
  int currentIndex = items.size() -1;
  while(currentIndex >0){
    bool foundIndex = false;
    if(compare(items[currentIndex], items[(currentIndex-1)/d])){
      foundIndex = true;
      T temp = items[(currentIndex-1)/d];
      items[(currentIndex-1)/d] = items[currentIndex];
      items[currentIndex] = temp;
      currentIndex = (currentIndex-1)/d;
    }
    if (!foundIndex){break;}
  }
}
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const {
  return items.size();
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const {
  if(size() == 0){return true;}
  return false;
}





#endif

