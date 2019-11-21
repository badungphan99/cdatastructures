//
// Created by dungpb on 11/21/19.
//

#include "dsarraylist.h"
#include "dscompareint.h"
#include <stdio.h>

int count = 0;

void printResult(ArrayList arrayList);

int main(){

    /// init new array list
    ArrayList *arrayList = arraylist_new(10);

    arraylist_clear(arrayList);

    /// insert some value in array list
    for(int i = 0; i < 6; i ++){
        arraylist_append(arrayList, i);
    }

    printResult(*arrayList);

    /// append value in array list
    arraylist_append(arrayList, 0);

    printResult(*arrayList);

    /// prepend value in array list
    arraylist_prepend(arrayList, 18);

    printResult(*arrayList);

    /// insert value in array list
    arraylist_insert(arrayList, 5, 100);

    printResult(*arrayList);

    /// remove value in array list
    arraylist_remove(arrayList, 5);

    printResult(*arrayList);

    /// find index of value 10, 5

//    printf("%d",arraylist_indexOf(arrayList,, 10));
//    printf("%d",arraylist_indexOf(arrayList,, 5));

    /// sort array list
    arraylist_sort(arrayList, intCompare);

    printResult(*arrayList);



    return 0;
}

void printResult(ArrayList arrayList){
    printf("print result %d th\n", count++);
    for(int i = 0; i < arrayList.length; i ++){
        printf("%d ",arrayList.data[i]);
    }
    printf("\n");
}