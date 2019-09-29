//
// Created by 17616 on 2019/9/26.
//
#include "list.h"
#ifndef LIST_LIST_CYCLE_H
#define LIST_LIST_CYCLE_H
#ifdef __cplusplus
extern "C" {
#endif
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
// Library version
#define LIST_VERSION "0.0.5"

int listc_constructor(list_t *p, unsigned int SizeOfData_);//构造函数
void listc_destructor(list_t *p);//析构函数
int listc_empty(list_t *p);//如果list是空的则返回1
unsigned int listc_size(list_t *p);//返回list中的元素个数
unsigned int listc_max_size();//返回list能容纳的最大元素数量
void *listc_back(list_t *p);//返回最后一个元素
list_node_t *listc_end(list_t *p);//返回从末尾的迭代器
void *listc_front(list_t *p);//返回第一个元素
list_node_t *listc_begin(list_t *p);//返回指向第一个元素的迭代器
int listc_insert(list_t *p, list_node_t *dst, void *src, list_direction_t direct);//插入元素，注意方向
void listc_pop_back(list_t *p);//删除最后一个元素
void listc_pop_front(list_t *p);//删除第一个元素
int listc_push_back(list_t *p, void *data);//在list的末尾添加一个元素
int listc_push_front(list_t *p, void *data);//在list的头部添加一个元素
void listc_erase(list_t *list__, list_node_t *p);//删除一个元素
void listc_clear(list_t *p);//删除所有元素
#ifdef __cplusplus
}
#endif
#endif //LIST_LIST_CYCLE_H
