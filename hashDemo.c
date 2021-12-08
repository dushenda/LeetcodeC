#include "include/uthash.h"
#include "string.h"
#include "stdio.h"

typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} Hash;

void printHash(Hash *hash)
{
    for (Hash *s = hash; s != NULL; s = s->hh.next)
    {
        printf("key=%d,val=%d\n", s->key, s->val);
    }
}

int main()
{
    Hash *hashTbl = NULL;
    Hash *hashNode = NULL;
    for (int i = 0; i < 10; i++)
    {
        hashNode = (Hash *)malloc(sizeof(Hash));
        hashNode->key = i;
        hashNode->val = i + 1;
        HASH_ADD_INT(hashTbl, key, hashNode);
    }
    printHash(hashTbl);
    printf("hash_cnt = %d\n", HASH_COUNT(hashTbl));
    HASH_DEL(hashTbl,hashTbl);
    hashNode = (Hash*)malloc(sizeof(Hash));
    hashNode->key = 111;
    hashNode->val = 222;
    HASH_ADD_INT(hashTbl, key, hashNode);
    printf("=====\n");
    printHash(hashTbl);
    return 0;
}