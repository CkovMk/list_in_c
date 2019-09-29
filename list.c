//
// Created by 17616 on 2019/9/29.
//

#include "list.h"
#ifdef __cplusplus
extern "C" {
#endif

void List_Constructor(list_t *p, unsigned int SizeOfData) {
    assert(p);
    assert(SizeOfData);
    memset(p, 0, sizeof(list_t));
    p->SizeOfData = SizeOfData;
    p->size = 0;
    //生成head和tail
    p->head = LIST_MALLOC(sizeof(list_node_t));
    assert(p->head);
    p->tail = p->head;
    //互联
    p->head->next = NULL;
    p->head->prev = NULL;

    //return 0;//初始化完毕
}

void List_Destructor(list_t *p) {
    //删除所有元素
    List_Clear(p);
    LIST_FREE(p->head->data);
    LIST_FREE(p->tail->data);
    LIST_FREE(p->tail);
    LIST_FREE(p->head);
    memset(p, 0, sizeof(list_t));
}

uint32_t List_MaxSize() { return 0xFFFFU; }

uint8_t List_IsEmpty(list_t *p) { if (p->size == 0) { return 1; } else { return 0; }}

uint32_t List_GetSize(list_t *p) { return p->size; }

list_node_t* List_Create(list_t* p, list_node_t* pos)
{
    assert(pos);
    //assert(src);
    list_node_t* newl;
    newl = LIST_MALLOC(sizeof(list_node_t));
    assert(newl);
    newl->data = LIST_MALLOC(p->SizeOfData);
    assert(newl->data);
    newl->prev = pos->prev;
    newl->next = pos;
    if (newl->prev != NULL)
    {
        newl->prev->next = newl;
    }
    else
    {
        p->head = newl;
    }
    pos->prev = newl;
    ++p->size;
    return newl;
}

list_node_t* List_Insert(list_t *p, list_node_t *pos, void *src) {
    assert(src);
    list_node_t *newl = List_Create(p, pos);
    memcpy(newl->data, src, p->SizeOfData);
    return newl;
}

void List_Erase(list_t *p, list_node_t *pos) {
    assert(p);
    assert(pos);
    assert(pos->next != NULL);
    pos->next->prev = pos->prev;
    if(pos->prev != NULL)
    {
        pos->prev->next = pos->next;
    }
    else
    {
        p->head = pos->next;
    }
    LIST_FREE(pos->data);
    LIST_FREE(pos);
    --p->size;
}

void List_PopFront(list_t *p) {
    if (p->size > 0) {
        List_Erase(p, p->head);
    }
}

void List_PopBack(list_t *p) {
    if (p->size > 0) {
        List_Erase(p, p->tail->prev);
    }
}

list_node_t* List_PushFront(list_t *p, void *data) {
    return List_Insert(p, p->head, data);
}

list_node_t* List_PushBack(list_t *p, void *data) {
    return List_Insert(p, p->tail, data);
}

void List_Clear(list_t *p) {
    while(p->size>0)
    {
        List_Erase(p,p->head->next);
    }
}

void* List_GetFront(list_t *p) { return p->head->data; }

void* List_GetBack(list_t *p) { return p->tail->prev->data; }

list_node_t* List_ItBegin(list_t *p) { return p->head; }

list_node_t* List_ItEnd(list_t *p) { return p->tail; }

#ifdef __cplusplus
}
#endif
