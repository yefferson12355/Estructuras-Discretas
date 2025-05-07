#include <iostream>
using namespace std;

class Estudiante{
    private:
        char*nombres;
        char*apellidos;
        int edad;
    public:
        void darNombres(char*n){
            nombres=n;
        }

};
class Libro{
    private:
        char*nombre;
        char*autor;
        int paginas;
    public:
        void darNombre(){
            //...
        }
        //...
};

class Prestamos{
    private:
        Estudiante estu;
        Libro lib;
        char*fecha;
        char*devolucion;
    public:
        void darEstudiante(Estudiante e){

        }
        //...
};

int main()
{
    Estudiante juan;
    juan.darNombre("Juan");
    Estudiante pedro;
    Estudiante maria;

    Libro mate;
    Libro historia;
    Libro progra;
    Libro cpp;

    Prestamos p1;
    p1.darEstudiante(juan);
    p1.darLibro(historia);
    p1.darFecha("2024-06-06");
    p1.darFecha("2024-06-08");
    p1.mostrar();

    Prestamos p2;
    p2.darEstudiante(maria);
    p2.darLibro(cpp);
    p2.darFecha("2024-06-10");
    p2.darFecha("2024-06-15");
    p2.mostrar();

    return 0;
}
