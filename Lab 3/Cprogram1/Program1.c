/*
Filename: Program1.c
Date: 02/20/2023
Author: Kaitlyn Clements
KUID: 3072622
Lab: 3
Last Modified: 02/20/2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void month(int numMonth){
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf(" %-12s", months[numMonth]);
}

void salesReport(float monthReport[], int length){
    printf(" Month \t Sales\n");
    for(int i=0; i<length; ++i){
        month(i);
        printf("$%.2f\n", monthReport[i]);
    }
}

void salesSummary(float monthReport[], int length){
    float min = monthReport[0];
    int minIndex = 0;
    float max = monthReport[0];
    int maxIndex = 0;
    float total = 0;

    for(int i = 1; i<length; ++i){
        if (monthReport[i] < min){
            min = monthReport[i];
            minIndex = i;
        }
        if (monthReport[i] > max){
            max = monthReport[i];
            maxIndex = i;
        }
        total = total+monthReport[i];
    }
    float avg = total/length;

    printf("Minimum sale: $%.2f (", min);
    month(minIndex);
    printf(")\n");
    printf("Maximum sale: $%.2f (", max);
    month(maxIndex);
    printf(")\n");
    printf("Average sale: $%.2f\n", avg);
}

void sixMonthMovingAvg(float monthReport[], int length){
    float sum = 0.0;
    printf(" Month \t Sales\n");
    for (int i = 0; i < length; ++i){
        month(i);
        for (int j = i; j<i+6 && j < length; ++j){
            sum = sum + monthReport[j];
        }
        printf("$%.2f\n", sum/6);
        sum = 0.0;
    }
}

void salesReportFromHighestToLowest(float monthReport[], int length){
    float sortedSales[12];
    int numMonth[12];
    for(int i = 0; i < length; ++i){
        sortedSales[i] = monthReport[i];
        numMonth[i] = i;
    }
    for(int i = 0; i < length; ++i){
        for (int j = i+1; j<length; ++j){
            if(sortedSales[i] < sortedSales[j]){
                float temp = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = temp; 
                int tempNum = numMonth[i];
                numMonth[i] = numMonth[j];
                numMonth[j] = tempNum;
            }
        }
    }
    printf(" Month \t Sales\n");
    for(int i = 0; i < length; ++i){
        month(numMonth[i]);
        printf("$%.2f\n", sortedSales[i]);
    }
}

int main(){
    FILE*myfile;
    myfile = fopen("sample.txt", "r");
    if (myfile == NULL){
        printf("Unable to open file\n");
        return 1;
    }

    float sales[12] = {0};

    for(int i = 0; i<12; i++){
        fscanf(myfile, "%f", &sales[i]);
    }

    printf("\nMonthly sales report for 2022: \n\n");
    salesReport(sales, 12);
    printf("\nSales Summary: \n\n");
    salesSummary(sales, 12);
    printf("\nSix Month Moving Average Report: \n\n");
    sixMonthMovingAvg(sales, 12);
    printf("\nSales Report from Highest to Lowest: \n\n");
    salesReportFromHighestToLowest(sales, 12);
    fclose(myfile);
    return 0;
}
