/*
Note:
1. Untuk input integer diganti menjadi 'inputint(&variabel, input);'
    Penggunaan:
    int n;
    inputint(&n, input);

2. Untuk input float diganti menjadi 'inputfloat(&variabel, input);'
    Penggunaan:
    float a;
    inputfloat(&a, input);

3. Syntax gets() diganti menjadi 'inputstring(variabel, ukuran array)'
    Penggunaan:
    char kalimat[100];
    - inputstring(kalimat, 100);
    - inputstring(kalimat, sizeof(kalimat));
    (Pilih salah satu saja)
*/

/*
Kenapa gak pake scanf() dan gets()?
1. http://sekrit.de/webdocs/c/beginners-guide-away-from-scanf.html
2. https://stackoverflow.com/questions/1694036/why-is-the-gets-function-so-dangerous-that-it-should-not-be-used
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

char input[1024];
int inputint(int *a, char buf[1024]) //Pengganti scanf untuk integer
{
    int success; // flag for successful conversion

    do
    {
        if (!fgets(buf, 1024, stdin))
        {
            // reading input failed:
            return 1;
        }

        // have some input, convert it to integer:
        char *endptr;

        errno = 0; // reset error number
        *a = strtol(buf, &endptr, 10);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large. Repeat again\n");
            success = 0;
        }
        else if (endptr == buf)
        {
            // no character was read
            success = 0;
        }
        else if (*endptr && *endptr != '\n')
        {
            // *endptr is neither end of string nor newline,
            // so we didn't convert the *whole* input
            success = 0;
        }
        else
        {
            success = 1;
        }
    } while (!success); // repeat until we got a valid number
    return *a;
}

float inputfloat(float *a, char buf[1024]) //Pengganti scanf untuk float
{
    int success; // flag for successful conversion

    do
    {
        if (!fgets(buf, 1024, stdin))
        {
            // reading input failed:
            return 1;
        }

        // have some input, convert it to integer:
        char *endptr;

        errno = 0; // reset error number
        *a = strtof(buf, &endptr);
        if (errno == ERANGE)
        {
            printf("Sorry, this number is too small or too large. Repeat again\n");
            success = 0;
        }
        else if (endptr == buf)
        {
            // no character was read
            success = 0;
        }
        else if (*endptr && *endptr != '\n')
        {
            // *endptr is neither end of string nor newline,
            // so we didn't convert the *whole* input
            success = 0;
        }
        else
        {
            success = 1;
        }
    } while (!success); // repeat until we got a valid number
    return *a;
}

void inputstring(char *string, int length) // Pengganti gets()
{
    int x = 0;
    fgets(string, length, stdin);
    while (*string)
    {
        if (*string == '\n')
        {
            *string = '\0';
            return;
        }
        x++;
        if (x == length)
        {
            *string = '\0';
            return;
        }
        string++;
    }
}

// Ngodingnya disini
int main(void){
    float n;
    int a;
    char d[100];
        printf("Input Float: "); inputfloat(&n, input);
        printf("Input Int: "); inputint(&a, input);
        printf("Input String: "); inputstring(d, sizeof(d));
        printf("%.2f\n", n);
        printf("%d\n", a);
        printf("%s\n", d);
}