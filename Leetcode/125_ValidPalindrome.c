#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isPalindrome(char* s) {
    
    // co jesli pusty literał
    if(s[0]=='\0') return true;

    // znajdzmy punkt koncowy
    int j = 0;
    while(s[j]!='\0') {j++;}
    j-=1;

    // teraz lecim z klasycznym badaniem palindromu z obu stron
    int i = 0;
    while(i<j)
    {
        // skipujemy alphanumeric
        while(i<j && isalnum(s[j])==0) {j--;}
        while(i<j && isalnum(s[i])==0) {i++;}

        // porownujemy odpowiednie litery, uprzednio przekonwertowawszy na lowercase
        if(tolower(s[i])!=tolower(s[j])) {return false;}
        i++, j--;
    }

    return true;

}