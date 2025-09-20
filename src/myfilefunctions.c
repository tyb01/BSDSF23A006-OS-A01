#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../include/myfilefunctions.h"

/* Count lines, words, characters in file. Returns 0 on success, -1 on error. */
int wordCount(FILE* file, int* lines, int* words, int* chars) {

	if (!file) return -1;
    	rewind(file);
    	int c;
    	int l = 0, w = 0, ch = 0;
    	int in_word = 0;
    	while ((c = fgetc(file)) != EOF) {
        	ch++;
        	if (c == '\n') l++;
        	if (isspace((unsigned char)c)) {
            	if (in_word) { w++; in_word = 0; }
        	} else {
            		in_word = 1;
        	}
    	}
	if (in_word) w++;
	if (lines) *lines = l;
	if (words) *words = w;
	if (chars) *chars = ch;
	rewind(file);
	return 0;
}

/* Returns number of matches (>0), sets *matches to allocated array of strings (caller frees).
   Returns 0 if no matches, -1 on failure. */
   
int mygrep(FILE* fp, const char* search_str, char*** matches) {

	if (!fp || !search_str || !matches) return -1;
	rewind(fp);
	size_t cap = 8;
	size_t cnt = 0;
	char **arr = malloc(cap * sizeof(char*));
	if (!arr) return -1;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	while ((read = getline(&line, &len, fp)) != -1) {
	if (strstr(line, search_str) != NULL) {
	    if (cnt >= cap) {
		size_t newcap = cap * 2;
		char **tmp = realloc(arr, newcap * sizeof(char*));
		if (!tmp) { /* cleanup */ 
		    for (size_t i = 0; i < cnt; ++i) free(arr[i]);
		    free(arr); free(line);
		    return -1;
		}
		arr = tmp; cap = newcap;
	    }
	    arr[cnt] = strdup(line);
	    if (!arr[cnt]) {
		for (size_t i = 0; i < cnt; ++i) free(arr[i]);
		free(arr); free(line);
		return -1;
	    }
	    cnt++;
	}
	}
	free(line);
	rewind(fp);
	if (cnt == 0) { free(arr); *matches = NULL; return 0; }
	*matches = arr;
	return (int)cnt;
}
