/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bordernode.c
 * Author: Oluwatosin V. Adewale
 * 
 * Created on December 3, 2017, 7:37 PM
 */

#include "bordernode.h"
#include <stdlib.h>

/* Maximum number of keys in a BorderNode */
enum {MAX_BN_SIZE = 10};
/* Key length to denote that a key has a suffix */
enum {KEYSUFFIX_KEYLENGTH = 64};
/* Key length to denote that a key is just an intermediary layer and points
 * to a next layer. */
enum {LAYER_KEYLENGTH = 128};


union LinkOrValue {
    Relation_T nextRelation; 
    void *value;
};


/* BorderNodes can hold different keys belonging to a key slice. For each key, 
 * there is a value. At most one key has a suffix or a link to the next layer.*/
struct BorderNode {
    /* The keyslice all the keys in this node are composed from */
    unsigned long keySlice;
    /* The length of each key from the keySlice. Used to check if key has suffix
     * or if there is a next layer. */
    unsigned int keyLength[MAX_BN_SIZE];
    /* Number of keys in the BorderNode*/
    unsigned int numKeys;
    /* Link to next layer or value of key. */
    LinkOrValue lv[MAX_BN_SIZE];
    /* keySuffix if a key has a keysuffix*/
    char* keySuffix;
};


BorderNode_T  BN_NewBorderNode(long keyslice) {

    BorderNode_T bordernode = 
            (struct BorderNode*) malloc(sizeof(struct BorderNode));

    if (bordernode == NULL)
        return bordernode;
    
    bordernode->keySlice = keyslice;
    bordernode->numKeys = 0;
    bordernode->keySuffix = NULL;
    
    return bordernode;
}

void BN_FreeBorderNode(BorderNode_T bordernode) {
    if (bordernode == NULL)
        return;
    
    if (bordernode->keySuffix)
        free(bordernode->keySuffix);
    
    free(bordernode);
    
    return;
}



