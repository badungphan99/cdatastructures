#include "dssinglylinkedlist.h"
#include <stdio.h> 
#include <stdlib.h>


// in list ra man hinh
void print_list(SListEntry *list);

// cau a
SListEntry *init_list();

// cau b
/**
 * @param listA singly linked list to calculate
 * @param listB singly linked list to calculate
 * @param mode  0 is minus and 1 is plus
 * @return      value of calculate
 */
SListEntry *plus_minus_list(SListEntry *listA, SListEntry *listB, int mode);

// cau c
float calculate_list(SListEntry *list, SListEntry *listVal);


int main(int argc, char const *argv[])
{
    // test nhap list
    SListEntry *list = init_list();
    printf("List : \n");
    print_list(list);


    // test cong 2 list
    SListEntry *list2 = init_list();
    printf("List 2 : \n");
    print_list(list);

    printf("List plus : \n");
    SListEntry *listResultPlus = plus_minus_list(list, list2, 1);
    
    print_list(listResultPlus);

    // test tru 2 list
    SListEntry *listResultMinus = plus_minus_list(list, list2, 0);
    printf("List minus : \n");
    print_list(listResultMinus);

    // test tinh gia tri list
    SListEntry *listVal = NULL;
    printf("Nhap gia tri bien\n");
    for (int i = 0; i < slist_length(list); i++)
    {
        float x;
        printf("Nhap x%d ", i);
        scanf("%f", &x);
        SListValue val = malloc(sizeof(float));
        *(float *)val = x;
        listVal = slist_prepend(&listVal, val);
    }

    float result = calculate_list(list, listVal);
    printf("Ket qua : %0.3f", result);
    return 0;
}

void print_list(SListEntry *list)
{
    SListEntry *entry = list;
    unsigned int length = slist_length(list);
    while ( entry != NULL)
    {
        float val = *(float*)slist_data(entry);
        
        printf("%.3f", val);
        if (length > 1)
        {
            printf("x^%d + ", --length);
        } else printf("\n");
        
        entry = slist_next(entry);
    }
    
}

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

SListEntry *plus_minus_list(SListEntry *listA,
                            SListEntry *listB,
                            int mode)
{
    int dau = 1;
    if (mode == 0) dau = -1;

    SListEntry *listResult = NULL;

    SListEntry *entryA = listA;
    SListEntry *entryB = listB;
    
    while(slist_length(entryA) != slist_length(entryB))
    {
        SListValue val = malloc(sizeof(float));
        *(float *)val = 0.0;
        if (slist_length(entryA) < slist_length(entryB))
        {
            entryA = slist_prepend(&entryA, val);
        }
        if (slist_length(entryA) > slist_length(entryB))
        {
            entryB = slist_prepend(&entryB, val);
        }
    }
    
    while (entryA != NULL && entryB != NULL)
    {
        SListValue val = malloc(sizeof(float));
        *(float *)val = (*(float *)slist_data(entryA)) + dau*(*(float *)slist_data(entryB));
        listResult = slist_prepend(&listResult, val);
        entryA = slist_next(entryA);
        entryB = slist_next(entryB);
    }
    
    return listResult;
}

float calculate_list(SListEntry *list, SListEntry *listVal)
{
    if (slist_length(list) != slist_length(listVal))
    {
        printf("Du lieu nhap sai!\n");
        return -1.0;
    }

    float result = 0.0;

    SListEntry *entry = list;
    SListEntry *entryVal = listVal;
    unsigned int length = slist_length(list);

    while (entry != NULL && entryVal != NULL)
    {
        float tmp = 1;
        float val = *(float *)slist_data(entryVal);
        for (int i = 1; i < length; i++)
            tmp = tmp*val;
        result = result + ( *(float *)(slist_data(entry)) ) * tmp;
        entry = slist_next(entry);
        entryVal = slist_next(entryVal);
    }
    
    return result;
}