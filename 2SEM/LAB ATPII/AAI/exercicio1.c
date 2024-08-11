#include <stdio.h>

int main()
{
    int voto=1;
    int cand1=0, cand2=0, cand3=0, cand4=0, branco=0, nulo=0, total;
    float percent;

    while(voto>0 && voto<7){
        printf("qual seu voto?");
        scanf("%d", &voto);
    switch (voto)
    {
    case 1:cand1++ ;break;
    case 2:cand2++;break;
    case 3:cand3++;break;
    case 4:cand4++;break;
    case 5:nulo++;break;
    case 6:branco++; break;
    default:voto=8; break;
    }
    if(voto==8)  break;
    else
    voto=1;
    }
    
    
    total=cand1+cand2+cand3+cand4+nulo+branco;
    printf("\nRESULTADOS:\n");
    percent=cand1*100;
    percent=percent/total;
    printf("O candidato 1 teve %d votos, %.2f % \n",cand1, percent);
    percent=cand2*100;
    percent=percent/total;
    printf("O candidato 2 teve %d votos, %.2f %\n",cand2, percent);
    percent=cand3*100;
    percent=percent/total;
    printf("O candidato 3 teve %d votos, %.2f %\n",cand3, percent);
    percent=cand4*100;
    percent=percent/total;
    printf("O candidato 4 teve %d votos, %.2f %\n",cand4, percent);
    percent=nulo*100;
    percent=percent/total;
    printf("O nulo teve %d votos, %.2f %\n",nulo, percent);
    percent=branco*100;
    percent=percent/total;
    printf("O branco teve %d votos, %.2f%\n",branco, percent);
    if(cand1>cand2 && cand1>cand3 && cand1>cand4)
        printf("O ganhador eh o candidato 1");
    else if(cand2>cand1 && cand2>cand3 && cand2>cand4)
        printf("O ganhador eh o candidato 2");
    else if(cand3>cand1 && cand3>cand2 && cand3>cand4)
        printf("O ganhador eh o candidato 3");
    else if(cand4>cand1 && cand4>cand2 && cand4>cand1)
        printf("O ganhador eh o candidato 4");
    else 
        printf("Nova votacao");
    

return 0;
}