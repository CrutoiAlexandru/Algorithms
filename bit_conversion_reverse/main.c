#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int binToInt(int n){
    int sum = 0;
    int counter = 0;

    while(n){
        sum = (n%10)*pow(2, counter) + sum;
        counter ++;
        n = n/10;
    }

    return sum;
}

double binToDouble(double n){
    int counter = 0;
    double sum = 0;

    for(int i = 0; i < 8; i ++){
        if(n*10 >= 1.2){
            sum = (1)*pow(2, -counter) + sum;
            n = n - 1;
            counter ++;
            n = n*10;
        }else{
            sum = ((int)n)*pow(2, -counter) + sum;
            n = n - (int)n;
            counter ++;
            n = n*10;
        }
        
        printf("%f \n", n);
    }

    return sum;
}

void main(){
    int binar[32];
    int exponent = 0;
    int pi = 0;
    double pz = 0;
    int counter = 1, counter1 = 0;
    double sum;

    for(int i = 0; i < 32; i++){
        scanf("%d", &binar[i]);
    }

    int k = 0;

    for(int i = 8; i > 0; i--){
        exponent = (binar[i])*pow(2, k) + exponent;
        k++;
    }

    printf("%d \n", exponent);

    exponent = exponent - 127;

    printf("%d \n", exponent);

    for(int i = 9 + exponent; i < 32; i++){
        pz = binar[i]* pow(2, -counter) + pz;
        counter++;
    }

    printf("%f \n", pz);

    for(int i = 9 + exponent - 1; i > 8 ; i--){
        pi = binar[i]*pow(2, counter1) + pi;
        counter1++;
    }

    if(pi == 0){
        pz = pz + pow(2, -1);
    }

    pi = pi + pow(2, exponent);

    sum = pi + pz;

    if(binar[0] == 1){
        sum = -sum;
    }

    printf("%f", sum);
}