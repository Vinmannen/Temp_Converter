#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    char flag;
    char *conv_from = "";
    char *conv_to = "";
    float value;

    puts("\n");
    puts("-f [char]     Temperature to convert from.");
    puts("-t [char]     Temperature to convert to.");
    puts("-v [float]    Value of the conversion.\n");
    puts("Only first letter of the temperature allowed.");
    puts("Supported temperatures: (c)elcius, (f)ahrenheit");
    puts("Example: ./main -f f -t c -v 20\n");


    while ((flag = getopt(argc, argv,"f:t:v:" )) != -1)
        switch(flag){
            case 'f':
                conv_from = optarg;
            case 't':
                conv_to = optarg;
            case 'v':
                value = atoi(optarg);
        }

    argc -= optind;
    argv += optind;

    if(!value){
        printf("Must enter a valid (v)alue (float or integer).\n");
        exit(1);
    }

    if((*conv_from == 'f') && (*conv_to == 'c')){
        float f_to_c =  (value - 32) * .5556;
        printf("%1.2f°F is %1.2f°C\n", value, f_to_c);
    }

    if((*conv_from == 'c') && (*conv_to == 'f')){
        float c_to_f =   (value * 1.8) + 32;
        printf("%1.2f°C is %1.2f°F\n", value, c_to_f);
    } 

    return 0;
}