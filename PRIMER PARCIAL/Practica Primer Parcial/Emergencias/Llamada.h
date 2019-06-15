#ifndef LLAMADA_H_INCLUDED
#define LLAMADA_H_INCLUDED

typedef struct
{
    int idLlamada;
    int idAsociado;
    int idAmbulancia;
    int tiempo;
    int motivo;/// 0-ninguno 1-infarto 2-ACV 3-Gripe
    int estado;/// 0-pendiente 1-cumplido (-1)-Vacio
    float horaEntrada;
    float horaSalida;

}Llamada;

int llam_init(Llamada* pLlamada,int len);
int llam_add(Llamada* pLlamada,Asociado* pAsociado,int len,char* msgE,int tries, int pIndex);
int llam_asignar(Llamada* pLlamada, int len,char* msgE,int tries);

int llam_findCallById(Llamada* pLlamada, int len, int idFind);
int llam_findCallByIdAndEstado(Llamada* pLlamada, int len, int idFind);
int llam_getID (Llamada* pLlamada,int len,char* msgE,int tries, char* msg);
int llam_findFree(Llamada* pLlamada, int len);

int llam_print(Llamada* pLlamada,int len);

#endif // LLAMADA_H_INCLUDED
