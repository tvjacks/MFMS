#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#ifndef STR_LEN
#define STR_LEN 50
#endif

typedef struct {
    int supplierID;
    char name[STR_LEN];
    char email[STR_LEN];
    char telephone[STR_LEN];
    char town[STR_LEN];
} Supplier;

void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count, const char searchName[]);

#endif
