#pragma once
class Triangle {
private:
    float lado1;
    float lado2;
    float lado3;

public:
    Triangle(float lado1, float lado2, float lado3) {
        this->lado1 = lado1;
        this->lado2 = lado2;
        this->lado3 = lado3;
    }
    ~Triangle() {}

    void setLados(float lado1, float lado2, float lado3) {
        this->lado1 = lado1;
        this->lado2 = lado2;
        this->lado3 = lado3;
    }

    bool esEquilatero() const {
        return (lado1 == lado2) && (lado2 == lado3);
    }

    bool esIsoceles() const {
        return ((lado1 == lado2) || (lado1 == lado3) || (lado2 == lado3)) && !esEquilatero();
    }

    bool esEscaleno() const {
        return !esEquilatero() && !esIsoceles();
    }

    bool esInvalido() const {
        return (lado1 + lado2 <= lado3) || (lado1 + lado3 <= lado2) || (lado2 + lado3 <= lado1);
    }

    void clasificacion() const {
        if (esInvalido()) {
            std::cout << "Triángulo invalido" << std::endl;
        } else if (esEquilatero()) {
            std::cout << "Triángulo equilatero" << std::endl;
        } else if (esIsoceles()) {
            std::cout << "Triángulo isosceles" << std::endl;
        } else {
            std::cout << "Triángulo escaleno" << std::endl;
        }
    }
};