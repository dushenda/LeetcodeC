#include "include/uthash.h"
#include "string.h"

typedef struct
{
    int key;
    int val;
    UT_hash_handle hh;
} Hash;

typedef struct
{
    int capacity;
} LRUCache;

Hash *hashTbl = NULL;
Hash *hashNode = NULL;
Hash *hashTmp = NULL;

LRUCache *lRUCacheCreate(int capacity)
{
    LRUCache *lruCache = (LRUCache *)malloc(sizeof(LRUCache));
    lruCache->capacity = capacity;
    return lruCache;
}

int lRUCacheGet(LRUCache *obj, int key)
{
    hashNode = NULL;
    hashTmp = NULL;
    for(Hash *s = hashTbl;s!=NULL;s=s->hh.next)
        printf("key=%d,val=%d\n",s->key,s->val);
    HASH_FIND_INT(hashTbl, &key, hashTmp);
    int res = -1;
    if (hashTmp != NULL)
    {
        hashNode = (Hash *)malloc(sizeof(Hash));
        hashNode->key = key;
        hashNode->val = hashTmp->val;
        HASH_DEL(hashTbl, hashTmp);
        HASH_ADD_INT(hashTbl, key, hashNode);
        res = hashTmp->val;
    }
    return res;
}

void lRUCachePut(LRUCache *obj, int key, int value)
{
    hashNode = NULL;
    hashTmp = NULL;
    HASH_FIND_INT(hashTbl, &key, hashTmp);

    hashNode = (Hash *)malloc(sizeof(Hash));
    hashNode->key = key;
    hashNode->val = value;

    if (hashTmp != NULL)
    {
        HASH_DEL(hashTbl, hashTmp);
        HASH_ADD_INT(hashTbl, key, hashNode);
        return;
    }

    int cnt = HASH_COUNT(hashTbl);
    if (cnt > obj->capacity && hashTbl != NULL)
    {
        HASH_DEL(hashTbl, hashTbl);
        HASH_ADD_INT(hashTbl, key, hashNode);
        return;
    }

    HASH_ADD_INT(hashTbl, key, hashNode);
    return;
}

void lRUCacheFree(LRUCache *obj)
{
    Hash *current_user, *tmp;

    HASH_ITER(hh, hashTbl, current_user, tmp)
    {
        HASH_DEL(hashTbl, current_user); /* delete; users advances to next */
        free(current_user);              /* optional- if you want to free  */
    }
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/