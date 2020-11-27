#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED
#include "categoria.h"
class Producto
{
    private:
        int id;
        char nombre[20];
        char marca[20];
        int categoria_id;
        int estado;
        int stock;
    public:
        void setNombre(char *n);
        void setMarca(char *m);
        void setCategoria(int c);
        void setEstado(int e);
        void setStock(int s);
        int getId(){return id;};
        char *getNombre(){return nombre;};
        char *getMarca(){return marca;};
        int getEstado(){return estado;};
        int getStock(){return stock;};
        int getCatId(){return categoria_id;};
        void cargar();
        void mostrar(int modo=1);
        bool escribirDisco();
        int leerDisco(int pos);
        bool modDisco(int pos);
};

// Funciones Externas
int buscarCod(int codB); // Busca el ID
int cantProd(); // Devuelve la cantidad de registros
bool copiaProducto(); // crea bk de producto.dat
bool recProducto(); // recupera bk de producto.dat
#endif // PRODUCTO_H_INCLUDED
