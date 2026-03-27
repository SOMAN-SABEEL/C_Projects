#include<stdio.h>
#include<math.h>
void printmenu();
double division(double, double);
double modulus(int, int);
int main(){
    int option;
    double first, second, result;
    while(1) {
        printmenu();
        scanf("%d", &option);

        if(option  == 7){
            break;
        }
        if(option < 1 || option > 7){
            fprintf(stderr, "Invalid Menu Option.");
            continue;
        }
        printf("\n Please enter the first number : ");
        scanf("%lf", &first);
        printf("Now, enter the second number : ");
        scanf("%lf", &second);

        switch (option)
        {
        case 1: // Addition
            result = first + second;
            break;
        case 2: // Subtract
            result = first - second;
            break;
        case 3: // Multiplication
            result = first * second;
            break;
        case 4: // Divide 
            result = division(first, second);
            break;
        case 5:  // Modulo
            result =  modulus(first, second);
            break;
        case 6: // Power
            result = pow(first, second);
            break;
        default:
            break;
        }
        if(!isnan(result)){
            printf("\nResult of operation is : %.2f", result);
        }
        
        
    }
    
    return 0;
}

void printmenu(){
    printf("\n\n---------------------------------------");
    printf("\n Welcome to the Simple Calculator \n");
    printf("\n Choose one of the following options:");
    printf("\n 1. Addition");
    printf("\n 2. Subtraction");
    printf("\n 3. Multiplication");
    printf("\n 4. Division"); 
    printf("\n 5. Modulus");
    printf("\n 6. Power");
    printf("\n 7. Exit");
    printf("\n Enter your choice: ");
}

double division(double a, double b){

    if (b == 0)
    {
        fprintf(stderr , "\nDivisor can't be 0");
        return NAN;
    } else {
         return a / b;
    } 
}


double modulus(int a, int b){

        if (b == 0)
    {
        fprintf(stderr , "\nDivisor can't be 0");
        return NAN;
    } else {
         return a % b;
    }

}