#include <stdio.h>
#include <ctype.h>

int main(){
    /*
        Declaração das variáveis das duas cartas que contém as suas propriedades.
    */
    char letrapais1 = 'A', letrapais2 = 'B';                                    //Declaração da variável da Letra do País.    
    char* codigopais1 = "A01";                                                  //Declaração da variável do Código do País da Carta 1.    
    char* codigopais2 = "B03";                                                  //Declaração da variável do Código do País da Carta 2.                  
    char* nomepais1 = "Brasil";                                                 //Declaração da variável do Nome do País da Carta 1.
    char* nomepais2 = "Argentina";                                              //Declaração da variável do Nome do País da Carta 2.
    unsigned long int populacaopais1 = 211100000, populacaopais2 = 45540000;    //Declaração da variável da População do País.
    float areapais1 = 8510000, areapais2 = 2780000;                             //Declaração da variável da Área em km² do País.
    float pibpais1 = 2174000000000, pibpais2 = 646100000000;                    //Declaração da variável do PIB do País.
    int pontosturisticospais1 = 35, pontosturisticospais2 = 28;                 //Declaração da variável da Quantidade de Pontos Turísticos do País.
    float densidadedemograficapais1, densidadedemograficapais2;                 //Declaração da variável da Densidade Demográfica do País.
    float pibpercapitapais1, pibpercapitapais2;                                 //Declaração da variável do PIB per Capita do País.
    long long int pontuacaofinal1, pontuacaofinal2;                             //Declaração da variável da Pontuação Final das Cartas.

    densidadedemograficapais1 = (float)(populacaopais1 / areapais1);            //Calcula a Densidade Demográfica do País da Carta 1.
    densidadedemograficapais2 = (float)(populacaopais2 / areapais2);            //Calcula a Densidade Demográfica do País da Carta 2.
    pibpercapitapais1 = (float)(pibpais1 / populacaopais1);                     //Calcula o PIB per Capita do País da Carta 1.
    pibpercapitapais2 = (float)(pibpais2 / populacaopais2);                     //Calcula o PIB per Capita do País da Carta 2.

    /*
        Exibir as Propriedades da Carta 1.
    */
    printf("Carta 1: \n"); //Informar a Carta a ter as propriedades informadas.
    printf("Estado: %c\n", letrapais1); //Exibir o Estado da Carta 1.
    printf("Código: %s\n", codigopais1); //Exibir o Código da Carta 1.
    printf("Nome do País: %s\n", nomepais1); //Exibir o Nome do País da Carta 1.
    printf("População: %lu\n", populacaopais1); //Exibir a População do País da Carta 1.
    printf("Área: %.0f km²\n", areapais1); //Exibir a Área em km² do País da Carta 1.
    printf("PIB: R$ %.2f\n", pibpais1); //Exibir o PIB do País da Carta 1.
    printf("Número de Pontos Turísticos: %d\n", pontosturisticospais1); //Exibir o Número de Pontos Turísticos do País da Carta 1.
    printf("Densidade Demográfica: %.2f hab/km²\n", densidadedemograficapais1); //Exibir a Densidade Populacional do País da Carta 1.
    printf("PIB per Capita: %.2f reais\n\n", pibpercapitapais1); //Exibir o PIB per Capita da País do Carta 1.

    /*
        Exibir as Propriedades da Carta 2.
    */
    printf("Carta 2: \n"); //Informar a Carta a ter as propriedades informadas.
    printf("Estado: %c\n", letrapais2); //Exibir o Estado da Carta 2.
    printf("Código: %s\n", codigopais2); //Exibir o Código da Carta 2.
    printf("Nome do País: %s\n", nomepais2); //Exibir o Nome do País da Carta 2.
    printf("População: %lu\n", populacaopais2); //Exibir a População do País da Carta 2.
    printf("Área: %.0f km²\n", areapais2); //Exibir a Área em km² do País da Carta 2.
    printf("PIB: R$ %.2f\n", pibpais2); //Exibir o PIB do País da Carta 2.
    printf("Número de Pontos Turísticos: %d\n", pontosturisticospais2); //Exibir o Número de Pontos Turísticos do País da Carta 2.
    printf("Densidade Demográfica: %.2f hab/km²\n", densidadedemograficapais2); //Exibir a Densidade Demográfica do País da Carta 2.
    printf("PIB per Capita: %.2f reais\n\n", pibpercapitapais2); //Exibir o PIB per Capita do País da Carta 2.

    /*
        Menu de Comparação do Primeiro Atributo das Cartas a ser comparado.
    */
    char opcao1;
    printf("Menu de Comparação do Primeiro Atributo:\n");
    printf("H. População\n");
    printf("A. Área\n");
    printf("P. PIB\n");
    printf("T. Número de pontos turísticos\n");
    printf("D. Densidade Demográfica\n");
    scanf(" %c", &opcao1);
    opcao1 = toupper(opcao1);
    switch (opcao1)
    {
    case 'H': //Comparar a População dos Países.
        printf("### População dos Países ###\nCarta 1, %s: %lu\nCarta 2, %s: %lu\n", nomepais1, populacaopais1, nomepais2, populacaopais2);
        if(populacaopais1 > populacaopais2){
            printf("Carta 1 venceu!\n");
        }else if(populacaopais2 > populacaopais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 = populacaopais1;
        pontuacaofinal2 = populacaopais2;
        break;
    case 'A': //Comparar a Área em km² População dos Países.
        printf("### Área em km² dos Países ###\nCarta 1, %s: %.0f km²\nCarta 2, %s: %.0f km²\n", nomepais1, areapais1, nomepais2, areapais2);
        if(areapais1 > areapais2){
            printf("Carta 1 venceu!\n");
        }else if(areapais2 > areapais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 = (long long int)(areapais1);
        pontuacaofinal2 = (long long int)(areapais2);
        break;
    case 'P': //Comparar o PIB dos Países.
        printf("### PIB dos Países ###\nCarta 1, %s: R$ %.2f\nCarta 2, %s: R$ %.2f\n", nomepais1, pibpais1, nomepais2, pibpais2);
        if(pibpais1 > pibpais2){
            printf("Carta 1 venceu!\n");
        }else if(pibpais2 > pibpais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 = (long long int)(pibpais1);
        pontuacaofinal2 = (long long int)(pibpais2);        
        break;
    case 'T': //Comparar a Quantidade de Pontos Turísticos dos Países.
        printf("### Quantidade de Pontos Turísticos dos Países ###\nCarta 1, %s: %d\nCarta 2, %s: %d\n", nomepais1, pontosturisticospais1, nomepais2, pontosturisticospais2);
        if(pontosturisticospais1 > pontosturisticospais2){
            printf("Carta 1 venceu!\n");
        }else if(pontosturisticospais2 > pontosturisticospais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 = pontosturisticospais1;
        pontuacaofinal2 = pontosturisticospais2;
        break;
    case 'D': //Comparar a Densidade Demográfica dos Países.
        printf("### Densidade Demográfica dos Países ###\nCarta 1, %s: %.2f hab/km²\nCarta 2, %s: %.2f hab/km²\n", nomepais1, densidadedemograficapais1, nomepais2, densidadedemograficapais2);
        if(densidadedemograficapais1 < densidadedemograficapais2){
            printf("Carta 1 venceu!\n");
        }else if(densidadedemograficapais2 < densidadedemograficapais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 = densidadedemograficapais1;
        pontuacaofinal2 = densidadedemograficapais2;
        break;
    default: //Exibir Mensagem de Opção Inválida.
        printf("Opção inválida!");
        break;
    }

    /*
        Menu de Comparação do Segundo Atributo das Cartas a ser comparado.
    */
    char opcao2;
    printf("Menu de Comparação do Segundo Atributo:\n");
    opcao1 != 'H' ? printf("H. População\n") : (void)0;
    opcao1 != 'A' ? printf("A. Área\n") : (void)0;
    opcao1 != 'P' ? printf("P. PIB\n") : (void)0;
    opcao1 != 'T' ? printf("T. Número de pontos turísticos\n") : (void)0;
    opcao1 != 'D' ? printf("D. Densidade Demográfica\n") : (void)0;
    scanf(" %c", &opcao2);
    opcao2 = toupper(opcao2);
    opcao2 = opcao1 == opcao2 ? 'Z' : opcao2;
    switch (opcao2)
    {
    case 'H': //Comparar a População dos Países.
        printf("### População dos Países ###\nCarta 1, %s: %lu\nCarta 2, %s: %lu\n", nomepais1, populacaopais1, nomepais2, populacaopais2);
        if(populacaopais1 > populacaopais2){
            printf("Carta 1 venceu!\n");
        }else if(populacaopais2 > populacaopais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 += populacaopais1;
        pontuacaofinal2 += populacaopais2;
        break;
    case 'A': //Comparar a Área em km² População dos Países.
        printf("### Área em km² dos Países ###\nCarta 1, %s: %.0f km²\nCarta 2, %s: %.0f km²\n", nomepais1, areapais1, nomepais2, areapais2);
        if(areapais1 > areapais2){
            printf("Carta 1 venceu!\n");
        }else if(areapais2 > areapais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 += (long long int)(areapais1);
        pontuacaofinal2 += (long long int)(areapais2);
        break;
    case 'P': //Comparar o PIB dos Países.
        printf("### PIB dos Países ###\nCarta 1, %s: R$ %.2f\nCarta 2, %s: R$ %.2f\n", nomepais1, pibpais1, nomepais2, pibpais2);
        if(pibpais1 > pibpais2){
            printf("Carta 1 venceu!\n");
        }else if(pibpais2 > pibpais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 += (long long int)(pibpais1);
        pontuacaofinal2 += (long long int)(pibpais2);        
        break;
    case 'T': //Comparar a Quantidade de Pontos Turísticos dos Países.
        printf("### Quantidade de Pontos Turísticos dos Países ###\nCarta 1, %s: %d\nCarta 2, %s: %d\n", nomepais1, pontosturisticospais1, nomepais2, pontosturisticospais2);
        if(pontosturisticospais1 > pontosturisticospais2){
            printf("Carta 1 venceu!\n");
        }else if(pontosturisticospais2 > pontosturisticospais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 += pontosturisticospais1;
        pontuacaofinal2 += pontosturisticospais2;
        break;
    case 'D': //Comparar a Densidade Demográfica dos Países.
        printf("### Densidade Demográfica dos Países ###\nCarta 1, %s: %.2f hab/km²\nCarta 2, %s: %.2f hab/km²\n", nomepais1, densidadedemograficapais1, nomepais2, densidadedemograficapais2);
        if(densidadedemograficapais1 < densidadedemograficapais2){
            printf("Carta 1 venceu!\n");
        }else if(densidadedemograficapais2 < densidadedemograficapais1){
            printf("Carta 2 venceu!\n");
        }else{
            printf("Empatou!\n");
        }
        pontuacaofinal1 -= densidadedemograficapais1;
        pontuacaofinal2 -= densidadedemograficapais2;
        break;
    default: //Exibir Mensagem de Opção Inválida.
        printf("Opção inválida!");
        break;
    }

    /*
        Faz a comparação da Pontuação Final das Cartas, determinando a carta vencedora da rodada.
    */
    printf("### Pontuação Final ###\n");
    if(pontuacaofinal1 > pontuacaofinal2){
        printf("Carta 1 (%s) venceu essa rodada! Carta 1 (%s) teve %lld pontos e Carta 2 (%s) %lld pontos!\n", nomepais1, nomepais1, pontuacaofinal1, nomepais2, pontuacaofinal2);
    }else if(pontuacaofinal1 < pontuacaofinal2){
        printf("Carta 2 (%s) venceu essa rodada! Carta 1 (%s) teve %lld pontos e Carta 2 (%s) %lld pontos!\n", nomepais2, nomepais1, pontuacaofinal1, nomepais2, pontuacaofinal2);
    }else{
        printf("Empate! Carta 1 (%s) teve %lld pontos e Carta 2 (%s) %lld pontos!\n", nomepais1, pontuacaofinal1, nomepais2, pontuacaofinal2);
    }
}