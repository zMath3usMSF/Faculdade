#include <stdio.h>

int main(){
    /*
        Declaração das variáveis das duas cartas que contém as suas propriedades.
    */
    char letraestado1, letraestado2;                                    //Declaração da variável da Letra do Estado.
    char codigocarta1[4], codigocarta2[4];                              //Declaração da variável do Código da Carta.
    char nomecidade1, nomecidade2;                              //Declaração da variável do Nome da Cidade.
    unsigned long int cidadepopulacao1, cidadepopulacao2;               //Declaração da variável da População da Cidade.
    float cidadearea1, cidadearea2;                                     //Declaração da variável da Área em km² da Cidade.
    float cidadepib1, cidadepib2;                                       //Declaração da variável do PIB da Cidade.
    int cidadepontosturisticos1, cidadepontosturisticos2;               //Declaração da variável da Quantidade de Pontos Turísticos da Cidade.
    float cidadedensidadepopulacional1, cidadedensidadepopulacional2;   //Declaração da variável da Densidade Populacional da Cidade.
    float cidadepibpercapita1, cidadepibpercapita2;                     //Declaração da variável da PIB per Capita da Cidade.
    float cidadesuperpoder1, cidadesuperpoder2;                         //Declaração da variável do Super Poder da Cidade.

    /*
        Receber Informações das Propriedades da Carta 1 e armezena-las em suas respectivas variáveis.
    */
    printf("Digite a Letra do Estado da Carta 1 (Uma Letra de 'A' a 'H')): ");
    scanf(" %c", &letraestado1); //Receber a Letra do Estado da Carta 1 e Armazenar em sua variável.

    printf("Digite o Código da Carta da Carta 1 (A Letra do Estado seguida de um número de 01 a 04, ex: A01, B03)): ");
    scanf(" %s", codigocarta1); //Receber o Código da Carta da Carta 1 e Armazenar em sua variável.

    printf("Digite o Nome da Cidade da Carta 1: ");
    scanf(" %s", nomecidade1); //Receber o Nome da Cidade da Carta 1 e Armazenar em sua variável.

    printf("Digite a População da Cidade da Carta 1: ");
    scanf(" %lu", &cidadepopulacao1); //Receber a População da Carta 1 e Armazenar em sua variável.

    printf("Digite a Área em km² da Cidade da Carta 1: ");
    scanf(" %f", &cidadearea1); //Receber a Área em km² da Carta 1 e Armazenar em sua variável.

    printf("Digite o PIB da Cidade da Carta 1: ");
    scanf(" %f", &cidadepib1); //Receber o PIB da Carta 1 e Armazenar em sua variável.

    printf("Digite a Quantidade de Pontos Turísticos da Cidade da Carta 1: ");
    scanf(" %d", &cidadepontosturisticos1); //Receber a Quantidade de Pontos Turísticos da Carta 1 e Armazenar em sua variável.

    cidadedensidadepopulacional1 = (float)(cidadepopulacao1 / cidadearea1); //Calcula a Densidade Populacional da Cidade da Carta 1.
    cidadepibpercapita1 = (float)(cidadepib1 / cidadepopulacao1);           //Calcula a PIB per Capita da Cidade da Carta 1.

    cidadesuperpoder1 = (float)((cidadepopulacao1 + cidadearea1 + cidadepib1 + cidadepibpercapita1) - (cidadedensidadepopulacional1)); //Calcular o Super Poder da Cidade da Carta 1.

    /*
        Receber Informações das Propriedades da Carta 2 e armezena-las em suas respectivas variáveis.
    */
    printf("Digite a Letra do Estado da Carta 2 (Uma Letra de 'A' a 'H')): ");
    scanf(" %c", &letraestado2); //Receber a Letra do Estado da Carta 2 e Armazenar em sua variável.
   
    printf("Digite o Código da Carta da Carta 2 (A Letra do Estado seguida de um número de 01 a 04, ex: A01, B03)): ");
    scanf(" %s", codigocarta2); //Receber o Código da Carta da Carta 2 e Armazenar em sua variável.

    printf("Digite o Nome da Cidade da Carta 2: ");
    scanf(" %s", nomecidade2); //Receber o Nome da Cidade da Carta 2 e Armazenar em sua variável.

    printf("Digite a População da Cidade da Carta 2: ");
    scanf(" %lu", &cidadepopulacao2); //Receber a População da Cidade da Carta 2 e Armazenar em sua variável.

    printf("Digite a Área em km² da Cidade da Carta 2: ");
    scanf(" %f", &cidadearea2); //Receber a Área em km² da Carta 2 e Armazenar em sua variável.

    printf("Digite o PIB da Cidade da Carta 2: ");
    scanf(" %f", &cidadepib2); //Receber o PIB da Carta 2 e Armazenar em sua variável.

    printf("Digite a Quantidade de Pontos Turísticos da Cidade da Carta 2: ");
    scanf(" %d", &cidadepontosturisticos2); //Receber a Quantidade de Pontos Turísticos da Carta 2 e Armazenar em sua variável.

    cidadedensidadepopulacional2 = (float)(cidadepopulacao2 / cidadearea2); //Calcula a Densidade Populacional da Cidade da Carta 2.
    cidadepibpercapita2 = (float)(cidadepib2 / cidadepopulacao2);           //Calcula a PIB per Capita da Cidade da Carta 2.

    cidadesuperpoder2 = (float)((cidadepopulacao2 + cidadearea2 + cidadepib2 + cidadepibpercapita2) - (cidadedensidadepopulacional2)); //Calcular o Super Poder da Cidade da Carta 2.

    /*
        Exibir as Propriedades da Carta 1.
    */
    printf("Carta 1: \n"); //Informar a Carta a ter as propriedades informadas.
    printf("Estado: %c\n", letraestado1); //Exibir o Estado da Carta 1.
    printf("Código: %s\n", codigocarta1); //Exibir o Código da Carta 1.
    printf("Nome da Cidade: %s\n", nomecidade1); //Exibir o Nome da Cidade da Carta 1.
    printf("População: %lu\n", cidadepopulacao1); //Exibir a População da Cidade da Carta 1.
    printf("Área: %.2f km²\n", cidadearea1); //Exibir a Área em km² da Cidade da Carta 1.
    printf("PIB: %.2f bilhões de reais\n", cidadepib1); //Exibir o PIB da Cidade da Carta 1.
    printf("Número de Pontos Turísticos: %d\n", cidadepontosturisticos1); //Exibir o Número de Pontos Turísticos da Cidade da Carta 1.
    printf("Densidade Populacional: %.2f hab/km²\n", cidadedensidadepopulacional1); //Exibir a Densidade Populacional da Cidade da Carta 1.
    printf("PIB per Capita: %.2f reais\n\n", cidadepibpercapita1); //Exibir o PIB per Capita da Cidade da Carta 1.

    /*
        Exibir as Propriedades da Carta 2.
    */
    printf("Carta 2: \n"); //Informar a Carta a ter as propriedades informadas.
    printf("Estado: %c\n", letraestado2); //Exibir o Estado da Carta 2.
    printf("Código: %s\n", codigocarta2); //Exibir o Código da Carta 2.
    printf("Nome da Cidade: %s\n", nomecidade2); //Exibir o Nome da Cidade da Carta 2.
    printf("População: %lu\n", cidadepopulacao2); //Exibir a População da Cidade da Carta 2.
    printf("Área: %.2f km²\n", cidadearea2); //Exibir a Área em km² da Cidade da Carta 2.
    printf("PIB: %.2f bilhões de reais\n", cidadepib2); //Exibir o PIB da Cidade da Carta 2.
    printf("Número de Pontos Turísticos: %d\n", cidadepontosturisticos2); //Exibir o Número de Pontos Turísticos da Cidade da Carta 2.
    printf("Densidade Populacional: %.2f hab/km²\n", cidadedensidadepopulacional2); //Exibir a Densidade Populacional da Cidade da Carta 2.
    printf("PIB per Capita: %.2f reais\n\n", cidadepibpercapita2); //Exibir o PIB per Capita da Cidade da Carta 2.

    /*
        Fazer a Comparação entre a População das Cartas.
    */
    printf("Comparação de cartas (Atributo: População):\n"); //Informar que a Comparação da População entre as cartas.
    printf("Carta 1 - %s: %lu.\n", nomecidade1, cidadepopulacao1); //Informar a População da Carta 1.
    printf("Carta 2 - %s: %lu.\n", nomecidade2, cidadepopulacao2); //Informar a População da Carta 2.
    if(cidadepopulacao1 > cidadepopulacao2){
        printf("Resultado: Carta 1 (%s) venceu!\n", nomecidade1);  //Informar que a Carta 1 Venceu pela População.
    }else{
        printf("Resultado: Carta 2 (%s) venceu!\n", nomecidade2);  //Informar que a Carta 2 Venceu pela População.
    }
}