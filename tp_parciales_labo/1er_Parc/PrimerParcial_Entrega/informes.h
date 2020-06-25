#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED


void informes_menu(Instrumento arrayInstrumento[], Musico arrayMusico[], Orquesta arrayOrquesta[],int sizeInstrumento,int sizeMusico,int sizeOrquesta);

int informes_listarOrquestaPorLugar(Orquesta arrayOrquesta[], int sizeOrquesta) ;
int informes_listarMusicosPorCriterioEdad(Musico arrayMusico[],Orquesta arrayOrquesta[], Instrumento arrayInstrumento[], int sizeMusico, int sizeOrquesta, int sizeIntrumento);
int informes_listarOrquestaPorCantMusicos(Orquesta arrayOrquesta[], Musico arrayMusico[], int sizeOrquesta, int sizeMusico);
int informes_listarInstrumentoPorOrquesta(Orquesta arrayOrquesta[], int sizeOrquesta,Instrumento arrayInstrumento[],int sizeInstrumento, Musico arrayMusico[],int sizeMusico) ;
int informes_listarPromedioInstrumento(Orquesta arrayOrquesta[], Musico arrayMusico[], int sizeOrquesta, int sizeMusico);

int informes_listarOrquestaCompleta(Orquesta arrayOrquesta[], Musico arrayMusico[],Instrumento arrayInstrumento[], int sizeOrquesta, int sizeMusico, int sizeInstrumento);

int informes_listarOrquestaConMenosMusicos(Orquesta arrayOrquesta[], Musico arrayMusico[], int sizeOrquesta, int sizeMusico);
int informes_mostrarOrquesta(Orquesta array[], int posicion);

int informes_listarMusicoCriterioTipoInstrumento(Musico arrayMusico[], Instrumento arrayInstrumento[], int sizeMusico, int sizeInstrumento);

#endif // INFORMES_H_INCLUDED
