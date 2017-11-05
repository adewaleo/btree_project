/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   range_query.c
 * Author: Oluwatosin V. Adewale
 *
 * Created on October 24, 2017, 10:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "relation.h"



void unit_tests(void) {
    enum {TEST_SIZE = 25};
    enum {NUM_VALUES = 5000};
    
    Relation_T testRelation = RL_NewRelation();
    Cursor_T testCursor = RL_NewCursor(testRelation);
    unsigned long i;
    unsigned long *test_values;
    unsigned long testIdx[TEST_SIZE];
    int count = 0;
    Bool status;
    /*char temp[100]; */
    /*FILE * outfile = fopen("out.txt", "w");*/
    int res = 0;
   
    /* move and put should behave diff on empty and non empty record, take you 
     close to the desired key assert check here and change code in move and put*/
    assert(RL_MoveToRecord(testCursor, (unsigned long) 0, &res) == False);
    assert(RL_CursorIsValid(testCursor) == False);
    
    test_values = (unsigned long *) malloc (NUM_VALUES * sizeof(unsigned long));
    
    for (i = 0; i < NUM_VALUES; i++) {
        test_values[i] = (unsigned long) i;
    }
    
    while(count < TEST_SIZE) {
        i = rand() % TEST_SIZE;
        
        printf("%d: Putting key %lu with value %lu\n", count, i, test_values[i]);
        assert(RL_PutRecord(testCursor, i, &test_values[i]));
        testIdx[count] = i;
        count++;
    }
    
    for (i = 0; i < TEST_SIZE; i++) {
        RL_MoveToRecord(testCursor, testIdx[i], &res);
        printf("Key: %lu Record: %lu\n", testIdx[i], *((unsigned long *) RL_GetRecord(testCursor)));
    }
    
    status = RL_MoveToFirstRecord(testCursor);
    assert(status);
    
    printf("\nPrinting In order.\n");
    while(status){
        printf("%lu\n", *((unsigned long *) RL_GetRecord(testCursor)));
        status = RL_MoveToNext(testCursor);
    }
    printf("\nFinished In order.\n");
    
    
    printf("\nPut and get from 0 to %d\n", TEST_SIZE -1);
    for (i = 0; i < TEST_SIZE; i++) {
        RL_PutRecord(testCursor, i, &test_values[i]);
    }
    
    for (i = 0; i < TEST_SIZE; i++) {
        RL_MoveToRecord(testCursor, i, &res);
        printf("%lu\n", *((unsigned long *) RL_GetRecord(testCursor)));
    }
    
    printf("\nPrint in order %d\n", TEST_SIZE -1);
    status = RL_MoveToFirstRecord(testCursor);
    assert(status);
    
    while(status){
        printf("%lu\n", *((unsigned long *) RL_GetRecord(testCursor)));
        status = RL_MoveToNext(testCursor);
    }

    fprintf(stderr, "\nTesting That RL_MoveToRecord properly tracks ancestors\n");
    
    for(i = TEST_SIZE; i == 0; i--) {
        unsigned long prev, curr;
        RL_MoveToRecord(testCursor, test_values[i-1], &res);
        prev = *(unsigned long *)RL_GetRecord(testCursor);
        assert(prev == test_values[i-1]);
         
        status = RL_MoveToNext(testCursor);
        while(status) {
            curr = *(unsigned long *)RL_GetRecord(testCursor);
            assert(prev < curr);
            prev = curr;
            status = RL_MoveToNext(testCursor);
        }   
    }
    

    fprintf(stderr, "\nTesting That RL_PutRecord properly tracks ancestors\n");

    for(i = TEST_SIZE; i > 0; i--) {   
        unsigned long prev, curr;
        unsigned long *randNum;
        
        randNum = (unsigned long *) malloc(sizeof(unsigned long));
        *randNum = rand() % (TEST_SIZE * 3);
       
        assert(RL_PutRecord(testCursor, *randNum, randNum));
        prev = *(unsigned long *)RL_GetRecord(testCursor);
        assert(prev == *randNum);
        
        status = RL_MoveToNext(testCursor);
        while(status) {
            curr = *(unsigned long *)RL_GetRecord(testCursor);
            assert(prev < curr);
            prev = curr;
            status = RL_MoveToNext(testCursor);
        }     
    }
    
    fprintf(stderr, "\nDone with Tests\n");

   
    RL_FreeCursor(testCursor);
    /*RL_DeleteRelation(testRelation); unimplemented*/
    
      

    /* In order traversal test */
/*    
    testRelation = RL_NewRelation();
    testCursor = RL_NewCursor(testRelation);
    
    
    while (fgets(temp,100, stdin) != NULL) {
        char* word = malloc(sizeof(char) * (strlen(temp) + 1)));
        int scanfReturn;
        scanfReturn = sscanf(temp,"%s %d",word, &count);
        if (scanfReturn == 2) {
            assert(RL_PutRecord(testCursor, count, (void *)word));
        } else {
            printf("Failed to read word and count from %s\n", temp); 
        }
    }
    
    
    printf("\nPrinting words and word count\n");
    status = RL_MoveToFirstRecord(testCursor);
    assert(status);
    
    while(status){
        fprintf(outfile, "%lu %s\n", RL_GetKey(testCursor), (char *) RL_GetRecord(testCursor));
        status = RL_MoveToNext(testCursor);
    } 
 * 
 */ 
}


/* Conversion functions assume that longs are 8 bytes, write each byte of string
 * into the unsigned long. Significant byte of ul corresponds to significant 
 * bytes in string with least significant bytes 0 if string consists of
 *  less than 8 chars. */

unsigned long str_to_ul(const char* str){
    int i = 0;
    unsigned long res = 0;
    char mask = 255;
    
    while((*str) != '\0' && i < 8) {
        res <<= 8;
        res |= (unsigned long)((*str) & mask);
        str++, i++;
    }
    while (i < 8) {
        res <<= 8;
        i++;
    }
    
    return res;
}

char* ul_to_str(unsigned long str) {
    char* res = (char*) calloc(9, sizeof(char));
    int i;
    unsigned long mask = 255;
    for(i = 7; i >= 0; i--) {
        res[i] = (char)(str & mask);
        str >>= 8;      
    }   
    return res;
}


void range_query_client_test(int argc, char **argv){
    char test1[]= "foo";
    char test2[]= "sherlock";
    char test3[]= "sherloc";
    
    unsigned long ul_test1 = str_to_ul(test1);
    unsigned long ul_test2 = str_to_ul(test2);
    unsigned long ul_test3 = str_to_ul(test3);

    
    printf("%s\n", ul_to_str(ul_test1));
    printf("%s\n", ul_to_str(ul_test2));
    printf("%s\n", ul_to_str(ul_test3));
    printf("\n");
}

int main(int argc, char** argv) {
    char *lower, *upper, *temp, *word;
    int res;
    Relation_T testRelation;
    Cursor_T testCursor;
    Bool status = True;
        
    if (argc != 3) {
        fprintf(stderr, "Usage ./command lower upper");
    }
    
    lower = argv[1], upper = argv[2];
    
    testRelation = RL_NewRelation();
    testCursor = RL_NewCursor(testRelation);
    
    temp = (char*)malloc(sizeof(char)* 100);
    while (fgets(temp,100, stdin) != NULL) {
        if (temp[strlen(temp)-1] == '\n') {
            temp[strlen(temp)-1] = '\0'; 
        }
        word = malloc(sizeof(char) * (strlen(temp) + 1));
        strcpy(word, temp);
        RL_PutRecord(testCursor, str_to_ul(word), word);
    }
    
    RL_MoveToRecord(testCursor, str_to_ul(lower), &res);
    
    if (res < 0) {
        if (!RL_MoveToNext(testCursor)) {
            return 0;
        }
    }

    while (status != False) {
        word = (char *)RL_GetRecord(testCursor);
        if (strcmp(word, upper) > 0) {
            return 0;
        }
        printf("%s\n", word);
        
        status = RL_MoveToNext(testCursor);
    }
      
    return 0;
}
