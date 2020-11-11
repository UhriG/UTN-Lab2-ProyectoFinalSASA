#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha
{
    private:
        int dia;
        int mes;
        int anio;
    public:
        //SET
        void setFecha(int, int, int);
        //GET
        int getDia(){return dia;};
        int getMes(){return mes;};
        int getAnio(){return anio;};
        void mostrarFecha();
        void cargarFecha(tm*);
        void fechaActual(tm*);
        void conversorFecha(tm*);

};


#endif // FECHA_H_INCLUDED
