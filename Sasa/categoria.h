#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

class categoria
{
    private:
        int id;
        char nombre[20];
        int estado;
    public:
        void setNombre(char *n);
        void setEstado(int e=1);


//        void setNombre(char *n);
//        void setFechaCrea(Fecha);
//        void setFechaMod(Fecha);

        //Get
        int getId(){return id;};
        char *getNombre(){return nombre;};
        int getEstado(){return estado;};


//        Fecha getFechaCrea(){return Fecha;};
//        Fecha getFechaMod(){return Fecha;};


        void cargar();
        void mostrar(int modo=1);
        bool escribirDisco();
        bool leerDisco(int pos);
        bool modDisco(int pos);



//        void cargar();
//        void mostrar();
//        bool escribirDisco();
//        bool leerDisco(int);
};

int buscarIDcat(int idB); // Busca el ID
int buscarNombrecat(char *nombre);
int cantCategoria(); // Devuelve la cantidad de registros
void compCategoria(); // Comprueba si existe categoria
void ordenarCategoriaDesc(categoria *cat, int cantReg); // Ordena de forma descendente

#endif // CATEGORIA_H_INCLUDED
