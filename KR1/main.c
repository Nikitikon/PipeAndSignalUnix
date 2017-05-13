//
//  main.c
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

void alar (int sig)
{
    return;
}

int main(int argc, const char * argv[]) {
    signal(SIGUSR1, alar);
    char* x = "1";
    
    int fdPi[2];
    int fdExp[2];
    
    pipe(fdPi);
    pipe(fdExp);
    
    char bufPi[27];
    char bufExp[27];
    
    int pidPi;
    int pidExp;
    
    if ((pidPi = fork()) == 0) {
        signal(SIGUSR1, alar);
        kill(getppid(), SIGUSR1);
        pause();
        dup2(fdPi[1], 1);
        execl("/Users/nikita-mac/Desktop/UNIX/KR1/KR1/Pi", "/Users/nikita-mac/Desktop/UNIX/KR1/KR1/Pi", NULL);
        perror("Exec Pi");
        exit(0);
    }
    pause();
    if ((pidExp = fork()) == 0) {
        signal(SIGUSR1, alar);
        kill(getppid(), SIGUSR1);
        pause();
        dup2(fdExp[1], 1);
        execl("/Users/nikita-mac/Desktop/UNIX/KR1/KR1/Exp", "/Users/nikita-mac/Desktop/UNIX/KR1/KR1/Exp", x, NULL);
        perror("Exec Exp");
        exit(0);
    }
    
    pause();
    kill(pidPi, SIGUSR1);
    kill(pidExp, SIGUSR1);
    
    sleep(1);
    
    kill(pidPi, SIGUSR2);
    kill(pidExp, SIGUSR2);

    wait(&pidPi);
    wait(&pidExp);
    
    read(fdPi[0], bufPi, 27);
    read(fdExp[0], bufExp, 27);

    double Exp = atof(bufExp);
    double Pi = atof(bufPi);
    Pi = sqrt(2 * Pi);
    double result = Exp / Pi;
    printf("\n%f\n", result);
    return 0;
}
