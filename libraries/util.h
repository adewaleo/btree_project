/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utilities.h
 * Author: Oluwatosin V. Adewale
 *
 * Created on September 29, 2017, 4:43 PM
 */

#ifndef UTIL_H
#define UTIL_H

/* Boolean enum type*/
typedef enum { False = 0 , True = 1} Bool;

/* Order of Btree nodes */
/* enum {ORDER = 2}; */

/* Fanout of Btree nodes */
enum {FANOUT = 15};

/* Max Tree depth: maximum number of levels. 
 * Levels go from 0 to MAX_TREE_DEPTH - 1 */
enum {MAX_TREE_DEPTH = 8};

/* Binary search on array a to find tgt between lo (inclusive) & hi (exclusive).
 * Code from: 
 * https://github.com/PrincetonUniversity/VST/blob/master/progs/bin_search.c */
int UTIL_BinarySearch(int a[], int tgt, int lo, int hi);


#endif /* UTIL_H */
