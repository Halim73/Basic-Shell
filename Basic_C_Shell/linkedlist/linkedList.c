#include"linkedList.h"

LinkedList* linkedList(){
    LinkedList* list = calloc(1,sizeof(LinkedList));
    list->head = calloc(1,sizeof(Node));
    
    list->head->data = NULL;
    list->head->next = NULL;
    list->head->prev = NULL;
    
    list->size = 0;
    
    return list;
}

void addLast(LinkedList* list, Node* node){
    if(list == NULL || node == NULL){
        perror("List is NULL");
        exit(-99);
    }
    
    Node* current = list->head;
    
    while(current->next){
        current = current->next;
    }
    current->next = node;
    node->prev = current;
    
    list->size++;
}

void addFirst(LinkedList* list, Node* node){
    
    node->next = list->head->next;
    node->prev = list->head;
    
    if(list->head->next != NULL)list->head->next->prev = node;
    
    list->head->next = node;
    
    list->size++;
}

void removeFirst(LinkedList* list, void (*removeData)(void*)){
    void* temp = list->head->next->data;
    Node* aux = list->head->next;
    
    list->head->next = aux->next;
    aux->next->prev = list->head->next;
    
    removeData(temp);
    aux->data = NULL;
    free(aux);
    
    list->size--;
}

void removeLast(LinkedList* list, void(*removeData)(void*)){
    Node* current = list->head->next;
    
    while(current->next){
        current = current->next;
    }
    current->prev->next = NULL;
    
    removeData(current->data);
    free(current);
    
    list->size--;
}

void removeItem(LinkedList* list, Node* node, void (*removeData)(void*), int (*compare)(const void*, const void*)){
    Node* current = list->head->next;
    
    while(current){
        if(compare(current->data,node->data) == 0){
            current->prev->next = current->next;
            
            if(current->next != NULL)current->next->prev = current->prev;
            
            removeData(current->data);
            current->data = NULL;
            free(current);
            
            removeData(node->data);
            node->data = NULL;
            free(node);
            
            list->size--;
            return;
        }
        current = current->next;
    }
}

void clearList(LinkedList* list, void (*removeData)(void*)){
    Node* current = list->head->next;
    Node* temp;
    
    while(current){
        temp = current;
        current = current->next;
        
        removeData(temp->data);
        temp->data = NULL;
        free(temp);
    }
    free(list->head);
    list->head = NULL;
    
    list->size = 0;
}

void* get(const LinkedList* list,int x){
    int i;
    Node* current = list->head->next;
    for(i=0;i<x;i++){
        current = current->next;
    }
    return current->data;
}

void* getItem(LinkedList* list, Node* node,int (*compare)(const void*, const void*)){
    Node* current = list->head->next;
    printf("searching for item");
    while(current){
        if(compare(current->data,node->data) == 0){
            printf("found item");
            return current->data;
        }
        current = current->next;
    }
    return NULL;
}

void printList(const LinkedList* list, void (*convertData)(void*)){
    Node* current = list->head->next;
      
    printf("\n");
    while(current){
        convertData(current->data);
        current = current->next;
    }
    printf("\n");
}