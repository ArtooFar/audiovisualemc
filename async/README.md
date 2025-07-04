# Biblioteca para threads assíncronas – `async.h`

## Conteúdo do diretório

| Arquivo              | Finalidade                                                                                                 |
| -------------------- | ---------------------------------------------------------------------------------------------------------- |
| **`async.h`**        | Implementa quatro *funcoes*  para criar, aguardar (`join`) ou soltar (`detach`) uma *thread*. |
| **`exemploasync.c`** | Exemplo completo (em C99) mostrando o uso

---

## Funções principais

| Função | Descrição                                                                          |
| ------------------- | ---------------------------------------------------------------------------------- |
| `async_run0(f)`     | Lança `f` em uma nova *thread*. `f` **não recebe argumentos**.                     |
| `async_run(f, arg)` | Lança `f` em uma nova *thread*, passando `arg` (ponteiro `void *`) como parâmetro. |
| `async_join(th)`    | Bloqueia até a *thread* `th`.
| `async_detach(th)`  | Coloca a *thread* em segundo plano até concluir. É como se tornasse ela "independente" |


## Passando argumentos para a thread

```c
void imprime_numero(void *arg) {
    int valor = *(int *)arg;     // converte e desreferencia
    printf("Valor = %d\n", valor);
}

int main(void) {
    int n = 42;
    async_thread_t thr = async_run(imprime_numero, &n);
    async_join(thr);
}
```

✅ **A variável (`n`) deve permanecer viva** até que a função termine ou você deve alocar dinâmicamente (`malloc`) e liberar dentro da própria thread.


---

## Quando usar `async_join` vs. `async_detach`

| Situação                                       | Recomenda‑se   |
| ---------------------------------------------- | -------------- |
| A thread **deve** terminar antes de prosseguir | `async_join`   |
| *Larga a pista e deixa rolar* (não há sincronização)       | `async_detach` |

> **Nunca** chame `async_detach` se precisar acessar dados modificados pela thread depois; use `join`.

---