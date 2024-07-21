#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define PRIME 31

typedef struct Node {
    char key[100];
    char value[100];
    struct Node* next;
}
Node;

typedef struct HashTable {
    Node* table[TABLE_SIZE];
}
HashTable;

// Function prototypes
unsigned int hashFunction(const char* key);
void insert(HashTable* ht, const char* key, const char* value);
char* search(HashTable* ht, const char* key);
void delete(HashTable* ht, const char* key);
void rehash(HashTable* ht);

int main() {
    HashTable ht = { {NULL} };
    insert(&ht, "Manish", "BITS");
    insert(&ht, "Anjali", "Delhi");
    insert(&ht, "Vartika", "Mumbai");
    insert(&ht, "Mayank", "Pune");
    printf("%s\n", search(&ht, "Manish")); // Expected: BITS
    printf("%s\n", search(&ht, "Anjali")); // Expected: Delhi
    printf("%s\n", search(&ht, "Vartika")); // Expected: Mumbai
    printf("%s\n", search(&ht, "Mayank")); // Expected: Pune
    printf("%s\n", search(&ht, "BITS")); // Expected: Oops! No data found.
    printf("After deletion :\n");
    delete(&ht, "Manish");
    printf("%s\n", search(&ht, "Manish")); // Expected: Oops! No data found.
    return 0;
}

// Hash function
unsigned int hashFunction(const char* key) {
    unsigned int hash = 0;
    unsigned int power = 1;
    while (*key) {
        hash = (hash + (*key * power)) % TABLE_SIZE;
        power = (power * PRIME) % TABLE_SIZE;
        key++;
    }
    return hash;
}

// Insert function
void insert(HashTable* ht, const char* key, const char* value) {
    unsigned int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

// Search function
char* search(HashTable* ht, const char* key) {
    unsigned int index = hashFunction(key);
    Node* curr = ht->table[index];
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            return curr->value;
        }
        curr = curr->next;
    }
    return "Oops! No data found.";
}

// Delete function
void delete(HashTable* ht, const char* key) {
    unsigned int index = hashFunction(key);
    Node* curr = ht->table[index];
    Node* prev = NULL;
    while (curr) {
        if (strcmp(curr->key, key) == 0) {
            if (prev) {
                prev->next = curr->next;
            }
            else {
                ht->table[index] = curr->next;
            }
            free(curr);
            return;
        }
        prev = curr;
        curr = curr->next;
    }
}

// Rehash function
void rehash(HashTable* ht) {
    Node* oldTable[TABLE_SIZE];
    memcpy(oldTable, ht->table, sizeof(ht->table));
    memset(ht->table, 0, sizeof(ht->table));
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* curr = oldTable[i];
        while (curr) {
            insert(ht, curr->key, curr->value);
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}
