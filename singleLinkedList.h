#include <malloc.h>

/************************************************
 *	Single Linked List Function Library	 		*
 *	file: singleLinkedList.h			 		*
 *	author: Diego Alberto Rincon				*	
 *	url: https://github.com/d1egoprog/COURSE-C	*
 ************************************************
*/

// Node Definition for a Single Linked List
struct SingleLinkedListNode{
	int data;
	SingleLinkedListNode *next;
};
// Definition of data type
typedef SingleLinkedListNode SLLN;

// Function Definition
// Node Creation Functions
SLLN* createNode(int data);
SLLN* createNodeAtEnd(SLLN *head, int data);
SLLN* createInteractiveSingleList(void);
// Utilities Function
void printList(SLLN* n);
SLLN* getDataNfromList(SLLN* n, int index);

// Retrieve the Node from a list with a index
SLLN* getDataNfromList(SLLN *n, int index){
	int i=1;
	while(n->next&&i<index){
		n=n->next;
		i++;
	}
	return n;
}

// Print a Single Linked Data 
void printList(SLLN* n){
	while(n){
		printf("%i\t",n->data);
		n=n->next;
	}
}

// Add a new Node to a Single Linked List 
SLLN* createNodeAtEnd(SLLN *head, int data){
	SLLN *n = head;
	SLLN *newNode = createNode(data);
	if(n){
		while(n->next){
			n=n->next;
		}
		n->next=newNode;
	}else{
		head = newNode;
	}
	return head;
}

//Create a new Memory space for a new Node Based on a Single Linked List
SLLN* createNode(int data){
	SLLN *n=(SLLN*) malloc (sizeof(SLLN*));
	n->data=data;
	n->next=NULL;
}

// Create a SingleLinkedList in a interactive mode
SLLN* createInteractiveSingleList(){
	int n;
	SLLN *head=NULL,*newNode=NULL, *prev=NULL;
	printf("Type the data for the new Node: ");
	scanf("%i",&n);
	do{
		prev=newNode;
		newNode=createNode(n);
		if(head==NULL){
			head=newNode;
		}else{
			prev->next=newNode;
		}
		printf("Type the data for next Node (0 to exit: ");
		scanf("%i",&n);
		
	}while(n!=0);
	return head;
}
