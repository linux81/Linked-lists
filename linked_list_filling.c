#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {

  FILE *fp;
int liczba;

struct Node 
{
  int data;
  struct Node *next;
};
struct Node* head;
head= (struct Node *)malloc(sizeof(struct Node));

void append(int num, struct Node*right)
{
    struct Node *temp;
    temp= (struct Node *)malloc(sizeof(struct Node));
    temp->data=num;
    
    while(right->next != NULL)
    right=right->next;
    right->next =temp;
    right=temp;
    right->next=NULL;
}


void printList(struct Node *n)
{
  while (n != NULL)
  {
     printf(" %d \n", n->data);
     n = n->next;
  }
}






  fp = fopen("liczby3.txt", "r");
  if (fp == NULL) {
    printf("there was an error opening file \n");
    return 1;
  }
  else {

    while (!feof(fp)) {
      fscanf(fp, "%d", &liczba);
      
      append(liczba, head);

      
    }
    fclose(fp);
printList(head);
  }

  return 0;
}
