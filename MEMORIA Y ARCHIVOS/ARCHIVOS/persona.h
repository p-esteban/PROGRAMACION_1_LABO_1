#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#define TEXT_SIZE 50

typedef struct
{
    int id;
    char nombre[TEXT_SIZE];
    char apellido[TEXT_SIZE];
    int estado;
}Persona;


#endif // PERSONA_H_INCLUDED


Persona* Pers_new(void);
int Pers_delete(Persona* this);

int Pers_setId(Persona* this, int id);
int Pers_getId(Persona* this, int* resultado);
int Pers_setNombre(Persona* this, char* nombre);
int Pers_getNombre(Persona* this, char* resultado);
int Pers_setApellido(Persona* this, char* apellido);
int Pers_getApelldio(Persona* this, char* resultado);
int Pers_setEstado(Persona* this, int estado);
int Pers_getEstado(Persona* this, int* resultado);
