#include <stdio.h>
#include <string.h>
#include "reports.h"

#define REPORT_WIDTH 41

static void printRule(void) {
    for (int i = 0; i < REPORT_WIDTH; i++) {
        putchar('=');
    }
    putchar('\n');
}

static void printHeader(const char *title) {
    int pad = (REPORT_WIDTH - (int)strlen(title)) / 2;

    putchar('\n');
    printRule();
    printf("%*s%s\n", pad, "", title);
    printRule();
}

void generateEmployeeReport(const Employee employees[], int empCount) {
    if (empCount <= 0) {
        printf("No employees registered for reporting.\n");
        return;
    }

    double total = 0;
    double highest = employees[0].basicSalary;
    double lowest = employees[0].basicSalary;

    for (int i = 0; i < empCount; i++) {
        double salary = employees[i].basicSalary;
        total += salary;
        if (salary > highest) highest = salary;
        if (salary < lowest) lowest = salary;
    }

    printHeader("EMPLOYEE REPORT");
    printf("Total Employees: %d\n", empCount);
    printf("Average Salary: N$%.2f\n", total / empCount);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
    printRule();
}

void generateBudgetReport(const Budget budgets[], int budgetCount) {
    if (budgetCount <= 0) {
        printf("No budgets registered for reporting.\n");
        return;
    }

    double totalAllocated = 0;
    double totalExpenditure = 0;
    int overCount = 0;

    for (int i = 0; i < budgetCount; i++) {
        totalAllocated += budgets[i].allocatedBudget;
        totalExpenditure += budgets[i].expenditure;
    }

    printHeader("BUDGET REPORT");
    printf("Total Allocated Budget: N$%.2f\n", totalAllocated);
    printf("Total Expenditure: N$%.2f\n", totalExpenditure);
    printf("Overall Remaining Budget: N$%.2f\n", totalAllocated - totalExpenditure);

    printf("\nDepartments Exceeding Budget:\n");
    for (int i = 0; i < budgetCount; i++) {
        if (budgets[i].expenditure > budgets[i].allocatedBudget) {
            printf("- %s (Allocated: N$%.2f, Expenditure: N$%.2f)\n",
                   budgets[i].departmentName,
                   budgets[i].allocatedBudget,
                   budgets[i].expenditure);
            overCount++;
        }
    }

    if (overCount == 0) {
        printf("  None. All departments are currently within budget.\n");
    }
    printRule();
}

void generateSupplierReport(Supplier suppliers[], int suppCount) {
    printHeader("SUPPLIER REPORT");
    displaySuppliers(suppliers, suppCount);
    printRule();
}

void generateAssetReport(Asset assets[], int assetCount) {
    printHeader("ASSET REPORT");
    displayAssets(assets, assetCount);
    printRule();
}
