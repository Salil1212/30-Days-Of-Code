// Add two numbers represented by linked lists
// MediumAccuracy: 34.52%Submissions: 257K+Points: 4
//  Done with winning Geekbits? Now win GfG Bag, GfG T-shirt & much more just by writing your experiences. Start Writing, Start Winning.
// banner
// Given two numbers, num1 and num2, represented by linked lists of size n and m respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

// Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

// Example 1:

// Input:
// n = 2
// num1 = 45 (4->5->null)
// m = 3
// num2 = 345 (3->4->5->null)
// Output: 
// 3->9->0->null  
// Explanation: 
// For the given two linked list (4 5) and (3 4 5), after adding the two linked list resultant linked list will be (3 9 0).
// Example 2:

// Input:
// n = 4
// num1 = 0063 (0->0->6->3->null)
// m = 2
// num2 = 07 (0->7->null)
// Output: 
// 7->0->null
// Explanation: 
// For the given two linked list (0 0 6 3) and (0 7), after adding the two linked list resultant linked list will be (7 0).
// Your Task:
// The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

// Expected Time Complexity: O(n+m)
// Expected Auxiliary Space: O(max(n,m)) for the resultant list.

// Constraints:
// 1 <= n, m <= 104

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverse(struct Node* head){
        struct Node* prev=NULL;
        struct Node* cur=head;
        while(cur){
            struct Node* nex=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nex;
            
        }
        return prev;
    }
    struct Node* sumTwoLists(struct Node* head1,struct Node* head2){
        struct Node* ans=new Node(-1);
        int carry=0;
        struct Node* temp1=head1;
        struct Node* temp2=head2;
        struct Node* temp=ans;
        while(temp1 || temp2 ||carry ){
      
        int val=0;
        
          if(temp1){
              val +=temp1->data;
              temp1=temp1->next;
              
          }
          if(temp2){
              val +=temp2->data;
              temp2=temp2->next;
          }
          if(carry){
              val +=carry;
              
          }
          int digit=val%10;
          carry=val/10;
          struct Node* n=new Node(digit);
          temp->next=n;
          temp=temp->next;
        }
        
      
        return ans->next;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        struct Node* temp1=reverse(num1);
        struct Node* temp2=reverse(num2);
        struct Node* temp=sumTwoLists(temp1,temp2);
        struct Node* ans=reverse(temp);
        while(ans && ans->data==0){
            ans=ans->next;
        }
        if(!ans){
            return new Node(0);
        }
        return ans;
        
        
        
        
        
    }
};