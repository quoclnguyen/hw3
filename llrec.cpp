#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
  if (head ==NULL){
    smaller = NULL;
    larger = NULL;
    return;
  }

  else{
    smaller=NULL;
    larger =NULL;
    pivotHelper(head, smaller, larger, pivot);
  }
  head = NULL;
}

void pivotHelper(Node *&head, Node *&smaller, Node *&larger, int pivot){
  //we'll pass in a "fresh" index each time
  if (head == NULL){
    if (larger ==NULL){
      smaller =NULL;
    }
    else if (smaller == NULL){
      larger = NULL;
    }
    return;
  }
  if ((head->val)<= pivot){
    smaller = head;
    smaller ->val = head ->val;
    smaller ->next = head ->next;
    pivotHelper((head->next), (smaller->next), larger,pivot);
  }
  else if((head->val) >pivot){
    larger = head;
    larger ->val = head->val;
    larger ->next = head->next;
    pivotHelper((head->next), smaller, (larger->next),pivot);
  }
}