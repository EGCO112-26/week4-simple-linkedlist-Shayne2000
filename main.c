//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include <string.h>

void show (struct node z) {
    struct node *test ;
    test = &z ;
    while (test->next != NULL){
        printf("%d\n",test->value);
        test = test->next ;
    }
}



struct studentNode
{
    int id ;
    char name[30] ;
    struct studentNode *next;
};

void showName (struct studentNode z) {
    struct studentNode *test ;
    test = &z ;
    while (test->next != NULL){
        printf("%d %s\n",test->id,test->name);
        test = test->next ;
    }
}

int main(int argc, const char * argv[]) {
    int x=5;
    struct node a,b,c,d,*head ;
    a.value = x;
    a.next=&b;
    head=&a;
    b.value=head->value+3;

    // printf("%d\n", head ->value ); //what value for 5
    // printf("%d\n", head ->next->value ); //what value for 8
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */

b.next = &c ;
c.value = 11 ;
c.next = NULL ;

    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
struct node z ;
z.value = 2 ;
z.next = &a ;


struct node y ;
a.next = &y ;
y.next = &b ;
y.value = 123 ;

// show(z);
    


    typedef struct node* NodePtr;
    NodePtr tmp=&z; //add temp value to faciliate
        
    /*  Exercise III Use loop to print everything
        int i,n=5;
        for(i=0;i<n;i++){
            printf("%3d", tmp->value);
          // What is missing???
        }
    */
    // int i,n=5;
    // for(i=0;i<n;i++){
    //     printf("%5d", tmp->value);
    //     tmp = tmp->next;
    // }
    
   /*  Exercise IV change to while loop!! (you can use NULL to help)
       
         while(){
            printf("%3d", tmp->value);
           // What is missing???
        }
    */
    // while(tmp != NULL){
    //     printf("%5d", tmp->value);
    //     tmp = tmp->next ;
    // }
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help
          
     */
    int n = 10 ;
    struct node *p,*h ;
    h = (struct node*)malloc(sizeof(struct node));

    p = h ;
    
    for (int i = 0 ; i < n-1 ; i ++) {
        
        p->value = i ;

        p->next = (struct node*)malloc(sizeof(struct node));

        p = p->next ;
    }p->value = 55 ;
    // show(*h);





    /*  Exercise VI Free all node !!
         //use a loop to help
          
     */

    p = h ;
    for (int i = n ; i >= 0 ; i --){
        p = h ;
        for (int j = 0 ; j < i ; j ++) {
            p = p->next ;
        }
        free(p);
    }

    // show(*h);



    struct studentNode *P,*H ;

    H = (struct StudentNode *)malloc(sizeof(struct studentNode)) ;
    P = H ;
    for (int i = 1 ; i < (argc+1)/2 ; i ++) {
        P->id = atoi(argv[(i-1)*2+1]);
        strcpy(P->name,argv[(i-1)*2+2]);
        P->next = (struct StudentNode *)malloc(sizeof(struct studentNode)) ;

        P = P->next ;
    }

    showName(*H);


    
    for (int i = 0 ; i < argc/2 ; i ++){
        P = H->next ;
        free(H);

        H = P ;
    }



    return 0;
}