#ifndef __LIST_H__
#define __LIST_H__



#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>



struct List {
    List* next;
    char name[20];
    double average_mark;
} *head = nullptr, * tail = nullptr;


void insert(char name[], double average_mark);
void insert(std::string& name, double average_mark);
void search_list();
void del(int n);
void print_list();
void serialize();
void deserialize();
#endif // __SEARCH_H__