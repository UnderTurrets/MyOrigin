#include<stdio.h>
#include<stdlib.h>



 
typedef struct node
{
    int val;
    struct node * next;
} ListNode;

typedef struct 
{
    int size;
    ListNode* head;
    
    // ListNode* tail;

    // if possible,you can add some function pointer here
} LinkList;

size_t TempSize(LinkList* list);


// create a LinkList
LinkList* CreateLinkList()
{
    LinkList* res=(LinkList*)malloc(sizeof(LinkList));
    res->head=NULL;
    res->size=0;
    return res;
}

// return the size of list
size_t TempSize(LinkList* list)
{   ListNode *temp=list->head;int i=1;
    for(temp;temp->next;temp=temp->next){
    	i++;
    	
	}
return i;

}



// insert an element right next to the index
// remeber to update size of list!
void Insert(LinkList* list,int index,int val)
{   int lim=TempSize(list);
      ListNode*insert=(ListNode*)malloc(sizeof(ListNode));
      insert->val=val;insert->next=NULL;
      int i=0;
    if(index<=lim&&index!=0){
      ListNode *temp1=list->head;
      if (temp1){
     	  for(i;i<index-1;i++){
     		  temp1=temp1->next;
		   }
		   ListNode*temp2=(ListNode*)malloc(sizeof(ListNode));
		   temp2=temp1->next;
		   temp1->next=insert;
		   insert->next=temp2; 
	   }
	}else{
		insert->next=list->head;
		list->head=insert;
	}    
	
	     
	     
	     
	     
        
	     
	
      

}

// append an element to the end of the LinkList
// remeber to update size of list!
void Append(LinkList* list,int val){
    
	 ListNode* p=(ListNode*)malloc(sizeof(ListNode));
     p->val= val; p-> next=NULL;
     ListNode* last=list -> head;
     if(last){
     	while(last->next){
     		last= last->next;
		 }
		 last->next =p;
	 }else{
	 	list->head=p;
	 }

}


// Get element by its index
int Get(LinkList* list,int index)
{   ListNode *temp=list->head;int i,ret;
    for(i=0;i<index ;i++){
    	temp=temp->next;
	}
	ret = temp->val;

    return ret;
}

// delete an element by its index
// remeber to update size of list!
void DeleteNode(LinkList* list,int index)
{   ListNode*temp2=list->head;
    ListNode*temp1=NULL;
	int i;
	if(index!=0){
	  for(i=0;i<index;i++){
    	temp1 = temp2;
    	temp2 = temp2->next;
		}
	  if (temp2->next){
	   temp1->next = temp2->next;
	  }
      free(temp2);
	}else{
		list->head=list->head->next;
		free(temp2);
	}
    	
}




// delete the whole list, attention!!! you should release all memory.
// memory leak is prohibited
void DeleteList(LinkList* list)
{   ListNode*temp1,*temp2;
    for(temp1=list->head;temp1;temp1=temp2){
    	temp2=temp1->next;
    	free(temp1);
    	
	}

}

// judge if the list is empty
_Bool IsEmpty(LinkList* list)
{  ListNode *temp=list->head;int i;
    if (temp->next!=NULL){
    	printf("这是一个非空链表"); 
		i=1; 
	}else{printf("这是一个空链表");i=0 ;
	}
return i;

}



// you can add more method,including sort,merge......


int main()
{   int i;
    LinkList* mylist=CreateLinkList();
    for(i=0;i<10;i++)
    {
        Append(mylist,i);
    }
//    for( i=0;i<10;i++)
//    {
//        printf("%d ",Get(mylist,i));
//    }
//    for (i=0;i<5;i++)
//    {
//        DeleteNode(mylist,i);
//    }
//    printf("size of list is:%d",TempSize(mylist));
    Insert(mylist,0,9);
    for( i=0;i<11;i++)
    {
        printf("%d ",Get(mylist,i));
    }
    printf("\n%d\n",mylist->head->val);
    DeleteList(mylist);
    
    return 0;
}
