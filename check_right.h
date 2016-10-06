#include <stdlib.h>
#define TABLE_SIZE 7177
#define MAX_NAME_SIZE 16

typedef struct _ENTRY {
    char lastName[16];
    struct _ENTRY *pNext;
} entry_c;

typedef struct _HTABLE {
    entry_c **list;

} hTable;

int hash_value(char* ptr);
hTable *create();
entry_c *findName(char* lastName,hTable* table);
void append(char* lastName,hTable* table);


