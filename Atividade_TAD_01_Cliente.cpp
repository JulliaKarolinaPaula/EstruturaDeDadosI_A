#include <stdio.h>
#include <ctype.h>

struct Data{
    int diaA = 19, mesA = 9, anoA = 2024;
    int diaN, mesN, anoN, idade;

    void ler_data(){
      printf("Digite o dia do nascimento: ");
      scanf("%d%*c", &diaN);
      printf("Digite o mes do nascimento: ");
      scanf("%d%*c", &mesN);
      printf("Digite o ano do nascimento: ");
      scanf("%d%*c", &anoN);
      
      idade = anoA - anoN;
      if((diaA < diaN)||(mesA < mesN)){
        idade -= 1;
      }
    }

    void imprimir_data(){
      printf("Data de Nascimento: %d/%d/%d\nIdade: %d\n", diaN, mesN, anoN, idade);
    }
};
struct Cliente{
  Data d;
  char nome[100];
  char sexo;

  void ler(){
    printf("Digite o nome: ");
    scanf("%s[^\n]%*c", nome);
    d.ler_data();
    printf("Digite o sexo: ");
    scanf("%c%*c", &sexo);
    sexo = toupper(sexo);
  }

  void imprimir(){
    printf("Nome: %s\n", nome);
    d.imprimir_data();
    printf("Sexo: %c\n", sexo);
  }

};
struct Cadastro{
    Cliente clientes[50];
    int x = 0, clients_cad = 0;

    void ler(){
      char r = 'S';
      
      while(r == 'S'){
        clientes[x].ler();
        x++;
        clients_cad++;

        if(x == 50){
            break;
        }
        printf("Deseja cadastrar outro cliente? S/N\n");
        scanf("%c%*c", &r);
        r = toupper(r);
      }
    }
    void imprimir(){
      printf("------------------------------------------\n");
      printf("Ha %d cliente(s) cadastrado(s).\n", clients_cad);
      printf("------------------------------------------\n");

      for(int i = 0;i<x;i++){
          clientes[i].imprimir();
      }
    }
};
int main(){
    Cadastro a;
    char repeat = 'S';
    
    do{
        int e;
        printf("ESCOLHA A OPCAO DESEJADA:\n");
        printf("1: Cadastrar um cliente.\n");
        printf("2: Listar clientes cadastrados.\n");
        printf("3: Sair do programa.\n");

        printf("Opcao: ");
        scanf("%d%*c", &e);

        switch (e){
          case 1: 
            a.ler();
              break;
          case 2:
            a.imprimir();
              break;
          case 3:
            return 0;
          }

      }while(repeat == 'S');

  return 0;
}