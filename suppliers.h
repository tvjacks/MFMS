#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "suppliers.h"
#include "input.h"

static int supplierIdExists(const Supplier suppliers[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (suppliers[i].supplierID == id) {
            return 1;
        }
    }
    return 0;
}

static int isValidPhone(const char phone[]) {
    if (strlen(phone) < 7) {
        return 0;
    }
    for (int i = 0; phone[i] != '\0'; i++) {
        if (!isdigit((unsigned char)phone[i]) && phone[i] != '+' &&
            phone[i] != ' ' && phone[i] != '-') {
            return 0;
        }
    }
    return 1;
}

static void printSupplier(const Supplier *s) {
    printf("ID: %d | Name: %s | Email: %s | Tel: %s | Town: %s\n",
           s->supplierID, s->name, s->email, s->telephone, s->town);
}

void addSupplier(Supplier suppliers[], int *count) {
    Supplier s;

    if (*count >= MAX_SUPPLIERS) {
        printf("Error: Supplier database is full.\n");
        return;
    }

    s.supplierID = readPositiveInt("Enter Supplier ID: ");
    if (supplierIdExists(suppliers, *count, s.supplierID)) {
        printf("Error: Supplier ID %d already exists.\n", s.supplierID);
        return;
    }

    readLine("Enter Supplier Name: ", s.name, STR_LEN);

    while (1) {
        readLine("Enter Email: ", s.email, STR_LEN);
        if (strchr(s.email, '@') != NULL && strchr(s.email, '.') != NULL) {
            break;
        }
        printf("Error: Enter a valid email (e.g. name@example.com).\n");
    }

    while (1) {
        readLine("Enter Telephone: ", s.telephone, STR_LEN);
        if (isValidPhone(s.telephone)) {
            break;
        }
        printf("Error: Telephone must be at least 7 digits (numbers, +, - and spaces only).\n");
    }

    readLine("Enter Town/Location: ", s.town, STR_LEN);

    suppliers[*count] = s;
    (*count)++;
    printf("Supplier added successfully!\n");
}

void displaySuppliers(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("No suppliers registered yet.\n");
        return;
    }

    printf("\n--- REGISTERED SUPPLIERS ---\n");
    for (int i = 0; i < count; i++) {
        printSupplier(&suppliers[i]);
    }
}

void searchSupplier(const Supplier suppliers[], int count, const char searchName[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(suppliers[i].name, searchName) == 0) {
            printf("\nSupplier Found:\n");
            printSupplier(&suppliers[i]);
            return;
        }
    }
    printf("Supplier with name '%s' not found.\n", searchName);
}
