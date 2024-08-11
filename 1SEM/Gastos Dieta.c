#include <stdio.h>

int main(){
float arroz=0.5, feijao=0.260, carne=0.3, alface=0, tomate=0, cafe=0, aveia=0.03, pamendoim=0.02, tapioca=0.06, requeijao=0.03;
float pao=4, ovo=5, banana=3, suco=0.2;
float gastostotais=0;
//SAL SHOYU ARISCO 
//ENERGETICO CHA AGUA COM GAS, CHOCOLATE 70%, YOPRO


//QUANTIDADE X PREÇO POR KILO
arroz=arroz*16/3;
feijao=feijao*12/2;
carne=carne*30;
alface=alface*3;
tomate=tomate*3;
cafe=cafe*0;
aveia=aveia*0;
pamendoim=pamendoim*0;
tapioca=tapioca*0;
requeijao=requeijao*0;


//QUANTIDADE PREÇO POR X UNIDADES
pao=pao*0.39; //7.8 o pacote
ovo=ovo*1.42;
suco=suco*0;
banana=banana*0;


gastostotais+= (arroz+feijao+carne+alface+tomate+cafe+aveia+pamendoim+tapioca+requeijao+pao+ovo+suco+banana);
printf("Os gastos totais por mes nessa dieta sao de %f", 30*gastostotais);

return 0;
}
