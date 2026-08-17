#include <stdio.h>

int lengthOfLongestSubstring(char* s) {
    
    int zliczenia[128]={0};

    size_t i = 0, j = 0, dlugosc = 0, maxDlugosc = 0;

    while(s[j]!='\0')
    {
        zliczenia[s[j]] += 1;
        dlugosc += 1;

        // jak spotkamy duplikat to czyscimy
        if(zliczenia[s[j]] > 1) 
        {
            // czyscimy wszystko sprzed duplikatu
            while(s[j]!=s[i]) 
            {
                zliczenia[s[i]] -= 1;
                i++;
                dlugosc--;
            }

            // czyscimy sam duplikat
            zliczenia[s[i]] -= 1;
            dlugosc--;
            i++;
        }

        if(maxDlugosc < dlugosc) {maxDlugosc = dlugosc;}

        j++;
        
    }

    return maxDlugosc;

}

int main(void)
{
    char s[] = {'a','b','c','d','e','d','\0'};
    int len = lengthOfLongestSubstring(s); // expected 5
    printf("%d", len);
    return 0;
}