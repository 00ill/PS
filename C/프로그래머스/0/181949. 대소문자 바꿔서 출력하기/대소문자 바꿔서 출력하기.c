#include <stdio.h>
#include <ctype.h>
#define LEN_INPUT 21

int main(void) {
    char s1[LEN_INPUT];
    scanf("%s", s1);
    char *p = s1;
    while(*p)
    {
        if('a' <= *p && *p <= 'z') *p = toupper(*p);
        else *p = tolower(*p);
        p++;
    }
    printf("%s", s1);
    return 0;
}
