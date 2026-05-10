#include<stdio.h>
#include<string.h>

struct Employee
{
    int id;
    char name[50];
    char designation[50];
    float salary;
};

void displayEmployees(struct Employee emp[], int n)
{
    int i;

    printf("Employee Records\n");

    for(i = 0; i < n; i++)
    {
        printf("ID: %d\n", emp[i].id);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].designation);
        printf("Salary: %f\n", emp[i].salary);
        printf("--------------------------------------------------\n");
    }
}

void findHighestSalary(struct Employee emp[], int n)
{
    int i, maxIndex = 0;

    for(i = 1; i < n; i++)
    {
        if(emp[i].salary > emp[maxIndex].salary)
        {
            maxIndex = i;
        }
    }

    printf("\nEmployee With Highest Salary\n");
    printf("ID: %d\n", emp[maxIndex].id);
    printf("Name: %s\n", emp[maxIndex].name);
    printf("Designation: %s\n", emp[maxIndex].designation);
    printf("Salary: %.2f\n", emp[maxIndex].salary);
}

void searchEmployee(struct Employee emp[], int n)
{
    int choice, id, i, found = 0;
    char name[50];

    printf("Search Employee\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
    {
        printf("Enter ID: ");
        scanf("%d", &id);

        for(i = 0; i < n; i++)
        {
            if(emp[i].id == id)
            {
                printf("Employee Found\n");
                printf("Name: %s\n", emp[i].name);
                printf("Designation: %s\n", emp[i].designation);
                printf("Salary: %f\n", emp[i].salary);
                found = 1;
            }
        }
    }
    else if(choice == 2)
    {
        printf("Enter Name: ");
        scanf("%s", name);

        for(i = 0; i < n; i++)
        {
            if(strcmp(emp[i].name, name) == 0)
            {
                printf("Employee Found\n");
                printf("ID: %d\n", emp[i].id);
                printf("Designation: %s\n", emp[i].designation);
                printf("Salary: %.2f\n", emp[i].salary);
                found = 1;
            }
        }
    }

    if(found == 0)
    {
        printf("Employee not found.\n");
    }
}

void updateBonus(struct Employee emp[], int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        if(emp[i].salary < 50000)
        {
            emp[i].salary = emp[i].salary + (emp[i].salary * 0.10);
        }
    }

    printf("10%% bonus added to employees with salary below 50000.\n");
}

int main()
{
    int n, i;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    for(i = 0; i < n; i++)
    {
        printf("Enter details of Employee %d\n", i + 1);

        printf("Enter ID: ");
        scanf("%d", &emp[i].id);

        printf("Enter Name: ");
        scanf("%s", emp[i].name);

        printf("Enter Designation: ");
        scanf("%s", emp[i].designation);

        printf("Enter Salary: ");
        scanf("%f", &emp[i].salary);
    }

    displayEmployees(emp, n);

    findHighestSalary(emp, n);

    searchEmployee(emp, n);

    updateBonus(emp, n);

    displayEmployees(emp, n);

    return 0;
}