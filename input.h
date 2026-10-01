#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "input.h"

/* Reads a non-empty line into buffer, re-asking until something is entered. */
void readLine(const char prompt[], char buffer[], int size) {
    while (1) {
        printf("%s", prompt);

        if (fgets(buffer, size, stdin) == NULL) {
            printf("\nInput closed.\n");
            exit(1);
        }

        if (strchr(buffer, '\n') == NULL) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) > 0) {
            return;
        }
        printf("Error: This field cannot be empty.\n");
    }
}

int readPositiveInt(const char prompt[]) {
    char line[LINE_LEN];
    char *end;
    long value;

    while (1) {
        readLine(prompt, line, LINE_LEN);
        value = strtol(line, &end, 10);

        if (*end == '\0' && value > 0 && value <= INT_MAX) {
            return (int)value;
        }
        printf("Error: Enter a positive whole number.\n");
    }
}

double readNonNegativeDouble(const char prompt[]) {
    char line[LINE_LEN];
    char *end;
    double value;

    while (1) {
        readLine(prompt, line, LINE_LEN);
        value = strtod(line, &end);

        if (*end == '\0' && value >= 0) {
            return value;
        }
        printf("Error: Enter a number that is 0 or more.\n");
    }
}
