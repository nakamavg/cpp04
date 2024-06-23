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

## Interfaces en C++
- En C++, una interfaz es una clase que tiene al menos una función miembro pura virtual. Una función pura virtual es una función que se define así:

```cpp
virtual void functionName() = 0;
```
- Esto indica que la clase es abstracta y no se puede instanciar directamente. Las clases derivadas deben implementar estas funciones puras virtuales.

- En el ejercicio, nos piden implementar una clase abstracta AMateria y tres clases concretas: Ice, Cure, Character y MateriaSource, cada una con funcionalidades específicas.
## Teoria
- En este ejercicio es un resumen de todo lo aprendido mas algo nuevo:
	- Las interfaces : Es una especia de contrato que define metodos que una clase debe implementar, pero
	no proporciona  la implementacion de esos metodos.
	- Polimorfismo: Permite que Diferentes clases sean tratadas de manera uniforme si implementan la misma interfaz.
	- Desacoplamiento: Las clases pueden cambiar idependientemente si que cumplan con la misma interfaz
	- Reusabilidad y Mantenibilidad: Fomentan la reusabilidad y mejoran la mantenibilidad del código al separar la definición de la funcionalidad de su implementación.

 ## Paso a Paso para el Ejercicio
- Definir la clase AMateria:
	- Tiene un tipo protegido (std::string type).
	- Métodos puros virtuales como clone() y use().
- Definir las clases Ice y Cure:
	- Ambas heredarán de AMateria y deben implementar los  métodos clone() y use().
- Definir la clase ICharacter:
	- Es una interfaz con métodos puros virtuales para gestionar un inventario de materias.
- Definir la clase Character:
	- Hereda de ICharacter y debe implementar un inventario de materias.
- Definir la clase IMateriaSource:
	- Otra interfaz para gestionar y crear AMateria.
- Definir la clase MateriaSource:
	- Hereda de IMateriaSource y debe gestionar un conjunto de plantillas de materias y crear nuevas instancias.

 ## Resumen 
- Interfaz (ICharacter): Define un conjunto de métodos que deben implementarse.
- Clase Abstracta (AMateria): Proporciona una base común y define métodos puros virtuales.
- Clases Concretas (Character, Ice, Cure): Implementan la funcionalidad específica requerida.
