#include <iostream>

class Vector3D{
private:
    double x;
    double y;
    double z;

public:
    //Definir constructor de la clase Vector3D
    Vector3D(double x, double y, double z):x(x), y(y), z(z){}

    //Operador de salida
    friend std::ostream &operator<<(std::ostream &out, const Vector3D &v){
        out << "(" << v.x << ", " << v.y << ", " << v.z <<")";
        return out;
    }

    //Operador de entrada
    friend std::istream &operator>>(std::istream &in, Vector3D &v){
        char dummy;
        in >> dummy >> v.x >> dummy >> v.y >> dummy >> v.z;
        return in;
    }

    //Operador de Igualdad

    bool operator==(const Vector3D &v) const{
        return x == v.x && y == v.y && z == v.z;
    }

    //Operador de desiguadad
    bool operator!=(const Vector3D &v) const{
        return x != v.x && y != v.y && z != v.z;
    }

    //Operador de preincremento
    Vector3D &operator++(){
        ++x;
        ++y;
        ++z;
        return *this;
    }

    //Operador de postIncremento
    Vector3D &operator++(int){
        Vector3D res = *this;
        ++(*this);
        return res;
    }

    //Operador de preDecremento
    Vector3D &operator--(){
        --x;
        --y;
        --z;
        return *this;
    }

    //Operador de postDecremento
    Vector3D &operator--(int){
        Vector3D res = *this;
        --(*this);
        return res;
    }

    //Suma acumulativa
    Vector3D &operator+=(const Vector3D &v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    //Resta acumulativa
    Vector3D &operator-=(const Vector3D &v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    //Operador unario de negación
    Vector3D operator-() const {
        return Vector3D(-x, -y, -z);
    }

    //Operador Suma de vectores
    const Vector3D operator+(const Vector3D &v) const{
        return Vector3D(x + v.x, y + v.y, z + v.z);
    }

    //Operador Resta de vectores
    const Vector3D operator-(const Vector3D &v) const{
        return Vector3D (x - v.x, y - v.y, z - v.z);
    }

    //Suma de un vector con un entero
    const Vector3D operator+(int n) const{
        return Vector3D (x + n, y + n, z + n);
    }

    //Resta de un vector con un numero entero
    const Vector3D operator-(int n) const{
        return Vector3D (x - n, y - n, z - n);
    }

    //Suma de un vector con un numero real
    const Vector3D operator+(double r) const{
        return Vector3D (x + r, y + r, z + r);
    }

    //Resta de un vector con un real
    const Vector3D operator-(double r) const{
        return Vector3D (x - r, y - r, z - r);
    }
};


int main() {
    Vector3D v1 (4.0 , 5.0 , 6.0);
    Vector3D v2 (4.0 , 5.0, 6.0);


    //Operadores de igualdad y desigualdad
    if (v1 == v2){
        std::cout << "Los vectores son iguales." << std::endl;
    } else {
        std::cout << "Los vectores son diferentes." << std::endl;
    }

    //Operedores con incremento y decremento
    ++v1;
    std::cout << "Vector despues de incremento: " << v1 <<std::endl;

    --v1;
    std::cout << "Vector despues de decremento: " << v1 <<std::endl;

    //Operadores de suma y resta
    Vector3D suma = v1 + v2;
    std::cout << "Suma de vectores: " << suma <<std::endl;

    Vector3D resta = v1 - v2;
    std::cout << "Resta de vectores: " << resta <<std::endl;

    // Operadores de suma y resta con enteros y reales
    Vector3D sumaEntero = v1 + 3;
    std::cout << "Suma de vector con entero: " << sumaEntero << std::endl;

    Vector3D restaEntero = v1 - 4;
    std::cout << "Resta de vector con entero: " << restaEntero << std::endl;

    Vector3D sumaReal = v1 + 15.6;
    std::cout << "Suma de vector con real: " << sumaReal << std::endl;

    Vector3D restaReal = v1 - 12.5;
    std::cout << "Resta de vector con real: " << restaReal << std::endl;

    // Operador unario de negación
    Vector3D negacionV1 = -v1;
    std::cout << "Negacion del vector 1: " << negacionV1 << std::endl;
}
