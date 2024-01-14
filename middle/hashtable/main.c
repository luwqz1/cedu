#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define uint unsigned int
#define uchar unsigned char

#define TABLE_SIZE 10000


typedef enum Bool {
    false,
    true,
} bool;


typedef struct {
    char *key;
    void *value;
    struct HashTable *next; 
} HashTable;


static HashTable *hashTable[TABLE_SIZE];


void init_hashtable() {
    memset(hashTable, 0, sizeof(void *) * TABLE_SIZE);
}


void entry_free(HashTable *entry) {
    if (entry == NULL) return;
    entry_free(entry->next);
    free(entry->key);
    free(entry->value);
}


void hashtable_free() {
    for (size_t i = 0; i < TABLE_SIZE; i++)
        if (hashTable[i]) {
            entry_free(hashTable[i]);
            hashTable[i] = NULL;
        }
}


char *strdup(char *s) {
    char *ptr = (char *)malloc(strlen(s) + 1);
    memcpy(ptr, s, strlen(s));
    ptr[strlen(s)] = NULL;
    return ptr;
}


uint hash(char *key) {
    uchar hash_id = 0;
    while (*key)
        hash_id = (hash_id << 5) + *(key++);
    
    return hash_id % TABLE_SIZE;
}


void insert(char *key, void *value) {
    uint index = hash(key);
    HashTable *entry = (HashTable *)malloc(sizeof(HashTable *));
    entry->key = strdup(key);
    entry->value = value;
    entry->next = hashTable[index];
    hashTable[index] = entry;
}


bool find(char *key, void **value) {
    uint index = hash(key);
    HashTable *entry = hashTable[index];

    while (entry) {
        if (strcmp(entry->key, key) == 0) {
            *value = entry->value;
            return true;
        }
    }

    return false;
}


void delete(char *key) {
    uint index = hash(key);
    HashTable *entry = hashTable[index];
    HashTable *prev = NULL;

    while (entry) {
        if (strcmp(entry->key, key)) {
            if (prev == NULL) hashTable[index] = entry->next;
            else prev->next = entry->next;
            free(entry);
            return;
        }
        prev = entry;
        entry = entry->next;
    }
}


int main() {
    init_hashtable();
    
    char *name;
    insert("name", strdup("Arseny"));

    if (find("name", &name))
        printf("Name: %s\n", name);
    else 
        printf("Not found!\n");

    hashtable_free();
    return 0;
}
