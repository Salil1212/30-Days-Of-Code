// Merge Sort on Doubly Linked List
// MediumAccuracy: 68.49%Submissions: 30K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given Pointer/Reference to the head of a doubly linked list of n nodes, the task is to Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing order.

// Example 1:

// Input:
// n = 8
// value[] = {7,3,5,2,6,4,1,8}
// Output:
// 1 2 3 4 5 6 7 8
// 8 7 6 5 4 3 2 1
// Explanation: After sorting the given
// linked list in both ways, resultant
// matrix will be as given in the first
// two line of output, where first line
// is the output for non-decreasing
// order and next line is for non-
// increasing order.
// Example 2:

// Input:
// n = 5
// value[] = {9,15,0,-1,0}
// Output:
// -1 0 0 9 15
// 15 9 0 0 -1
// Explanation: After sorting the given
// linked list in both ways, the
// resultant list will be -1 0 0 9 15
// in non-decreasing order and 
// 15 9 0 0 -1 in non-increasing order.
// Your Task:
// The task is to complete the function sortDoubly() which takes reference to the head of the doubly linked and Sort the given doubly linked list using Merge Sort in both non-decreasing and non-increasing. The printing is done automatically by the driver code.

// Expected Time Complexity: O(nlogn)
// Expected Space Complexity: O(logn)

// Constraints:
// 1 <= n <= 104
// -105 <= values[i] <= 105

  #include<iostream>
  #include<bits/stdc++.h>
  using namespace std;
  
  struct Node{
      int data;
      struct  Node* next, * prev;
      Node(int x){
          data=x;
          next=prev=NULL;
      }
  };
  
  
  struct Node* middle(struct Node *head){
        struct Node* slow=head;
        struct Node* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    struct Node* merge(struct Node* left,struct Node* right){
        if(!left) return right;
        if(!right) return left;
        struct Node* ans=new Node(-1);
        struct Node* temp=ans;
        while(left && right){
            if(left->data<right->data){
                temp->next=left;
                left->prev=temp;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                right->prev=temp;
                temp=right;
                right=right->next;
            }
        }
        while(left){
            temp->next=left;
            left->prev=temp;
            temp=left;
            left=left->next;
            
        }
        while(right){
            temp->next=right;
            right->prev=temp;
            temp=right;
            right=right->next;
        }
      ans=ans->next;
      ans->prev=NULL;
      return ans;
    }
    struct Node *sortDoubly(struct Node *head) {
        // Your code here
        if(!head|| !head->next) return head;
        struct Node* mid=middle(head);
        struct Node* left=head;
        struct Node* right=mid->next;
        mid->next=NULL;
        right->prev=NULL;
        left=sortDoubly(left);
        right=sortDoubly(right);
        struct Node* result=merge(left,right);
        return result;
        
 }
 int main(){
     struct Node* n1=new Node(7);
     struct Node* n2=new Node(3);
     struct Node* n3=new Node(5);
     struct Node* n4=new Node(2);
     struct Node* n5=new Node(6);
     struct Node* n6=new Node(4);
     struct Node* n7=new Node(1);
     struct Node* n8=new Node(8);
     n1->next=n2;
     n2->prev=n1;
     n2->next=n3;
     n3->prev=n2;
     n3->next=n4;
     n4->prev=n3;
     n4->next=n5;
     n5->prev=n4;
     n5->next=n6;
     n6->prev=n5;
     n6->next=n7;
     n7->prev=n6;
     n7->next=n8;
     n8->prev=n7;
     struct Node * ans=sortDoubly(n1);
  struct Node* temp=ans;
  while(temp){
      cout<<temp->data<<" ";
      temp=temp->next;
  }
  
     
     return 0;
     
 }