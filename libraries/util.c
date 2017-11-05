/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   utilities.c
 * Author: Oluwatosin V. Adewale
 * 
 * Created on September 29, 2017, 4:43 PM
 */


#include "util.h"

int UTIL_BinarySearch(int a[], int tgt, int lo, int hi){
  int mid, val;
  while(lo < hi){
    mid = (lo + hi) >> 1; /* (hi - lo) >> 1 + lo ? */
    val = a[mid];
    if (val == tgt) return mid;
    else if (val < tgt) lo = mid + 1;
    else hi = mid;
  }
  return -1;
}

