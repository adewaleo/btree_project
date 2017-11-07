/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   relation.h
 * Author: Oluwatosin V. Adewale
 * A Relation Library(RL)
 * Created on September 29, 2017, 4:39 PM
 */


#ifndef RELATION_H
#define RELATION_H

#include "util.h"

/* Relation type declaration. A Relation is a set of Records. */
typedef struct Relation* Relation_T;
/* Cursor type declaration. A cursor operates on the relation. */
typedef struct Cursor* Cursor_T;


/* Create a new relation. 
 * Returns the relation on success. Returns NULL on failure. */
Relation_T RL_NewRelation(void);

/* Delete the relation */
void RL_DeleteRelation(Relation_T relation);

/* Create a cursor on the specified relation.
 * On creation, the cursor is invalid. i.e. It is not pointing to a record in
 * the table.
 * Hence, certain operations cannot be carried out on it. */
Cursor_T RL_NewCursor(Relation_T relation);

/* Free the cursor. */
void RL_FreeCursor(Cursor_T cursor);

/* Is the cursor valid? Is the cursor pointing to a particular record. */
Bool RL_CursorIsValid(Cursor_T cursor);

/* Get the key of the entry the cursor is currently pointing at. */
unsigned long RL_GetKey(Cursor_T cursor);

/*************************
 * Relation  Operations  *
 *************************/

/* TODO: what kind of failures can occur? */
/* Put a key and its record into the relation. If the key already exists,
 * update record. Leave the cursor at key's position, if successful. Else, 
 * the cursor is invalid. Return TRUE on success; return FALSE on failure. 
 * PutRecord will be faster if Cursor is pointing near record.
 */
Bool RL_PutRecord(Cursor_T cursor, unsigned long key, const void* record);

/* Move the cursor to the position of key in it's relation. 
 * Return True on Success; return False if the record doesn't exist. 
 * Cursor will be Invalid if the Relation is empty.
 * Write to pRes, whether the key of the record at the current location of 
 * cursor is: less than (*pRes < 0), equal to (*pRes == 0), 
 * or greater than (*pRes > 0) the search key.
 * TODO: PutRecord will be faster if Cursor is pointing near record. */
Bool RL_MoveToRecord(Cursor_T cursor, unsigned long key, int* pRes);

/* Get the record from the location cursor is currently at. 
 * cursor must be valid.*/
const void* RL_GetRecord(Cursor_T cursor);

/* Delete key and its record from cursor's relation. */
void RL_DeleteRecord(Cursor_T cursor, unsigned long key);

/* Move the cursor to the first record of it's relation. Return True. 
 * cursor is valid. If the relation is empty, return False. cursor is invalid.*/
Bool RL_MoveToFirstRecord(Cursor_T btCursor);

/* Go to the next record of cursor's relation. If there is a next record, 
 * return True. If no next record, return False. cursor is at last record. */
Bool RL_MoveToNext(Cursor_T btCursor);

#endif /* RELATION_H */
