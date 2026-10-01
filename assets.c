#ifndef ASSETS_H
#define ASSETS_H

#define MAX_ASSETS 100
#ifndef STR_LEN
#define STR_LEN 50
#endif

typedef struct {
    int assetID;
    char name[STR_LEN];
    char type[STR_LEN];
    double purchaseValue;
    char department[STR_LEN];
    char condition[STR_LEN];
} Asset;

void addAsset(Asset assets[], int *count);
void displayAssets(const Asset assets[], int count);
void searchAsset(const Asset assets[], int count, int searchID);

#endif
