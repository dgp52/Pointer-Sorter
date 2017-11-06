//Name: Viraj Patel -vjp60
//Deepkumar Patel - dgp52
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//Define struct for linked list nodes.
typedef struct node {
  char* val;
  struct node * next;
} node_t;

//Print values of linked list.
void printLinkedlist(node_t * head) {
  node_t * current = head;
  //If ther's no words.
  if(head == NULL) {
    printf("No words found\n");
  } else {
    //Else print all words in the list
    while (current != NULL) {
      printf("%s\n", current->val);
      current = current->next;
    }
  }
}

//Free memory allocated for linked list nodes.
void releaseMemory(struct node* head) {
  struct node* tmp;
  while (head != NULL)
    {
      tmp = head;
      head = head->next;
      free(tmp);
    }
}

int main (int argc, char** argv) {
  //Check the number of inputs and 
  //Check if the input is empty and show error message
  if(argc!=2 || strlen(argv[1])==0){
    printf("Invalid input\n");
    return 1;
  }
  //Get the input string using argv[1]
  char *mychar = NULL;
  mychar = argv[1];
  //Convert non-alphabetic character into space
  int counter = 0;
  while(counter<strlen(argv[1])){
    if(!(islower(mychar[counter]) || isupper(mychar[counter]))){
      mychar[counter] = ' ';
    }
    counter++; 
  }
  //Split words on spaces 
  char* splitw;
  node_t * head = NULL;
  splitw = strtok (mychar," ");
  while (splitw !=NULL) {
    //Create sorted linked list
    if (head == NULL) {
      head = malloc(sizeof(node_t));
      //Error Message if memory allocation fails
      if (head == NULL) {
	printf("Failed to allocate memory\n");
	return -1;
      }
      head->val=splitw;
    } else {
      //Create two pointers.
      //newNode: add this new node
      node_t* newNode;
      newNode = malloc(sizeof(node_t));
      //Error Message if memory allocation fails
      if (newNode == NULL) {
	printf("Failed to allocate memory\n");
	return -1;
      }
      newNode->val=splitw;
      //currentNode: Points to the current node
      node_t* currentNode;
      currentNode =head;
      //previousNode: Points to the node current was previously pointing at
      node_t* previousNode;
      previousNode = 0;
      //Find the location to insert the node by comparing strings
      while(currentNode!=0){
	//compare strings using strcmp
	if(strcmp(currentNode->val,newNode->val) > 0){
	  break;
	} else {
	  previousNode=currentNode;
	  currentNode=currentNode->next;
	}
      }
      //If currentNode points to head else insert somewhere after the head
      if(currentNode==head) {
	newNode->next=head;
	head=newNode;
      } else {
	newNode->next =currentNode;
	previousNode->next=newNode;
      }
    }
    splitw = strtok(NULL, " ");
  }
  //Print all sorted elements
  printLinkedlist(head);
  //Release or free Malloc
  releaseMemory(head);
  return 0;
}
