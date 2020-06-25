#ifndef FANTASMA_H_INCLUDED
#define FANTASMA_H_INCLUDED

#define SIZE_STRING 51

typedef struct
{
    int id;
    char tipo[SIZE_STRING];
    int cantidad;
    float importe;
}Entrega;


#endif // FANTASMA_H_INCLUDED

Entrega* entrega_new();
Entrega* entrega_newParametros(char* id,char* tipo,char* cantidad, char* importe);

void entrega_delete(Entrega* this);

int entrega_searchById(LinkedList* pArrayListEntrega, int valorBuscado, int* index);
int entrega_maxId(LinkedList* pArrayListEntrega, int* maxID);
int entrega_searchByCantidad(LinkedList* pArrayListEntrega, int valorBuscado, int* index);
int entrega_searchByTipo(LinkedList* pArrayListEntrega, char* valorBuscado, int* index);
int entrega_searchByImporte(LinkedList* pArrayListEntrega, float valorBuscado, int* index);

int entrega_criterioSortId(void* this1, void* this2);
int entrega_criterioSortTipo(void* this1, void* this2);

int entrega_criterioFilterTipo(void* entrega, char* criterio);

int entrega_print(Entrega* entrega);

int entrega_setIdStr(Entrega* this, char* id);
int entrega_setId(Entrega* this, int id);
int entrega_getIdStr(Entrega* this, char* result);
int entrega_getId(Entrega* this, int* result);

int entrega_setTipo(Entrega* this, char* tipo);
int entrega_getTipo(Entrega* this, char* result);

int entrega_setCantidadStr(Entrega* this, char* cantidad);
int entrega_setCantidad(Entrega* this, int cantidad);
int entrega_getCantidadStr(Entrega* this, char* result);
int entrega_getCantidad(Entrega* this, int* result);

int entrega_setImporteStr(Entrega* this, char* importe);
int entrega_setImporte(Entrega* this, float importe);
int entrega_getImporteStr(Entrega* this, char* result);
int entrega_getImporte(Entrega* this, float* result);







