#include"listUtils.h"

Node* buildNode(FILE* fin, void*(*buildData)(FILE* in) ){
    Node* node = calloc(1,sizeof(Node));
    
    void* temp = buildData(fin);
    node->data = temp;
    
    node->next = NULL;
    node->prev = NULL;
    
    return node;
}

Node* buildNode_Type(void* passedIn){
    Node* node = calloc(1,sizeof(Node));
    
    node->data = passedIn;
    
    node->next = NULL;
    node->prev = NULL;
    
    return node;
}

void sort(LinkedList* list, int (*compare)(const void*, const void*)){
    Node* current = list->head->next;
    Node* step;
    Node* min;
    
    while(current->next){
        min = current;
        
        if(current->next != NULL)step = current->next;
        
        while(step){
            if(compare(min->data,step->data) > 0){
                min = step;
            }
            step = step->next;
        }
        
        void* temp = current->data;
        current->data = min->data;
        min->data = temp;
        
        current = current->next;
    }
}

void buildListTotal(LinkedList* list, int total, FILE* fin, void* (*buildData)(FILE* in)){
    int i;
    for(i=0;i<total;i++){
        Node* node = buildNode(fin,buildData);
        addLast(list,node);
    }
}