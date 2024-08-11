#include <stdio.h>
#include <math.h>

double op1(double vel,double temp)
{
    return vel*temp;
}
double op2(double dist,double temp)
{
    return dist/temp;
}
double op3(double dist,double vel)
{
    return dist/vel;
}
double op4(double vel,double acel,double temp)
{
    return (vel*temp)+(acel*temp*temp)/2;
}
double op5(double vel,double acel,double temp)
{
    return vel+(acel*temp);
}
double op6(double dist,double acel,double temp)
{
    double vo;
    vo = (dist - (acel * temp * temp) / 2) / temp;
    return vo;
    //return (dist/temp)-(acel*temp)/2;
}
double op7(double dist,double vel,double acel)
{
    double vf, t;
    vf = sqrt((vel * vel) + (2 * acel * dist));
    t = (vf - vel) / acel;
    return t;
    //return (sqrt((vel*vel)+(2*dist*acel))-vel)/acel;

}


int main(){
int n=0, o=0, i=0;
double num1=0, num2=0, num3=0;

scanf("%d", &n);
for(i=0;i<n;i++)
{
    scanf("%d", &o);
    
    switch (o)
    {
    case 1:scanf("%lf %lf", &num1, &num2);
    printf("%.2lf\n",op1(num1,num2));break;
    case 2:scanf("%lf %lf", &num1, &num2);
    printf("%.2lf\n",op2(num1,num2));break;
    case 3:scanf("%lf %lf", &num1, &num2);
    printf("%.2lf\n",op3(num1,num2));break;
    case 4:scanf("%lf %lf %lf", &num1, &num2, &num3);
    printf("%.2lf\n",op4(num1,num2,num3));break;
    case 5:scanf("%lf %lf %lf", &num1, &num2, &num3);
    printf("%.2lf\n",op5(num1,num2,num3));break;
    case 6:scanf("%lf %lf %lf", &num1, &num2, &num3);
    printf("%.2lf\n",op6(num1,num2,num3));break;
    case 7:scanf("%lf %lf %lf", &num1, &num2, &num3);
    printf("%.2lf\n",op7(num1,num2,num3));break;
    }
}
    return 0;
}