#ifndef INPUT_H
#define INPUT_H

#define LINE_LEN 100

void readLine(const char prompt[], char buffer[], int size);
int readPositiveInt(const char prompt[]);
double readNonNegativeDouble(const char prompt[]);

#endif
