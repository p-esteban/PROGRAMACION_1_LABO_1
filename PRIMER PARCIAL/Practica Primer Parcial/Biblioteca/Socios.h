#ifndef SocioS_H_INCLUDED
#define SocioS_H_INCLUDED
typedef struct
{
    int idSocio;
    char apellido[31];
    char nombre[31];
    char sexo[2];
    int telefono;
    char email[4900];
    int dia;
    int mes;
    int ano;
    int isEmpty;/// (-1) vacio - 0 ocupado
}Socio;

int socio_init(Socio* pSocio,int len);

int socio_add(Socio* pSocio,int len,int pIndex,char* msgE,int tries);

int socio_alter(Socio* pSocio, int len,char* msgE,int tries);
int socio_remove(Socio* pSocio, int len,char* msgE,int tries);

int socio_print(Socio* pSocio,int len);


int socio_findFree(Socio* pSocio, int len);
int socio_findSocioById(Socio* pSocio, int len, int idFind);
int socio_getID(Socio* pSocio,int len,char* msgE,int tries, char* msg);




#endif // SocioS_H_INCLUDED
