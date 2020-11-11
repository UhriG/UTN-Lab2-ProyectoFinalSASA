#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H
#include "usuario.h"
#include "producto.h"
#include "Fecha.h"

class Movimiento
{
    public:
        //void movimiento();
        void cargar();
        bool escribirDisco();
        void setLogueado(char *n);
        char *getLogueado(){return usuarioLogueado;};
        int movimiento();

    private:
        char usuarioLogueado[20];
        char producto[20]
        char marca[20];
        int categoria_id;
        int tipoMovimiento;
        int stock;
        Fecha f;
};

#endif // MOVIMIENTOS_H
