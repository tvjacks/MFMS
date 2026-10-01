#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "input.h"

static int assetIdExists(const Asset assets[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (assets[i].assetID == id) {
            return 1;
        }
    }
    return 0;
}

static void printAsset(const Asset *a) {
    printf("ID: %d | Name: %s | Type: %s | Value: N$%.2f | Dept: %s | Condition: %s\n",
           a->assetID, a->name, a->type, a->purchaseValue, a->department, a->condition);
}

void addAsset(Asset assets[], int *count) {
    Asset a;

    if (*count >= MAX_ASSETS) {
        printf("Error: Asset database is full.\n");
        return;
    }

    a.assetID = readPositiveInt("Enter Asset ID: ");
    if (assetIdExists(assets, *count, a.assetID)) {
        printf("Error: Asset ID %d already exists.\n", a.assetID);
        return;
    }

    readLine("Enter Asset Name: ", a.name, STR_LEN);
    readLine("Enter Asset Type (e.g. Vehicle, Computer): ", a.type, STR_LEN);
    a.purchaseValue = readNonNegativeDouble("Enter Purchase Value (N$): ");
    readLine("Enter Department: ", a.department, STR_LEN);
    readLine("Enter Condition (e.g. Good, Fair, Poor): ", a.condition, STR_LEN);

    assets[*count] = a;
    (*count)++;
    printf("Asset added successfully!\n");
}

void displayAssets(const Asset assets[], int count) {
    if (count == 0) {
        printf("No assets registered yet.\n");
        return;
    }

    printf("\n--- REGISTERED ASSETS ---\n");
    for (int i = 0; i < count; i++) {
        printAsset(&assets[i]);
    }
}

void searchAsset(const Asset assets[], int count, int searchID) {
    for (int i = 0; i < count; i++) {
        if (assets[i].assetID == searchID) {
            printf("\nAsset Found:\n");
            printAsset(&assets[i]);
            return;
        }
    }
    printf("Asset with ID %d not found.\n", searchID);
}
