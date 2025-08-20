 #include <iostream>
#include <iomanip>

using namespace std;

// -----------------------------------------------------------------------------
// (C) Paso por puntero: swap y variaciones
// Implementar aquí para usarlas más abajo.
// -----------------------------------------------------------------------------
void swap_por_puntero(int* a, int* b) {
    // implementar intercambio clásico usando *a, *b y una variable temporal.
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_si_mayor(int* p, int* q) {
    // intercambiar solo si *p > *q.
    if(*p > *q){
        int tmp= *p;
        *p= *q;
        *q= tmp; 
    }
}

void swap_si_menor(int* p, int* q) {
    // intercambiar solo si *p < *q.
    if(*p < *q){
        int tmp= *p;
        *p= *q;
        *q= tmp; 
    }
}

void set_si_positivo(int* p, int valor) {
    // escribir 'valor' en *p solo si valor > 0.
    if(*p>0){
        *p= valor;
    }
}

// -----------------------------------------------------------------------------
// (D) Funciones que procesan arreglos pasados por puntero
// -----------------------------------------------------------------------------
int suma(const int* arr, int n) {
    // recorrer arr[0..n-1] y acumular.
    int suma=0;
    for(int i=0; i<n; i++){
        suma+=arr[i];
    }
    return suma;
}

double promedio(const int* arr, int n) {
    //usar suma(...) y devolver (double)suma/n si n>0; si n==0 retornar 0.0.
    //veo si n==0 y en caso de que si devuelvo 0.0
    if(n==0)
    return 0.0;
    //si no se retornó devuelvo el promedio
    return suma(arr,n)/n;

}

int maximo(const int* arr, int n) {
    // devolver el mayor valor del arreglo (validar n>0).
    //valido que n>0, en caso de que no retorno 0
    if(n==0)
    return 0;
    //encuentro el mayor valor del arreglo y lo devuelvo 
    int max= arr[0];
    for(int i=0; i<n; i++){
        if(max<arr[i]){
            max=arr[i];
        }     
    }
    return max;
}
// -----------------------------------------------------------------------------
// (C) Funciones 
// -----------------------------------------------------------------------------
void swap_por_puntero2(int &x, int&y){
    int temp= x; 
    x=y; 
    y=temp;     
}

void swap_si_mayor2(int &x, int &y)
{
    if(x > y)
    {
        swap_por_puntero2(x,y); 
    }
}

void swap_si_menor2(int &x, int &y)
{
    if(x<y)
    swap_por_puntero2(x,y);

}

void set_si_positivo2(int &x, int valor){
    if (valor>0)
    {
        x= valor; 
    }
}

int main() {
    cout << fixed << setprecision(2);

    // -------------------------------------------------------------------------
    // (A) Variables y direcciones (calentamiento)
    // -------------------------------------------------------------------------
    // TODO:
    // 1) Declarar: int a=5; float f=3.14f; char c='Z';
    // 2) Imprimir valor y dirección:
    //    cout << "a=" << a << "  &a=" << &a << "\n";
    //    cout << "f=" << f << "  &f=" << &f << "\n";
    //    Para 'c' usar:
    //    cout << "c=" << c << "  &c=" << static_cast<const void*>(&c) << "\n";
    // 3) Escribir en comentarios 2-3 observaciones sobre el patrón de direcciones.

    cout << "APARTADO A \n"; 
    int a=5;
    float f=3;
    char c='Z';

    cout << a << " " << &a << "\n";
    cout << f << " " << &f << "\n";
    cout << c << " " << static_cast<const void*>(&c) << "\n"; 

    /*al imprimirlo la consola mostró:
        5 0x5ffe8c
        3.00 0x5ffe88
        Z 0x5ffe87 */
    // entre el int y el float hay una diferencia de 5 bytes entre una direccion y la otra(debido a que el float ocupa 4 bytes)
    //en el byte restante se guardo el char lo que significa que ocupa 1 byte.

    // -------------------------------------------------------------------------
    // (B) Proyecto CasaDomotica++ - Parte 1: Sensor de temperatura por puntero
    // -------------------------------------------------------------------------
    // El "sensor" será una variable 'temperaturaActual' y un puntero a ella.
    // TODO:
    // 1) Declarar: int temperaturaActual = 22;
    // 2) Declarar: int* ptrTemp = &temperaturaActual;
    // 3) Mostrar equivalencia: *ptrTemp y temperaturaActual.
    // 4) Modificar el valor a través del puntero: *ptrTemp = 27; y verificar.
    // 5) Leer una nueva temperatura desde consola y asignarla vía *ptrTemp.

    cout << "APARTADO B \n"; 

    // 1)
    int temperaturaActual= 22; 
    // 2)
    int* ptrTemp= &temperaturaActual; 
    // 3)
    cout << "contenido en ptrTemp: " << *ptrTemp << "\n"<<  " contenido en temperaturaActual: " << temperaturaActual << "\n";
    // 4)
    *ptrTemp= 27; 
    cout << "contenido en ptrTemp: " << *ptrTemp << "\n"<<  " contenido en temperaturaActual: " << temperaturaActual << "\n";
    // 5)
    cin >> *ptrTemp; 
    cout << "contenido en ptrTemp: " << *ptrTemp << "\n"<<  " contenido en temperaturaActual: " << temperaturaActual << "\n"; 


    // -------------------------------------------------------------------------
    // (C) Paso por puntero: pruebas de swap y variantes
    // -------------------------------------------------------------------------
     cout << "APARTADO C \n"; 
    // 1) Implementar swap_por_puntero arriba y probar con:
    //    int x=5, y=9;  swap_por_puntero(&x,&y);
    int x=5; 
    int y=9; 
    cout << x << " " <<y << "\n"; 
    swap_por_puntero2(x,y); 
    cout << x << " " <<y << "\n";

    // 2) Implementar swap_si_mayor y probar casos (p.ej., 10 y 3, luego 2 y 7).
    int z=10; 
    int j=3; 
    cout << z << " " << j << "\n";
    swap_si_mayor2(z,j);
    cout << z << " " << j << "\n";

    int b= 2; 
    int d= 7; 
    cout << b << " " << d << "\n";
    swap_si_mayor2(b,d);
    cout << b << " " << d << "\n";

    // 3) (Opcional) swap_si_menor y set_si_positivo.
    set_si_positivo2(b,5); 
    cout << b << "\n"; 
    set_si_positivo2(b,-1);
    cout << b << "\n";


    // -------------------------------------------------------------------------
    // (D) Arreglos estáticos: direcciones y funciones con punteros
    // -------------------------------------------------------------------------
    // 1) Declarar un arreglo fijo: int v[5] = {10,20,30,40,50};
    int v[5]={10,20,30,40,50};
    // 2) Imprimir v[i] y &v[i] en un for (i=0..4) para observar contigüidad.
    //    Sugerencia de línea para dirección:
    //    cout << (void*)(&v[i]) << "\n";
    for(int i=0; i<5; i++)
    {
        cout << "direccion: " << (void*)&v[i] << " " <<  "contenido: " << v[i] << "\n";

    }

    // 3) Llamar a suma(v,5), promedio(v,5) y (opcional) maximo(v,5) e imprimir.
   int sum= suma(v,5);
   double prom= promedio(v,5);
   int max= maximo(v,5);

   cout << sum << " " << prom << " " << " " << max; 
   
    cout << "\nFin Semana 1. Próximo paso: memoria dinámica y archivos (Semana 2).\n";
    return 0;

}
