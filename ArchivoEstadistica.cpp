#include "ArchivoEstadistica.h"

ArchivoEstadistica::ArchivoEstadistica()
{
    strcpy(_nombre, "Estadisticas.dat");
}

//Lee el registro
Estadisticas ArchivoEstadistica::leerRegistro()
{
    Estadisticas reg;
    FILE *o;
    o=fopen(_nombre, "rb");
    if(o==NULL) return reg;
    fseek(o,0, 0);
    fread(&reg,sizeof(Estadisticas),1,o);
    fclose(o);
    return reg;
}
//Cambia el contador del Trompo ganador
int ArchivoEstadistica::cambiarContador(Estadisticas reg, int ganador)
{
    FILE *p;
    p=fopen(_nombre, "rb+");
    if(p==NULL) return -1;
    switch(ganador)
    {
    case 1:
        reg.IncrementarContCaballero();
        break;
    case 2:
        reg.IncrementarContDragon();
        break;
    }
    fseek(p,0, 0);
    fwrite(&reg, sizeof reg,1, p);
    fclose(p);
    return 1;
}
//VERIFICA QUE EL ARCHIVO ESTE CREADO
int ArchivoEstadistica::verificarArchivoCreado(Estadisticas reg)
{
    FILE *p;
    p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        // El archivo no existe, se crea y se escribe el registro inicial
        p = fopen(_nombre, "wb");
        if (p == NULL)
        {
            // No se pudo crear el archivo
            return -1;
        }
        fwrite(&reg, sizeof(Estadisticas), 1, p);
        std::cout<< "Se creo el archivo." <<std::endl;
        fclose(p);
        return 1;
    }

    // El archivo ya existe
    fclose(p);
    std::cout<< "El archivo ya existe." <<std::endl;
    return 0;
}
