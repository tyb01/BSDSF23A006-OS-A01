#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main(int argc, char** argv) {
    printf("--- Testing String Functions ---\n");
    char a[256] = "Hello";
    char b[256] = " World!";
    printf("a = '%s'\n", a);
    printf("mystrlen(a) = %d\n", mystrlen(a));
    mystrcat(a, b);
    printf("after mystrcat: a = '%s'\n", a);

    char copied[256];
    int c = mystrcpy(copied, "Sample text");
    printf("copied = '%s' (mystrcpy returned %d)\n", copied, c);

    char partial[10];
    int n = mystrncpy(partial, "ABCDEFGHIJK", 5);
    partial[5] = '\\0';
    printf("partial (first 5) = '%s' (returned %d)\n", partial, n);

    printf("\n--- Testing File Functions ---\n");
    const char *fname = (argc > 1) ? argv[1] : "test.txt";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        perror("fopen");
        printf("Please create a file '%s' or pass filename as argument.\n", fname);
        return 1;
    }

    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("wordCount => lines=%d words=%d chars=%d\n", lines, words, chars);
    } else {
        printf("wordCount failed\n");
    }

    char **matches = NULL;
    int found = mygrep(fp, "TODO", &matches);
    printf("mygrep searching for 'TODO' => matches=%d\n", found);
    if (found > 0) {
        for (int i = 0; i < found; ++i) {
            printf("match[%d]: %s", i, matches[i]);
            free(matches[i]);
        }
        free(matches);
    }
    fclose(fp);
    return 0;
}
