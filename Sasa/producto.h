#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto
{
    private:
        int id;
        char nombre[10];
        char marca[10];
        int categoria_id;
        int estado;
        int stock;
        //Fecha fecha_creacion;
        //Fecha fecha_modificacion;
    public:
        void setNombre(char *n);
        void setMarca(char *m);
        void setCategoria(int c);
        void setEstado(int e);
        void setStock(int s);
        //void setFechaCrea(Fecha);
        //void setFechaMod(Fecha);
        int getId(){return id;};
        char *getNombre(){return nombre;};
        char *getMarca(){return marca;};
        int getCategoria(){return categoria_id;};
        int getEstado(){return estado;};
        int getStock(){return stock;};
        //Fecha getFechaCrea(){return Fecha;};
        //Fecha getFechaMod(){return Fecha;};
        void cargar();
        void mostrar();
        bool escribirDisco();
        int leerDisco(int pos);
};

#endif // PRODUCTO_H_INCLUDED
