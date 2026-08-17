#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int* findAnagrams(char* s, char* p, int* returnSize) 
{
    *returnSize = 0;
    int* wynikowa = malloc(sizeof(int)*30000); // max rozmiar wyniku

    // najpierw ogarniamy co sie dzieje w p
    int zliczamyP[26] = {0};
    size_t sizeP = 0;
    while(p[sizeP] != '\0') 
    {
        size_t indexP = p[sizeP] - 'a';
        zliczamyP[indexP] += 1;
        sizeP += 1;
    }

    // zabezpieczenie przed s krotszym od p - jesli tak jest to wychodzimy od razu
    for(size_t o = 0; o<sizeP; o++)
    {
        if(s[o] == '\0') {return wynikowa;}
    }

    // zliczamy nasze startowe sliding window
    int i = 0, j = sizeP-1;
    int zliczamyS[26] = {0};
    for(size_t k = 0; k<sizeP; k++)
    {
        size_t indexS = s[i+k] - 'a';
        zliczamyS[indexS] += 1;
    }

    // teraz idziemy ze sliding window przez p
    while(1)
    {

        // sprawdzamy nasze okno pod katem anagramu
        int zgodne = 1;
        for(size_t l = 0; l < 26; l++)
        {
            if(zliczamyP[l]!=zliczamyS[l]) {zgodne = 0; break;} 
        }        

        if(zgodne)
        {
            wynikowa[*returnSize] = i;
            *returnSize += 1;
        }

        if (s[j+1]=='\0') {break;}
        zliczamyS[s[i] - 'a'] -= 1;
        zliczamyS[s[j + 1] - 'a'] += 1;

        // przesuwamy sie z naszym oknem dalej
        i++, j++;
    }

    wynikowa = realloc(wynikowa, (*returnSize)*sizeof(int));
    return wynikowa;
}

int main(void)
{

}