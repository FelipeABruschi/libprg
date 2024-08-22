// #include "libprg/libprg.h"
//
// no_arv *criar_no(int valor)
// {
//     no_arv *no = (no_arv *) malloc(sizeof(no_arv));
//     no->valor = valor;
//     no->esquerda = no->direita = NULL;
//     return no;
// }
// void destruir_no(no_arv *no)
// {
//     if (no != NULL)
//     {
//         destruir_no(no->esquerda);
//         destruir_no(no->direita);
//         free(no);
//     }
// }
//
//
// no_arv *inserir_valor(no_arv *raiz, int valor)
// {
//     if (raiz == NULL)
//         return criar_no(valor);
//     else if (valor < raiz->valor)
//         raiz->esquerda = inserir_valor(raiz->esquerda, valor);
//     else if (valor > raiz->valor)
//         raiz->direita = inserir_valor(raiz->direita, valor);
//
//     return raiz;
// }
//
// bool busca(no_arv *raiz, int valor)
// {
//     if (raiz == NULL) return false;
//     if (valor == raiz->valor) return true;
//     if (valor < raiz->valor) return busca(raiz->esquerda, valor);
//     return busca(raiz->direita, valor);
// }
//
// no_arv *remover_valor(no_arv *raiz, int valor)
// {
//     if (raiz == NULL)
//         return raiz;
//     if (valor < raiz->valor)
//         raiz->esquerda = remover_valor(raiz->esquerda, valor);
//     else if (valor > raiz->valor)
//         raiz->direita = remover_valor(raiz->direita, valor);
//     else {
//         // IF nó folha ou nó com um filho
//         // ELSE nó com dois filhos
//     }
//     return raiz;
// }
