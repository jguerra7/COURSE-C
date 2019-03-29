#include <stdio.h>
#include <malloc.h>

/************************************************
 *	Binary Tree Function Library		 		*
 *	file: binaryTree.h					 		*
 *	author: Diego Alberto Rincon				*	
 *	url: https://github.com/d1egoprog/COURSE-C	*
 ************************************************
*/

struct BinaryTree{
	int data;
	BinaryTree *left;
	BinaryTree *right;
};

typedef struct BinaryTree BT;

BT *createBinaryTree(BT *node);
BT *createRandomBinaryTree(BT *node, int level);
BT *createBinaryTreeNode(bool generate);
void printBinaryTree(BT *root, int level, int father, char side);
void preOrder(BT *root);
void inOrder(BT *root);
void postOrder(BT *root);

BT *createBinaryTree(BT *node){
	BT *son = NULL;
	if (node == NULL){
		node = createBinaryTreeNode(false);
	}
	int choise = -1;
	printf("Travel by Left Side? (1)Yes o (0)No :\t");
	scanf("%i",&choise);
	if(choise == 1){
		son=createBinaryTree(node->left);
		node->left=son;
	}
	printf("Travel by Right Side? (1)Si o (0)No :\t"); 
	scanf("%i",&choise);
	if(choise == 1){
		son=createBinaryTree(node->der);
		node->der=son;
	}
	printf("Returning to context of %i \n",node->data); 
	return node;
}

BT *createRandomBinaryTree(BT *node, int level){
	BT *son = NULL;
	int choise;
	if (node == NULL){
		node = createBinaryTreeNode(true);
	}
	if (level >= 0){
		level--;
		choise = rand()%10;
		if(choise <= 7){
			son=createRandomBinaryTree(node->left,level);
			node->left=son;
		}
		choise = rand()%10;
		if(choise <= 7){
			son=createRandomBinaryTree(node->right,level);
			node->right=son;
		}
	}
	return node;
}

BT *createBinaryTreeNode(bool generate){
	BT *node = NULL;

	int data = rand()%50;
	if (!generate){
		printf("Type the data for node:\t"); 
		scanf("%i",&data);
	}
	node = (BT *)malloc(sizeof (BT));
	node->data = data;
	node->right = NULL;
	node->left = NULL;
	return node;
}

void printBinaryTree(BT *root, int level, int father, char side) {
	int i;
	if(root) {
		printBinaryTree(root->right,level+1, root->data,'R');
		printf("\n\n");
		for (i=0;i<level;i++)
				printf("       ");
		printf("(%d-%c)--%d",father, side, root->data);
		printBinaryTree(root->left,level+1,root->data,'L');
	}
	return;
}

void preOrder(BT *root){
	if (root){
		printf("-%i-",root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
	return;
}

void inOrder(BT *root){
	if (root){
		inOrder(root->left);
		printf("-%i-",root->data);
		inOrder(root->right);
	}
	return;
}

void postOrder(BT *root){
	if (root){
		postOrder(root->left);
		postOrder(root->right);
		printf("-%i-",root->data);
	}
	return;
}
