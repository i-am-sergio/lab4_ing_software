#include <iostream>
#include <gtest/gtest.h>
#include "Triangle.h"

class TriangleTest : public ::testing::Test {
protected:
    Triangle* t1;
    Triangle* t2;  
    Triangle* t3;
    Triangle* t4; 
    Triangle* aux;

    void SetUp() override {
        // Configuración común para todas los tests
        t1 = new Triangle(5.0, 5.0, 5.0);  // Triangulo equilátero
        t2 = new Triangle(4.0, 4.0, 3.0);  // Triangulo isósceles
        t3 = new Triangle(3.0, 4.0, 5.0);  // Triangulo escaleno
        t4 = new Triangle(1.0, 1.0, 3.0);  // Triangulo inválido
        aux = new Triangle(0, 0, 0);       // Triangulo auxiliar 
    }

    void TearDown() override {
        // Liberar recursos después de los tests
        delete t1;
        delete t2;
        delete t3;
        delete t4;
        delete aux;
    }
};

TEST_F(TriangleTest, Equilatero) {
    ASSERT_TRUE(t1->esEquilatero());
    ASSERT_FALSE(t1->esIsoceles());
    ASSERT_FALSE(t1->esEscaleno());
    ASSERT_FALSE(t1->esInvalido());
}

TEST_F(TriangleTest, Isoceles) {
    ASSERT_FALSE(t2->esEquilatero());
    ASSERT_TRUE(t2->esIsoceles());
    ASSERT_FALSE(t2->esEscaleno());
    ASSERT_FALSE(t2->esInvalido());
}

TEST_F(TriangleTest, Escaleno) {
    ASSERT_FALSE(t3->esEquilatero());
    ASSERT_FALSE(t3->esIsoceles());
    ASSERT_TRUE(t3->esEscaleno());
    ASSERT_FALSE(t3->esInvalido());
}

// Triángulo inválido (violación de la desigualdad triangular)
TEST_F(TriangleTest, Invalido) {
    ASSERT_TRUE(t4->esInvalido());
}

TEST_F(TriangleTest, IngresoPorConsola) {
    double lado1, lado2, lado3;
    std::cout << "Ingresa el lado 1: ";
    std::cin >> lado1;
    std::cout << "Ingresa el lado 2: ";
    std::cin >> lado2;
    std::cout << "Ingresa el lado 3: ";
    std::cin >> lado3;
    aux->setLados(lado1,lado2,lado3);
    ASSERT_TRUE(aux->esEquilatero() || aux->esIsoceles() || aux->esEscaleno() || aux->esInvalido());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
