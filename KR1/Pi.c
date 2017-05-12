//
//  Pi.c
//  KR1
//
//  Created by Nikita-Mac on 23.04.17.
//  Copyright © 2017 Nikita-Mac. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <math.h>
#include <string.h>
#include <signal.h>

int flag = 1;

void Exit (int sig)
{
    flag = 0;
}

int main(int argc, const char * argv[]) {

    signal(SIGUSR2 ,Exit);
    
    double const Const = 2 * sqrt(3);
    double result = 0;
    int i = 0;
    while (flag){
        double temp = pow(-1, i) / pow(3, i);
        temp /= 2 * i + 1;
        result += temp * Const;
        i++;
    }
    
    char buf[27];
    memset(buf, '\0', 27);
    sprintf(buf,"%1.24f", result);
    
    printf("%s",buf);
    exit(0);
}
