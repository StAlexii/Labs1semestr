#ifndef _LIST_H
#define _LIST_H

typedef struct {
    char material[20];
    int length;
    int ceilingWidth;
    int wallHeight;
} cornice_t;

struct listitem {
    cornice_t data;   
    struct listitem* next; 
};

typedef struct listitem* List;

void initlist(List* list);          
void insertfront(List* list, cornice_t item);
void insertback(List* list, cornice_t item); 
int isempty(List list);               
void destroyItem(List* list, List node);  
List findItem(List list, cornice_t item);  
int length(List list);    

#endif /* _LIST_H */
