#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

#define SIZE_STRING 51

typedef struct
{
    int id;
    char fecha[SIZE_STRING];//fecha
    char tipo[SIZE_STRING];//varString
    char cuitCliente[SIZE_STRING];//varLongString
    int cantidad;//varInt
    float precioUnitario;//varFloat
}Venta;


#endif // FANTASMA_H_INCLUDED

Venta* venta_new();
Venta* venta_newParametros(char* id,char* fecha,char* tipo, char* cuitCliente,char* cantidad, char* precioUnitario);

void venta_delete(Venta* this);

int venta_searchById(LinkedList* pArrayListVenta, int valorBuscado, int* index);
int venta_maxId(LinkedList* pArrayListVenta, int* maxID);
int venta_searchByTipo(LinkedList* pArrayListVenta, char* valorBuscado, int* index);

int venta_criterioSortId(void* this1, void* this2);
int venta_criterioSortTipo(void* this1, void* this2);

int venta_criterioFilterCantidad(Venta* venta);
int venta_criterioFilterTipo(Venta* venta);
int venta_criterioFilterPrecioUnitario(Venta* venta);
int venta_print(Venta* venta);


int venta_setIdStr(Venta* this, char* id);
int venta_setId(Venta* this, int id);
int venta_getIdStr(Venta* this, char* result);
int venta_getId(Venta* this, int* result);

int venta_setFecha(Venta* this, char* fecha);
int venta_getFecha(Venta* this, char* result);

int venta_setTipo(Venta* this, char* tipo);
int venta_getTipo(Venta* this, char* result);

int venta_setCuitCliente(Venta* this, char* cuitCliente);
int venta_getCuitCliente(Venta* this, char* result);

int venta_setCantidadStr(Venta* this, char* cantidad);
int venta_setCantidad(Venta* this, int cantidad);
int venta_getCantidadStr(Venta* this, char* result);
int venta_getCantidad(Venta* this, int* result);

int venta_setPrecioUnitarioStr(Venta* this, char* precioUnitario);
int venta_setPrecioUnitario(Venta* this, float precioUnitario);
int venta_getPrecioUnitarioStr(Venta* this, char* result);
int venta_getPrecioUnitario(Venta* this, float* result);

int venta_contarRevelados(void* this);
int venta_criterioMayo150(void* this);
int venta_criterioMayo300(void* this);
int venta_criterioTipo(void* this);







