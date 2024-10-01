/* 4. Implemente uma função que calcule a área da superfície e o volume de uma esfera de raio R. A area da superfície e o volume são dados, respectivamente, por:

A = 4 * p * R^2
V = 4/3 * p * R^3 */

#include <stdio.h>
#include <math.h>
#define P 3.14
void calcular(double *r, double *area, double *volume){
      *area = 4 * P * (pow(2,*r));
      *volume = 4/3 * P * (pow(3,*r));
}
int main(){
      double r=0, area=0, volume=0;

      scanf("%lf", &r);

      calcular(&r,&area,&volume);

      printf("AREA = %2.lf\nVOLUME = %.2lf\n", area, volume);


      return 0;
}