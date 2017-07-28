#include <stdio.h>
#include <stdlib.h>
#include "linkList.c"

linkList * head = NULL;

typedef struct{
    int types;
    char * stuff;
}returns;

int type_int = 0;
int type_float = 1;
int type_string = 2;



void push_int(int val){
    push(type_int, val);
}
void push_float(float val){
    push(type_float, val);
}
void push_char(char * val){
    push(type_string, val);
}
void push(int type, char * val) {
    linkList * new_node;
    linklist ** theHead = &head;
    new_node = malloc(sizeof(linkList));
    if(type != type_string)
    {
        new_node->data = malloc(sizeof(val));
    }
    else
    {
        new_node->data = malloc(strlen(val));
    }
    new_node->next = *theHead;
    *theHead->previous = new_node;
    *theHead = new_node;
}






int pop_int(){
    //returns is a special structure that holds the type of information and the information itself
    returns print = pop(type_int);
    return (int) (print->stuff);
}
float pop_float(){
    returns print = pop(type_float);
    //this first one calls the unspecific pop function
    return (float) (print->stuff);
    //this returns the special information in the specified form
}
char * pop_char(){
    returns print = pop(type_string);
    return print->stuff;
}
returns pop(int type) {
    linkList ** theHead = &head;
    returns * retval = malloc(sizeof(returns));
    linkList * next_node = NULL;

    if (*theHead == NULL) {
        //Return something of value?
        return -1;
    }

    next_node = (*theHead)->next;
    next_node->previous = NULL;
    if(type != type_string){
        retval->stuff = malloc(sizeof(val));
    }
    else{
        retval->stuff = malloc(strlen(val));
    }
    retval->stuff = (*theHead)->data;
    retval->types = (*theHead)->types;
    free(*theHead);
    (*theHead) = next_node;

    return retval;
}





int remove_last_int(){
    returns print = remove_last(type_int);
    return (int) (print->stuff);
}
float remove_last_float(){
    returns print = remove_last(type_float);
    return (float) (print->stuff);
}
char * remove_last_char(){
    returns print = remove_last(type_string);
    return print->stuff;
}
returns remove_last(int type) {
    returns * retval = malloc(sizeof(returns));    /* if there is only one item in the list, remove it */
    if (head->next == NULL) {
        if(type != type_string){
            retval->stuff = malloc(sizeof(val));
        }
        else{
            retval->stuff = malloc(strlen(val));
        }
        retval->stuff = head->data;
        free(head);
        head = NULL;
        return retval;
    }

    /* get to the last node in the list */
    linkList * current = head;
    //looks at current->next->next because current->next will need to be deleted when it is removed from the list and the previous item (current) needs to not have its pointer pointing there
    while (current->next->next != NULL) {
        current = current->next;
    }

    /* now current points to the last item of the list, so let's remove current->next */
    if(type != type_string){
        retval->stuff = malloc(sizeof(val));
    }
    else{
        retval->stuff = malloc(strlen(val));
    }
    retval = current->next->data;
    free(current->(*next));
    current->next = NULL;
    return retval;
}




int remove_int_by_index(int index);
{
    returns print = remove_by_index(&head, type_int, index);
    return (int) print->stuff;
}
float remove_float_by_index(int index);
{
    returns print = remove_by_index(&head, type_float, index);
    return (float) print->stuff;
}
char * remove_string_by_index(int index);
{
    returns print = remove_by_index(&head, type_string, index);
    return print->stuff;
}
returns remove_by_index(int type, int index) {
    int i = 0;
    returns * retval = malloc(sizeof(returns));
    retval->types = type;
    linkList theHead = &head
    linkList * current = *theHead;
    linkList * temp_node = NULL;

    if (index == 0) {
        return pop(type);
    }

    for (int i = 0; i < index-1; i++) {
        if (current->next == NULL) {
            //Change to return bad value?
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval->stuff = temp_node->val;
    current->next = temp_node->next;
    //POSSIBLE BUG, NOT SURE HOW TO FIX
    temp_node->next->previous = current;
    free(temp_node);


    return retval;
}




//RETURNS -1 IF ITEM DOES NOT APPEAR IN LINKED LIST
//RETURNS FIRST MENTION OF ITEM IN LIST
int find_index( int type, char * info)
{
    //index number of current item
    int i = 0;
    theHead = &head;
    linkList * current = *theHead;

    if(type == type_string){
        while( strcmp(current->data, info) != 0 && current->next != NULL){
            current = current->next;
            i++;
        }
    }
    else{
        if(type == current->type){
            while( ( current->data != info && current->next != NULL ){
                current = current->next;
                i++;
            }
    }
    
    if(current->data != info && current->next == NULL){
        return -1;
    }
    
    return i;
}



/*
int find_index(linkList ** head, int type, char * info)
{
    //index number of current item
    int i = 0;
    linkList * current = *head;

    if(type = 0){
        while( ((int) current->data) != (int) info){
            current = current->next;
            i++;
        }
    }
    else{
        if(type = 1){
            while( ((float) current->data) != (float) info){
                current = current->next;
                i++;
            }
        }
        else{
            if(type = 2){
                while(strcmp(info,current->data) != 0){
                    current = current->next;
                    i++;
                }
            }
        }
    }
    
    free(current);
    free(retval);
    return i;
}
*/ //Old bad find_index when not thinking about type variable in linkList