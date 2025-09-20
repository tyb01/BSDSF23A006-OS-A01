#include <stddef.h>
#include "../include/mystrfunctions.h"

/* Return length of the string*/

int mystrlen( const char* s) {
	if (!s) return 0;
	const char* p = s;
	int len = 0;
	while (*p != '\0') { len++; p++; }
	return len;
}

/* Copy the string and return number of characters copied, otherwise -1 */

int mystrcpy (char* dest, const char* src) {
	if (!dest || !src) return -1;
    	char *d = dest;
    	const char *s = src;
    	int cnt = 0;
    	while ((*d++ = *s++) != '\0') cnt++;
    	return cnt;
}

/* Copy at most n characters, pad with '\\0' if src shorter.
   Returns number of characters copied from src, 0 on error. */
   
int mystrncpy(char* dest, const char* src, int n) {

	if (!dest || !src || n <= 0) return 0;
    	int i;
    	for (i = 0; i < n && src[i] != '\0'; ++i) dest[i] = src[i];
    	for (; i < n; ++i) dest[i] = '\0';

    	int src_len = 0;
    	while (src[src_len] != '\0') src_len++;
    	return (src_len < n) ? src_len : n;
}

/* Append src to dest; dest must have enough space.
   Returns new length of dest, -1 on error. */
   
int mystrcat(char* dest, const char* src) {

	if (!dest || !src) return -1;
    	int dest_len = mystrlen(dest);
    	int i = 0;
    	while (src[i] != '\0') {
        	dest[dest_len + i] = src[i];
        	i++;
    	}
    	dest[dest_len + i] = '\0';
    	return dest_len + i;
}
