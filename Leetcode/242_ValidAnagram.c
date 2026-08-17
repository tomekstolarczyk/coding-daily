#include <stdio.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    
    int liczydloS[26] = {0};

    size_t i = 0;
    while(s[i]!=0)
    {
        int index = s[i] - 'a';
        liczydloS[index] += 1;
        i+=1;
    }

    int liczydloT[26] = {0};

    size_t j = 0;
    while(t[j]!=0)
    {
        int index = t[j] - 'a';
        liczydloT[index] += 1;
        j+=1;
    }

    for(size_t k = 0; k<26; k++)
    {
        if(liczydloS[k]!=liczydloT[k]) {return false;}
    }

    return true;
}

