/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
struct node * sortLinkedList(struct node *head) {
	if (head != NULL){
		struct node* temp1;
		struct node* temp2;
		struct node* temp = NULL;
		for (temp1 = head; temp1->next != head; temp1 = temp1->next){
			temp = temp1;
			for (temp2 = temp1->next; temp2 != head; temp2 = temp2->next){
				if (temp1->data > temp2->data){
					int t = temp1->data;
					temp1->data = temp2->data;
					temp2->data = t;
				}
			}
		}
		return head;
	}
	return NULL;
}

int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	struct node* p = (struct node*)*head1;
	struct node* q = (struct node*)*head2;
	if (p != NULL && q != NULL){

		struct node *temp = NULL;
		struct node *r = NULL;
		r = p;
		temp = p;
		while (temp->next != p)
			temp = temp->next;
		temp->next = q;
		temp = q;
		while (temp->next != q)
			temp = temp->next;
		temp->next = r;
		struct node* temp1 = r;
		int count = 1;
		temp1 = temp1->next;
		while (temp1 != r){
			count++;
			temp1 = temp1->next;
		}
		*head1 = r;
		return count;
	}
	return -1;
}