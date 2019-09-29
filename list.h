//
// Created by 17616 on 2019/9/29.
//
#ifndef LIST_LIST_H
#define LIST_LIST_H
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#ifdef __cplusplus
extern "C" {
#endif
// Library version
#define LIST_VERSION "0.1.5"

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
} list_t;

/**
 * @brief   链表的构造函数。
 *
 * @param  {list_t*} p    : list对象句柄。
 * @param  {unsigned} int : 每个node存储的数据多大。
 */
void List_Constructor(list_t *p, unsigned int SizeOfData_);

/**
 * @brief   链表的析构函数。
 *
 * @param  {list_t*} p    : list对象句柄。
 */
void List_Destructor(list_t *p);

/**
 * @brief   返回链表能容纳的最大节点数量。
 */
uint32_t List_MaxSize(void);

/**
 * @brief   检查链表是否为空。
 *
 * @param  {list_t*} p    : list对象句柄。
 * @return {int}          : 空链表返回1，非空链表返回0。
 */
uint8_t List_IsEmpty(list_t *p);

/**
 * @brief  获得 链表内有效节点的个数。
 *
 * @param  {list_t*} p    : list对象句柄。
 * @return {int}          : 链表内节点的个数。空链表返回0。
 */
uint32_t List_GetSize(list_t *p);

/**
 * @brief                     : 向链表内新建节点。
 *
 * @param  {list_t*} p        : list对象句柄。
 * @param  {list_node_t*} pos : 要插入节点的位置。新节点总是插入到此位置之前。
 * @return {list_node_t*}     : 返回指向创建的节点的指针。
 */
list_node_t* List_Create(list_t* p, list_node_t* pos);

/**
 * @brief                     : 向链表内插入节点。
 *
 * @param  {list_t*} p        : list对象句柄。
 * @param  {list_node_t*} pos : 要插入节点的位置。新节点总是插入到此位置之前。
 * @param  {void*} data       : 要插入节点内的数据。数据大小应与构造链表时一致。
 * @return {list_node_t*}     : 返回指向插入的节点的指针。
 */
list_node_t* List_Insert(list_t *p, list_node_t *pos, void *data);

/**
 * @brief   删除链表的一个节点
 *
 * @param  {list_t*} p        : list对象句柄
 * @param  {list_node_t*} pos : 要删除的节点
 * @return {int}              : 错误代码
 */
void List_Erase(list_t *p, list_node_t *pos);

/**
 * @brief   删除链表内第一个元素
 *
 * @param  {list_t*} p    : list对象句柄
 */
void List_PopFront(list_t *p);

/**
 * @brief   删除链表内最后一个元素
 *
 * @param  {list_t*} p    : list对象句柄
 */
void List_PopBack(list_t *p);

/**
 * @brief   向链表头部插入节点。
 *
 * @param  {list_t*} p    : list对象句柄
 * @param  {void*} data   : 要插入节点内的数据。数据大小应与构造链表时一致。
 * @return {int}          : 错误代码
 */
list_node_t* List_PushFront(list_t *p, void *data);

/**
 * @brief   向链表尾部插入节点。
 *
 * @param  {list_t*} p    : list对象句柄
 * @param  {void*} data   : 要插入节点内的数据。数据大小应与构造链表时一致。
 * @return {int}          : 错误代码
 */
list_node_t* List_PushBack(list_t *p, void *data);

/**
 * @brief   清空链表。
 *
 * @param  {list_t*} p    : list对象句柄
 */
void List_Clear(list_t *p);
/**
 * @brief   返回指向链表内第一个节点所存储元素的指针。
 *
 * 用户需要自行检查链表是否为空。
 *
 * @param  {list_t*} p    : list对象句柄
 */
void *List_GetFront(list_t *p);

/**
 * @brief   返回指向链表内最后一个有效节点所存储元素的指针。
 *
 * @param  {list_t*} p    : list对象句柄。
 */
void *List_GetBack(list_t *p);

/**
 * @brief   返回指向链表第一个节点的指针。
 *
 * @param  {list_t*} p    : list对象句柄。
 */
list_node_t* List_ItBegin(list_t *p);

/**
 * @brief   返回指向链表最后一个有效节点之后的节点的指针。
 *
 * @param  {list_t*} p    : list对象句柄。
 */
list_node_t* List_ItEnd(list_t *p);

#ifdef __cplusplus
}
#endif
#endif //LIST_LIST_H
