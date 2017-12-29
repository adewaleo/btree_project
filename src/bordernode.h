/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   bordernode.h
 * Author: Oluwatosin V. Adewale
 *
 * Created on December 3, 2017, 7:37 PM
 */

#ifndef BORDERNODE_H
#define BORDERNODE_H

#include "relation.h"

/* A BorderNode hold keys and their values and/or points to a Relation 
 * indexing the next slice of keys with similar prefixes. */
typedef struct BorderNode* BorderNode_T;

/* Create a new BorderNode. Returns the new BorderNode if successful, otherwise
 * returns NULL */
BorderNode_T BN_NewBorderNode(long keyslice);

/* Free a BorderNode.*/
void BN_FreeBorderNode(BorderNode_T bordernode);

#endif /* BORDERNODE_H */
