#include <stdio.h>
#include <ctype.h>

struct Funcionario{
      char nome[100], cargo[100];
      double salarioBase, beneficios, descontos, salarioLiquido;

      void ler(){
            printf("Digite o nome do funcionario: ");
            scanf("%s[^\n]%*c", nome);
            printf("Digite o cargo do funcionario: ");
            scanf("%s[^\n]%*c", cargo);
            printf("Digite o salario base do funcionario: ");
            scanf("%lf%*c", &salarioBase);
            printf("Digite os beneficios do funcionario: ");
            scanf("%lf%*c", &beneficios);
            printf("Digite os descontos do funcionario: ");
            scanf("%lf%*c", &descontos);

            salarioLiquido = salarioBase + beneficios - descontos;
      }
      void imprimir(){
            printf("\nNome do Funcionario: %s\nCargo do Funcionario: %s\nSalario Base: R$ %.2lf\nBeneficios: R$ %.2lf\nDescontos: R$ %.2lf\nSalario Liquido: R$ %.2lf\n", nome, cargo, salarioBase, beneficios, descontos, salarioLiquido);
      }
};
struct Loja{
      Funcionario funcionarios[10];
      int f;
      int x = 0, funcCadastrados = 0;

      void ler(){
            char a = 'S';

            while (a == 'S'){
                  funcionarios[x].ler();
                  x++;
                  funcCadastrados++;

                  if(x == 10){
                        break;
                  }

                  printf("Deseja cadastrar outro funcionario? S/N\n");
                  scanf("%c%*c", &a);
                  a = toupper(a);     
                  
            }
            
      }
      void imprimir(){
            for(int i = 0;i < x;i++){
                  funcionarios[i].imprimir();
            }
      }

      void mediaSalarial(){
            double medSalarial=0, todoSalario=0;

            for(int i=0;i<x;i++){
                  todoSalario += funcionarios[i].salarioLiquido;
            }

            medSalarial = todoSalario / funcCadastrados;

            printf("\nA MEDIA SALARIAL DOS FUNCIONARIOS E: R$ %.2lf\n", medSalarial);
      }

      void maiorSalario(){
            double maior=0;
            int funcMaior;

            for(int i=0;i<x;i++){
                  if(funcionarios[i].salarioLiquido > maior){
                        maior = funcionarios[i].salarioLiquido;
                        funcMaior = i;
                  }
            }

            printf("\nO FUNCIONARIO COM MAIOR SALARIO E: \n");
            funcionarios[funcMaior].imprimir();
      }
};
int main(){
      Loja a;

      a.ler();
      a.imprimir();
      a.mediaSalarial();
      a.maiorSalario();
      
      return 0;
}