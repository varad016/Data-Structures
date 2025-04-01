#include<stdio.h>
#include<stdlib.h>

struct node{
  int a;
  struct node *next;
};

struct node *head=0;

void insert(int n){
  struct node *temp=(struct node *)malloc(sizeof(struct node));
  temp->a=n;
  temp->next=head;
  head=temp;
}

int main(){
 insert(10);
 insert(20);
 insert(30);


  if(head==0){
    printf("LINKEDLIST IS EMPTY");
  }

  struct node *p=head;

  while(p!=0){
    printf("%d ",p->a);
    p=p->next;
  }

  return 0;
}