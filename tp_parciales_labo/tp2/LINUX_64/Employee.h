#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#define TEXT_SIZE 51

typedef struct
{
    int id;
    char name[TEXT_SIZE];
    char lastName[TEXT_SIZE];
    float salary;
    int sector;
    int isEmpty;

}Employee;


#endif // EMPLOYEE_H_INCLUDED

int initEmployees(Employee* list, int len);
int findEmpty(Employee* list, int len, int* index);


int addEmployee(Employee* list, int len, int* contadorID);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);

void mock(Employee* list,int* contadorID);
int editEmployee(Employee* list, int len);
int isEmpty(Employee* list, int len);
int reportEmployee(Employee* list, int len);
int reportSalary(Employee* list, int len);



