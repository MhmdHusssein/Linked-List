/*
	Name: Mohamed Hussein Mohamed Salem
	LinkedList 
*/

#include <stdio.h>
#include <stdlib.h>
#include "STD_Types.h"

typedef struct Node_Type node;

struct Node_Type{
	u32 Value;
	node *Next;
};

void AddNode(u32 Val);
void PrintLinkedList(void);
void DeleteNode(void);
void NewNode(u32 val,u32 pos);

u32 ListLength = 0;

node *head = NULL;

void main()
{
	u32 INPUT;
	u32 NewValue;
	u8 ExitFlag = 0;
	u32 new_value,pos;
	u32 position;
	
	while (ExitFlag == 0)
	{
		printf("To add node enter 0\n");
		printf("To print Linked List enter 1\n");
		printf("To DELETE certain node enter 2\n");
		printf("To ADD node at  certain position enter 3\n");
		printf("To EXIST enter 4\n");
		printf("Your Choice: "); fflush(stdout);
		scanf("%d",&INPUT);
		
		switch(INPUT)
		{
			case 0: printf("please enter node value = "); fflush(stdout);
                    scanf("%d",&NewValue);
                    AddNode(NewValue);
                    printf("Node ADDED, THANK YOU\n\n\n");          break;
     
            case 1: PrintLinkedList();                              break;
            
            case 2: DeleteNode();                                   break;
			
			case 3: printf("Enter the value you want to add = "); fflush(stdout);
	                scanf("%d",&new_value);
	
	                printf("Enter the position you want to add new node at = "); fflush(stdout);
	                scanf("%d",&pos);
					
	        		NewNode(new_value,pos);                   		break; 
			                                                        
            case 4: printf("Thank You\nGood Bye");  ExitFlag = 1;   break;
			
            default: printf("Invalid Choice, please try again.\n"); break; 			
		}
	}
	
}

void AddNode(u32 Val)
{
	/* First Node to Create */
	if (ListLength == 0)
	{
		node *temP = (node*)malloc(sizeof(node));  //it will insert a new node to the start of the linked list
    	temP->Value=Val;
    	temP->Next=head;
    	head=temP;
	}
	
	
	else
	{
		node *last;
		
		/* Allocate the node */
		node *new = (node*) malloc(sizeof(node));
		
		/* Assign the received value to the new node */
		new -> Value = Val;
		/* Make the new node next pointer to Null, as it will 
		be added to the end of the list */
		new -> Next  = NULL;
		
		last = head;
		
		/* Search for the last node */
		while( (last -> Next) != NULL )
		{
			last = (last -> Next);
		}
		
		last -> Next = new;
	}
	
	/* Increase the list length by one node */
	ListLength++;
	
	return;
}

void PrintLinkedList(void)
{
	printf("\n\n----------------------\n");
	/* at lease 1 node is created */
	if (ListLength > 0)
	{
		node *Last = head;
		u32 i = 1;
		
		/* Print the list head */
		printf("Node Number %d = %d\n", i,Last -> Value);
	
		/* Print all nodes util you find the last node
		which has the next pointer equals to NULL  */
		while ((Last -> Next) != NULL)
		{
			i++;
			Last = Last -> Next;
			printf("Node Number %d = %d\n",i,Last -> Value);
		}
	}
	
	else
	{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
}

void DeleteNode(void)
{
	u32 i,position;
	node *Temp=head;
	node *last;
	
	printf("\n\n----------------------\n");
	
	if (ListLength > 0)
	{
		PrintLinkedList();
		
		printf("Enter position of value you want to delete between(0 - %d):\n\n ",ListLength-1);
		printf("Enter the position of value you want to delete = "); fflush(stdout);
	    scanf("%d",&position); 
		
		if(position < ListLength)
		{
		
		if (head == NULL)
            return;
 
        // If head needs to be removed
        if (position == 0)
        {
            head = Temp->Next;   // Change head
            free(Temp);		// free old head
            printf("Node Deleted\n");
			ListLength--;
		    return;
        }
 
        // Find previous node of the node to be deleted
        for (i=0; Temp!=NULL && i<position-1; i++)
          Temp = Temp->Next;
 
         // If position is more than number of nodes
        if (Temp == NULL || Temp->Next == NULL)
             return;
 
           // Node temp->next is the node to be deleted
           // Store pointer to the next of node to be deleted
        node *next = Temp->Next->Next;
 
          // Unlink the node from linked list
        free(Temp->Next);  // Free memory
 
        Temp->Next = next;		// Unlink the deleted node from list
		ListLength--;
		printf("Node Deleted\n");
		}else{
			printf("position doesn't exist.\n");
		}
	}else{
		printf("List is Empty\n");
	}
	
	printf("----------------------\n\n\n");
	
}

void NewNode(u32 val,u32 pos)
{
	u32 new_value;
	
	if(pos > ListLength)
	{
        printf("\n\nEnter a valid position.\n\n");
	}else{		
	printf("\n\n----------------------\n");
	
	if (ListLength > 0)
	{
	    node *ptr = (node*)malloc(sizeof(node));
    	ptr->Value=val;		//Creating a new node
    	u32 i;
    	node *temp=head;
    	if(pos==0)
        {
        	ptr->Next=temp;	
			head = ptr;
			ListLength++;
			printf("Node ADDED, THANK YOU\n");
			printf("----------------------\n\n\n");
    		return;
    	}
		
    	for(i=1;i<pos-1;i++)  //moving to the (n-1)th position node in the linked list
    	{
        	temp=temp->Next;
    	}

    	ptr->Next=temp->Next;  //Make the newly created node point to next node of ptr temp
    	temp->Next=ptr; 
	
		
	}
	ListLength++;
	
	printf("Node ADDED, THANK YOU\n");
	
	printf("----------------------\n\n\n");
	
	}
	
	
}