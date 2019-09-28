//
// Created by 17616 on 2019/9/26.
//
#ifndef LIST_LIST_H
#define LIST_LIST_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
// Library version
#define LIST_VERSION "0.0.5"

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

int ListList(list_t *p, unsigned int SizeOfData_);//构造函数
void List_List(list_t *p);//析构函数
int list_empty(list_t *p);//如果list是空的则返回1
unsigned int list_size(list_t *p);//返回list中的元素个数
unsigned int list_max_size();//返回list能容纳的最大元素数量
list_node_t *list_back(list_t *p);//返回最后一个元素
list_node_t *list_end(list_t *p);//返回从末尾的迭代器
list_node_t *list_front(list_t *p);//返回第一个元素
list_node_t *list_begin(list_t *p);//返回指向第一个元素的迭代器
int list_insert(list_t *p, list_node_t *dst, void *src, list_direction_t direct);//插入元素，注意方向
void list_pop_back(list_t *p);//删除最后一个元素
void list_pop_front(list_t *p);//删除第一个元素
int list_push_back(list_t *p, void *data);//在list的末尾添加一个元素
int list_push_front(list_t *p, void *data);//在list的头部添加一个元素
void list_erase(list_t *list__, list_node_t *p);//删除一个元素
void list_clear(list_t *p);//删除所有元素
#ifdef __cplusplus
}
#endif
#endif //LIST_LIST_H
