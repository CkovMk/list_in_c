#include <stdio.h>
#include "list.h"
typedef struct my{
    float a;
    float b;
    int c[2];
}my_t;
int main() {
    printf("Hello, World!\n");
    list_t list0;
    ListList(&list0, sizeof(my_t));
    my_t buf;
    for (int i = 0; i < 4; ++i) {
        buf.a = i*1.2;
        buf.b = i*1.2+1.3;
        buf.c[0] = i;
        buf.c[1] = i+1;
        list_push_back(&list0,&buf);
    }
    printf("take!\n");
    for (list_node_t* j = list_begin(&list0); j !=list0.tail ; ) {
        printf("a = %f\n",((my_t*)j->data)->a);
        printf("b = %f\n",((my_t*)j->data)->b);
        printf("c[0] = %d\n",((my_t*)j->data)->c[0]);
        printf("c[1] = %d\n",((my_t*)j->data)->c[1]);
        j=j->next;
        list_erase(&list0,j->prev);
    }
    printf("end!\n");
    return 0;
}