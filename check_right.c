#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check_right.h"

int hash_value(char* ptr)
{
    unsigned int value = 0;
    unsigned int seed = 31;
    int i = 0;
    while(i < strlen(ptr)) {
        value = value * seed + *ptr;
        i++;
    }
    return value % TABLE_SIZE;
}

hTable *create()
{
    hTable *table;
    table = malloc(sizeof(hTable));
    table -> list = malloc(sizeof(entry_c*) * TABLE_SIZE);
    int i = 0;

    for(i = 0; i < TABLE_SIZE; ++i)
        table -> list[i] = NULL;

    return table;
}

entry_c *findName(char* lastName,hTable* table)
{
    entry_c* list;
    int value = hash_value(lastName);

    for(list = table->list[value]; list != NULL; list = list -> pNext) {
        if(strcmp(list->lastName,lastName) == 0)
            return list;
    }

    return NULL;
}

void append(char* lastName,hTable* table)
{
    entry_c* entry_new;
    int value = hash_value(lastName);

    entry_new = (entry_c*) malloc(sizeof(entry_c));

    strcpy(entry_new -> lastName,lastName);
    entry_new -> pNext = table -> list[value];
    table -> list[value]= entry_new;
}

int main()
{
    FILE* f1 = fopen("test.txt","r");
    FILE* f2 = fopen("dictionary/words.txt","r");

    hTable *table = create();
    char tmp[50];
    char* parse;
    int i = 0;

    while(fgets(tmp,sizeof(tmp),f1)) {
        i = 0;
        while(tmp[i] != '\0') {
            if(tmp[i] == ' ')
                parse = &tmp[i]+1;
            i++;
        }
        tmp[i - 1] = '\0';
        append(parse,table);
    }

    while(fgets(tmp,sizeof(tmp),f2)) {
        i = 0;
        while(tmp[i] != '\0')
            i++;
        tmp[i - 1] = '\0';
        if(!findName(tmp,table))
            printf("Can't find:%s\n",tmp);
    }
    return 0;
}
