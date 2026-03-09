#include<stdio.h>
#include<stdlib.h>
#define size 10
struct node
{
	int key;
	struct node *next;
};
void initialize(struct node *table[])
{
	int i;
	for(i=0;i<size;i++)
	{
		table[i]=NULL;
	}
}
int hash(int key)
{
	return key%size;
}
void insert(struct node *table[],int key)
{
	int index=hash(key);
	struct node *new=(struct node*)malloc(sizeof(struct node));
	new->key=key;
	new->next=table[index];
	table[index]=new;
	printf("Inserted %d\n",key);
}
int search(struct node*table[],int key)
{
	int index=hash(key);
	struct node *temp=table[index];
	while(temp!=NULL)
	{
		if(temp->key==key)
		 return 1;
		temp=temp->next;
	}
	return 0;
}
void delete(struct node *table[],int key)
{
	int index=hash(key);
	struct node *temp=table[index],*prev=NULL;
	while(temp!=NULL&&temp->key==key)
	{
		table[index]=temp->next;
		free(temp);
		printf("Deleted %d\n",key);
		return;
	}
	while(temp!=NULL&&temp->key!=key)
	{
		prev=temp;
		temp=temp->next;
	}
	if(temp==NULL)
	{
		printf("%d key is not found\n",key);
		
	}
	prev->next=temp->next;
	free(temp);
	printf("Deleted %d\n",key);
}
void display(struct node *table[])
{
	int i;
	for(i=0;i<size;i++)
	{
		printf("[%d]->",i);
		struct node *temp=table[i];
		while(temp!=NULL)
		{
			printf("%d->",temp->key);
			temp=temp->next;
		}
		printf("NULL\n");
		}
}
int main() {
  struct node* hash_table[size];
 initialize(hash_table);
 int choice, key;
 do {
 printf("---- Hash Table Menu ----\n");
 printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 printf("Enter key to insert: ");
 scanf("%d", &key);
 insert(hash_table, key);
 break;
 case 2:
 printf("Enter key to search: ");
 scanf("%d", &key);
if (search(hash_table, key))
 printf("Key %d found\n", key);
 else
 printf("Key %d not found\n", key);
 break;
 case 3:
 printf("Enter key to delete: ");
 scanf("%d", &key);
 delete(hash_table, key);
 break;
 case 4:
 display(hash_table);
 break;
 case 5:
 printf("Exiting...\n");
 break;
 default:
printf("Invalid choice. Try again.\n");
 }
 } while (choice != 5);
 return 0;
}
