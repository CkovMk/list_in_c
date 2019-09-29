//
// Created by 17616 on 2019/9/26.
//
#include "list_cycle.h"
#include "string.h"

int listc_constructor(list_t *p, unsigned int SizeOfData_) {
    assert(p);
    memset(p, 0, sizeof(list_t));
    p->SizeOfData = SizeOfData_;
    p->size = 0;
    //生成head和tail
    if (!(p->head = LIST_MALLOC(sizeof(list_node_t)))) { return -1; }
    if (!(p->tail = LIST_MALLOC(sizeof(list_node_t)))) {
        LIST_FREE(p->head);
        return -1;
    }
    //往head tail填充空数据以免爆炸
    if (!(p->head->data = LIST_MALLOC(p->SizeOfData))) {
        LIST_FREE(p->head);
        LIST_FREE(p->tail);
        return -1;
    }
    if (!(p->tail->data = LIST_MALLOC(p->SizeOfData))) {
        LIST_FREE(p->head);
        LIST_FREE(p->head->data);
        LIST_FREE(p->tail);
        return -1;
    }
    memset(p->head->data, 0, p->SizeOfData);
    memset(p->tail->data, 0, p->SizeOfData);
    //互联
    p->head->next = p->tail;
    p->head->prev = p->tail;
    p->tail->prev = p->head;
    p->tail->next = p->head;
    return 0;//初始化完毕
}

void listc_destructor(list_t *p) {
    //删除所有元素
    listc_clear(p);
    LIST_FREE(p->head->data);
    LIST_FREE(p->tail->data);
    LIST_FREE(p->tail);
    LIST_FREE(p->head);
    memset(p, 0, sizeof(list_t));
}

void listc_erase(list_t *list__, list_node_t *p) {
    assert(p);
    p->next->prev = p->prev;
    p->prev->next = p->next;
    LIST_FREE(p->data);
    LIST_FREE(p);
    --list__->size;
}

int listc_insert(list_t *p, list_node_t *dst, void *src, list_direction_t direct) {
    assert(dst);
    assert(src);
    list_node_t *newl;
    if (!(newl = LIST_MALLOC(sizeof(list_node_t)))) { return -1; }
    if (!(newl->data = LIST_MALLOC(p->SizeOfData))) {
        LIST_FREE(newl);
        return -1;
    }
    memcpy(newl->data, src, p->SizeOfData);
    if (direct == LIST_NEXT) {
        newl->prev = dst;
        newl->next = dst->next;
    } else if (direct == LIST_PREV) {
        newl->prev = dst->prev;
        newl->next = dst;
    } else if (direct == LIST_HEAD) {
        newl->prev = p->head;
        newl->next = p->head->next;
    } else if (direct == LIST_TAIL) {
        newl->prev = p->tail->prev;
        newl->next = p->tail;
    }
    newl->next->prev = newl;
    newl->prev->next = newl;
    ++p->size;
    return 0;
}

void listc_pop_back(list_t *p) {
    if (p->size > 0) {
        listc_erase(p, p->tail->prev);
    }
}

void listc_pop_front(list_t *p) {
    if (p->size > 0) {
        listc_erase(p, p->head->next);
    }
}

int listc_push_front(list_t *p, void *data) {
    return listc_insert(p, p->head, data, LIST_HEAD);
    //return listc_insert(p,p->head,data,LIST_NEXT);
}

int listc_push_back(list_t *p, void *data) {
    return listc_insert(p, p->tail, data, LIST_TAIL);
    //return listc_insert(p,p->tail,data,LIST_PREV);
}

void listc_clear(list_t *p) {
    while(p->size>0)
    {
        listc_erase(p, p->head->next);
    }

}

unsigned int listc_max_size() { return 0xFFFFU; }

int listc_empty(list_t *p) { if (p->size == 0) { return 1; } else { return 0; }}

unsigned int listc_size(list_t *p) { return p->size; }

void *listc_back(list_t *p) { return p->tail->prev->data; }

list_node_t *listc_end(list_t *p) { return p->tail->prev; }

void *listc_front(list_t *p) { return p->head->next->data; }

list_node_t *listc_begin(list_t *p) { return p->head->next; }





