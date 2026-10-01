#ifndef REPORTS_H
#define REPORTS_H

#include "employees.h"
#include "suppliers.h"
#include "assets.h"

#define DEPT_LEN 30

typedef struct {
    char departmentName[DEPT_LEN];
    double allocatedBudget;
    double expenditure;
} Budget;

void generateEmployeeReport(const Employee employees[], int empCount);
void generateBudgetReport(const Budget budgets[], int budgetCount);
void generateSupplierReport(Supplier suppliers[], int suppCount);
void generateAssetReport(Asset assets[], int assetCount);

#endif
