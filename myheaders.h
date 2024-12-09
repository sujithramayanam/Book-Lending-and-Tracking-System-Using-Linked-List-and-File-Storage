#ifndef MYHEADERS_H
#define MYHEADERS_H
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include <stdio_ext.h>

typedef struct Book
{
    /* data */
    char name[100];
    char author[100];
    int pages;
    int count;
    struct Book *next;
}Book;
struct Book *syncfile();
#endif