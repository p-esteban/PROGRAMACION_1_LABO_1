#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;



Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete(Employee* this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setIdStr(Employee* this, char* idStr);
int employee_getIdStr(Employee* this, char* resultado);

int employee_setHorasTrabajadasStr(Employee* this, char* horasTrabajadasStr);
int employee_getHorasTrabajadasStr(Employee* this, char* resultado);

int employee_setSueldoStr(Employee* this, char* sueldoStr);
int employee_getSueldoStr(Employee* this, char* resultado);

int employee_searchById(LinkedList* pArrayListEmployee, int valorBuscado, int* index);
int employee_maxId(LinkedList* pArrayListEmployee, int* maxID);

int employee_criterioName(void* this1, void* this2);
int employee_criterioId(void* this1, void* this2);
int employee_criterioHoras(void* this1, void* this2);
int employee_criterioSueldo(void* this1, void* this2);






#endif // employee_H_INCLUDED


