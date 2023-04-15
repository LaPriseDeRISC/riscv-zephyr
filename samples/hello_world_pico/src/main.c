// /*
//  * Copyright (c) 2012-2014 Wind River Systems, Inc.
//  *
//  * SPDX-License-Identifier: Apache-2.0
//  */

// #include <zephyr/kernel.h>
// #define A_SIZE 100
// void main(void)
// {
// 	printk("Hello World! %s\n", CONFIG_BOARD);
//     int *a = malloc(A_SIZE*sizeof(int));
//     printk("a = %p\n", a);
//     for(int i = 0; i < A_SIZE; i++) {
//         a[i] = i;
//     }

//     for (int i=0; i< A_SIZE/10 ; i++) {
//         for (int j = 0 ; j < 10 ; j++) {
//             printk("%d ", a[i*10+j]);
//         }
//         printk("\n");
// }

/* 
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 * 
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>
#define TAB_SIZE 16

void print_tab(int *tab, int size)
{
    printk("{");
    for (int i = 0; i < size - 1; i++)
    {
        printk("%d, ", tab[i]);
    }
    printk("%d}\n", tab[size - 1]);
}

void print_mem(int *tab, int size)
{
    for (int i = 0; i < size; i += TAB_SIZE)
    {
        // printk("@%x i%d: ", (int)tab, i);
        printk("@%x:\t", (int)tab + i);
        for (int j = 0; j < TAB_SIZE; j++)
        {
            if (tab[i + j] < 10 && tab[i + j] >= 0)
                printk(" ");
            printk("%d ", tab[i + j]);
        }
        printk("\n");
    }
}

void main(void)
{
    printk("Hello World! %s\nSize of int is %d\n", CONFIG_BOARD, sizeof(int));
    int big_array[TAB_SIZE * 4];
    for (int i = 0; i < TAB_SIZE * 4; i++)
        big_array[i] = -1;

    int *overflow = malloc(TAB_SIZE * sizeof(int));
    int *tab = malloc(TAB_SIZE * sizeof(int));
    
    void* malloc_test[15];
    for (int i = 0; i < 15; i++)
        malloc_test[i] = malloc(1000);
    
    // int tab[16]; # stack

    printk("&overflow = %x\n", (int)overflow);
    printk("&tab = %x\ttab[] = ", (int)tab);

    print_tab(tab, TAB_SIZE);

    for (int i = 0; i < TAB_SIZE; i++)
    {
        tab[i] = i + 1;
    }
    printk("tab initialized to : tab[] = ");
    print_tab(tab, TAB_SIZE);

    for (int i = 0; i < TAB_SIZE; i++)
    {
        overflow[i] = i + TAB_SIZE + 1;
    }
    printk("tab is : \ttab[] = ");
    print_tab(tab, TAB_SIZE);
    printk("all memory :\n");
    print_mem(overflow, TAB_SIZE * 8);
    printk("\n");

    printk("overflow initialized to : overflow[] = ");
    print_tab(overflow, TAB_SIZE);

    // memcpy(overflow, big_array, TAB_SIZE * 4 * sizeof(int));
    printk("tab after overflow : tab[] = ");
    print_tab(tab, TAB_SIZE);

    printk("all memory :\n");
    print_mem(overflow, TAB_SIZE * 8);
    printk("\n");

    free(0);
    printk("Done.\n");
}
