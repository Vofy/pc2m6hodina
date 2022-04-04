#include <stdio.h>
#include <stdlib.h>

int my_pow(int zaklad, int exponent)
{
    int power = 1;
    for(int j = 0; j < exponent; j++)
        power *= zaklad;

    return power;
}

int do_desitkove(char *cislo, int zaklad)
{
    int velikost = strlen(cislo);

    // Prekonvertuju znaky na jejich realne hodnoty
    for(int i = 0; i < sizeof(cislo); i++)
    {
        // Cisla
        if(48 <= cislo[i] && cislo[i] <= 57)
            cislo[i] -= 48;

        // Mala pismena
        if(97 <= cislo[i] && cislo[i] <= 122)
            cislo[i] -= 87;

        // Velka pismena
        if(65 <= cislo[i] && cislo[i] <= 90)
            cislo[i] -= 55;
    }

    int result = 0;

    // Prolezu kazdy znak od konce a vynazobim ho mocninou zakladu na hodnotu mocniny pozice znaku
    for(int znak = 0; znak < velikost; znak++)
    {
        result += cislo[velikost - znak - 1] * my_pow(zaklad, znak);
    }

    return result;
}

int main()
{
    char cislo[256];
    int zaklad;

    printf("Zadejte cislo: ");
    scanf("%s", &cislo);


    printf("Zadejte soustavu: ");
    scanf("%d", &zaklad);

    printf("\nVysledek: %d\n", do_desitkove(&cislo, zaklad));

    return 0;
}
