#include <stdio.h>

int characterReplacement(char* s, int k) {
    
    int zliczenia[26] = {0}, i = 0, j = 0, maxFreq = 0, length, maxLength = 0;
    while(s[j] != '\0')
    {
        // zliczamy sobie kolejna napotkana litery
        int index = s[j] - 'A';
        zliczenia[index] += 1;
        if(zliczenia[index] > maxFreq) {maxFreq = zliczenia[index];}

        // tutaj ten warunek z k sprawdzajacy nam potrzebny, naprawiamy okno
        length = j - i + 1;
        if(maxFreq + k < length){zliczenia[s[i]-'A'] -= 1; i++;}

        // jak okno poprawione to sprawdzamy obecna dlugosc, jesli wieksza to aktualizujemy wynik
        length = j - i + 1;
        if(maxLength<length) {maxLength = length;}

        // rozszerzamy dalej okno
        j++;
    }

    return maxLength;
}