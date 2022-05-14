# 1
Demostrar que el algoritmo voraz para el problema de la mochila sin fragmentación no siempre obtiene la solución óptima. Para ello puede modificar el algoritmo visto en clase de manera de que no permita fragmentación y encontrar un ejemplo para el cual no halla la solución óptima.

```kotlin
type Objeto =   tuple
                    id: Nat
                    value: Float
                    weight: Float
                end tuple

fun mochila(W: Float, C: Set of Objeto) ret L: List of Objeto
    var obj: Objeto 
    var resto: Float
    var C_aux: Set of Objeto

    L := empty_list()
    C_aux := set_copy(C)
    resto := W

    do (resto > 0)
        obj := select_obj(C_aux)

        if obj.weight <= resto then
            resto := resto - obj.weight
            addl(L, obj)

        elim(C_aux, obj)

    set_destroy(C_aux)
end fun

fun select_obj(C: Set of Objeto) ret r: Objeto
    var C_aux: Set of Objeto
    var o: Objeto
    var m: Float

    m := -∞
    C_aux := set_copy(C)

    do (not is_empty_set(C_aux))
        o := get(C_aux)

        if (o.value/o.weight > m) then 
            m := o.value/o.weight
            r := o

        elim(C_aux,o)

    set_destroy(C_aux)
end fun
```

```kotlin
var BackpackWeight: Float
var Items: Set of Objeto
var A, B, C, D: Objeto

A := {id: 1, value: 30, weight: 7}  // 4.28pts
B := {id: 2, value: 20, weight: 6}  // 3.33pts
C := {id: 3, value: 15, weight: 4}  // 3.75pts

Items := {A, B, C}
BackpackWeight := 10
//  Mejor combinación posible: [B,C]

mochila(BackpackWeight, Items) // Devuelve: [A]
```

# 2
Considere el problema de dar cambio. Pruebe o dé un contraejemplo: si el valor de cada moneda es al menos el doble de la anterior, y la moneda de menor valor es 1, entonces el algoritmo voraz arroja siempre una solución óptima.

- Supongamos 
  - un conjunto `1, 4, 9`
  - un monto `12`
- El algoritmo voraz devuelve `2`

---

Para cada uno de los siguientes ejercicios:
- Describa cuál es el criterio de selección.
- ¿En qué estructuras de datos representará la información del problema?
. Explique el algoritmo, es decir, los pasos a seguir para obtener el resultado. No se pide que ”lea” el algoritmo (”se define una variable x”, ”se declara un for”), si no que lo explique (”se recorre la lista/el arreglo/” o ”se elije de tal conjunto el que satisface...”).
- Escriba el algoritmo en el lenguaje de programación de la materia.