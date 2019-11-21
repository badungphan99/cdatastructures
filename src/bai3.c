#include "libcdatastructures/dssinglylinkedlist.h"
#include <stdio.h> 
#include <stdlib.h>

//cau a
SListEntry *init_list()
{
    int bac;
    printf("Nhap bac cua da thuc : ");
    scanf("%d", &bac);
    SListEntry *list = NULL;
    
    for (int i = 0; i <= bac; i++)
    {
        float a;
        printf("Nhap a%d ", i);
        scanf("%f", &a);
        SListValue val = malloc(sizeof(float));
        *(float *)val = a;
        list = slist_prepend(&list, val);
        
    }
    
    return list;
}

void print_list(SListEntry *list)
{
    SListEntry *entry = list;
    unsigned int length = slist_length(list);
    while ( entry != NULL)
    {
        printf("%.3f", *(float*)slist_data(entry));
        if (length > 1)
        {
            printf("x^%d + ", --length);
        } else printf("\n");
        entry = slist_next(entry);
    }
    
}


int main(int argc, char const *argv[])
{
    SListEntry *list = init_list();
    // printf("%f\n", *(float*)slist_data(list));
    print_list(list);
    return 0;
}
