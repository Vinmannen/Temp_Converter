#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    //Declaring variables
    char flag; //Variable for getopt so it can be used in a switch
    char *conv_from; //Pointer to the "from" character
    char *conv_to; //Pointer to the "to" character
    float value; //Conversion value
    
    //Some information about the usage
    puts("\n");
    puts("-f [char]     Temperature to convert from.");
    puts("-t [char]     Temperature to convert to.");
    puts("-v [float]    Value of the conversion.\n");
    puts("Only first letter of the temperature allowed.");
    puts("Supported temperatures: (c)elcius, (f)ahrenheit");
    puts("Example: ./main -f f -t c -v 20\n");


    //Read arguments while flag is not -1
    //Go through each "optarg" and add it to the variables
    while ((flag = getopt(argc, argv,"f:t:v:" )) != -1) //":" to make it required
        switch(flag){ //a switch to handle each argument
            case 'f':
                conv_from = optarg;
            case 't':
                conv_to = optarg;
            case 'v':
                value = atoi(optarg);
        }

    //Skip past arguments to make option an option and input an input
    argc -= optind;
    argv += optind;

    //If no, or an invalid, value entered, return an error
    if(!value){
        printf("Must enter a valid (v)alue (float or integer).\n");
        exit(1);
    }

    //-f = f and -t = c do...
    if((*conv_from == 'f') && (*conv_to == 'c')){
        float f_to_c =  (value - 32) * .5556;
        printf("%1.2f°F is %1.2f°C\n", value, f_to_c);
    }

    //-f = c and -t = f do...
    else if((*conv_from == 'c') && (*conv_to == 'f')){
        float c_to_f =   (value * 1.8) + 32;
        printf("%1.2f°C is %1.2f°F\n", value, c_to_f);
    }

    //If no valid value are given, return an error message
    else{
        printf("Invalid or unsupported value entered. Check your input and try again.\n");
        exit(1);
    }

    //Standard return 0 if everything went OK
    return 0;
}
