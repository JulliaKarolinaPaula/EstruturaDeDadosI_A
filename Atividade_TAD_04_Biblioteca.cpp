#include <stdio.h>
#include <ctype.h>

struct Livro{
      char titulo[100], autor[100];
      int paginas;

      void ler(){
            printf("Informe o TITULO do livro: ");
            scanf("%s[^\n]%*c", titulo);
            printf("Informe o AUTOR do livro: ");
            scanf("%s[^\n]%*c", autor);
            printf("Informe a quantidade de PAGINAS do livro: ");
            scanf("%d%*c", &paginas);
      }

      void imprimir(){
            printf("TITULO: %s\nAUTOR: %s\nNUMERO DE PAGINAS: %d\n", titulo, autor, paginas);
      }
};

struct Biblioteca{
      Livro livros[10];
      int x = 0, livros_cad = 0;

      void ler(){
            char a = 'S';

            while(a == 'S'){

                  if(livros_cad == 10){
                        printf("BIBLIOTECA CHEIA.");
                        break;
                  } else{
                        livros[x].ler();
                        x++;
                        livros_cad++;
                  }

                  printf("Deseja cadastrar outro livro? S/N");
                  scanf("%c%*c", &a);
                  a = toupper(a);
            }
      }

      void imprimir(){
            int maiorPag=0, pg;
            if(livros_cad == 0){
                  printf("Biblioteca Vazia.\n");
            } else {
                  for(int i = 0;i<x;i++){
                    if(livros[i].paginas > maiorPag){
                        maiorPag = livros[i].paginas;
                        pg = i;
                        }
                    livros[i].imprimir();
                  }

                   printf("O LIVRO COM MAIOR NUMERO DE PAGINAS: \n");
                   livros[pg].imprimir();
            }
      }
};
int main(){
      Biblioteca a;
      
      a.imprimir();
      a.ler();
      a.imprimir();

      return 0;
}