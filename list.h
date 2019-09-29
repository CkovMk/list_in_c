//
// Created by 17616 on 2019/9/29.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H


// Memory management macros
#ifndef LIST_MALLOC
#define LIST_MALLOC malloc
#endif
#ifndef LIST_FREE
#define LIST_FREE free
#endif
typedef enum {
    LIST_HEAD,
    LIST_TAIL,
    LIST_PREV,
    LIST_NEXT
} list_direction_t;

/*
* list_t node struct.
*/
typedef struct list_node {
    void *data;
    struct list_node *prev;
    struct list_node *next;
} list_node_t;

/*
 * list_t struct.
 */
typedef struct list_struct {
    list_node_t *head;
    list_node_t *tail;
    unsigned int SizeOfData;
    unsigned int size;
} list_t, *list_hander_t;

#endif //LIST_LIST_H
