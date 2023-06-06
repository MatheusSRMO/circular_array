# Circular Array

A biblioteca `circular_array` implementa uma estrutura de dados de array circular em linguagem C. Um array circular é uma estrutura que permite armazenar e manipular elementos de forma circular, ou seja, quando um elemento é inserido no final do array e não há mais espaço disponível, o próximo elemento é adicionado no início do array, reutilizando posições vazias.

## Estrutura

A estrutura `CircularArray` é definida da seguinte forma:

```c
struct circular_array {
    data_type* items;
    int capacity;
    int size;
    int front;
    int rear;
    bool dynamic;
};
```

- `items`: um ponteiro para o array que armazena os elementos.
- `capacity`: a capacidade máxima do array circular.
- `size`: o número de elementos atualmente presentes no array.
- `front`: a posição do primeiro elemento no array.
- `rear`: a posição do último elemento no array.
- `dynamic`: um indicador booleano que determina se o array pode crescer dinamicamente quando estiver cheio.

## Funções

A biblioteca `circular_array` oferece as seguintes funções:

### `CircularArray* circular_array_construct(int capacity, bool dynamic)`

Cria e inicializa um novo array circular.

- `capacity`: a capacidade inicial do array circular.
- `dynamic`: indica se o array pode crescer dinamicamente quando estiver cheio.

Retorna um ponteiro para a estrutura `CircularArray` recém-criada.

### `bool circular_array_is_empty(CircularArray* circular_array)`

Verifica se o array circular está vazio.

- `circular_array`: o ponteiro para o array circular a ser verificado.

Retorna `true` se o array estiver vazio, caso contrário, retorna `false`.

### `bool circular_array_is_full(CircularArray* circular_array)`

Verifica se o array circular está cheio.

- `circular_array`: o ponteiro para o array circular a ser verificado.

Retorna `true` se o array estiver cheio, caso contrário, retorna `false`.

### `void circular_array_push(CircularArray* circular_array, data_type data)`

Adiciona um elemento no final do array circular.

- `circular_array`: o ponteiro para o array circular.
- `data`: o elemento a ser adicionado.

Se o array estiver cheio e não for dinâmico, a função termina o programa com uma mensagem de erro. Se o array estiver cheio e for dinâmico, ele é redimensionado para o dobro da capacidade atual antes de adicionar o novo elemento.

### `data_type circular_array_pop(CircularArray* circular_array)`

Remove e retorna o primeiro elemento do array circular.

- `circular_array`: o ponteiro para o array circular.

Se o array estiver vazio, a função termina o programa com uma mensagem de erro.

Retorna o primeiro elemento do array.

### `void circular_array_print(CircularArray* circular_array, void (*print_fn)(data_type))`

Imprime os elementos do array circular.

- `circular_array`: o ponteiro para o array circular.
- `print_fn`: um ponteiro para uma função que imprime um elemento do array.

A função `print_fn` é chamada para imprimir cada elemento do array circular. Os elementos são separados por vírgula e o array é impresso entre colchetes.

### `void circular_array_destruct(CircularArray* circular_array)

`

Libera a memória alocada para o array circular.

- `circular_array`: o ponteiro para o array circular.

Esta função deve ser chamada para liberar a memória alocada para o array circular quando ele não for mais necessário.

## Exemplo de Uso

Aqui está um exemplo de como usar a biblioteca `circular_array`:

```c
#include <stdio.h>
#include <stdbool.h>
#include "circular_array.h"

void print_int(int value) {
    printf("%d", value);
}

int main() {
    CircularArray* array = circular_array_construct(5, true);

    circular_array_push(array, 1);
    circular_array_push(array, 2);
    circular_array_push(array, 3);
    circular_array_push(array, 4);
    circular_array_push(array, 5);

    circular_array_print(array, print_int);

    int popped_value = circular_array_pop(array);
    printf("Popped value: %d\n", popped_value);

    circular_array_print(array, print_int);

    circular_array_destruct(array);

    return 0;
}
```

Este exemplo cria um array circular com capacidade inicial de 5 elementos e permitindo crescimento dinâmico. Em seguida, adiciona 5 elementos ao array, imprime o array, remove o primeiro elemento, imprime o array novamente e, por fim, libera a memória alocada pelo array circular.
