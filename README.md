# cpp04

C++ - Module 04 Subtype polymorphism, abstract classes, interfaces

## ex00

- La clase Gato y Perro Heredan de animal.

Como todas las clases van a tener este metodo
`virtual void makeSound() const;`
debe ser virtual para asi poder sobrescribirlo
la clase WrongCat y Wrong Animal sirven para ejemplificar
que pasa cuando cometemos el error de no hacer el metodo 
virtual

## ex01

- Añadir clase cerebro;

- La clase cerebro tiene un array de 100 ideas

- La clase perro y gato ahora tienen un puntero a Brain
	- Lo cual hare que en el constructor se haga un new Brain
	- en el operador de copia tambien debemos hacer un for
	para mover todas las ideas

# ex02 Clase virtual

- Como no tiene sentido que llamemos a la clase Animal necesitamos que sea abstracta para que no se pueda acceder
desde fuera.

# ex03 Materias!

## Paso 1: Definir la Clase Abstracta AMateria

