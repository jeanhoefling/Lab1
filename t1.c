#include <stdio.h>
#define pi 3.1415926535

double potencia (double base, int expoente) {
    double res = 1;
    if (expoente >= 0) {
        while (expoente > 0) {
            res = res * base;
            expoente--;
        }
        return res;
    }
    else {
        expoente = -expoente;
        while (expoente > 0) {
            res = res * base;
            expoente--;
        }
        return 1/res;
    }
}

long fatorial (long numero) {
    if (numero == 0) {
        return 1;
    }
    return numero * fatorial (numero-1);
}

double seno (double angulo) {
    double termo = angulo;
    double total = 0;
    long i = 1;
    while (termo >= potencia(10, -10) || termo <= -potencia(10, -10)) {
        total += termo;
        i += 2;
        termo *= ((-1) * angulo * angulo)/(i * (i-1));
    }
    return total;
}

double raiz (double numero) {
    double termo_anterior = 5, termo_atual = 6, temp = 5;
    while (termo_atual - termo_anterior > potencia(10, -10) || termo_atual - termo_anterior < -potencia(10, -10)) {
        termo_anterior = temp;
        termo_atual = (termo_anterior+numero/termo_anterior)/2;
        temp = termo_atual;
    }
    return termo_atual;
}


double cosseno (double angulo) {
    double seno_angulo = seno(angulo);

    //If feito para evitar cálculo de uma raiz negativa por imprecisão da função seno
    if (seno_angulo > 1 || seno_angulo < -1) {
        seno_angulo = (int)seno_angulo;
    } 

    double cosseno_angulo = raiz(1-potencia(seno_angulo, 2));
    int quadrante = ((int)(angulo/(pi/2)))%4 + 1;
    if (quadrante == 2 || quadrante == 3) {
        cosseno_angulo = -cosseno_angulo;
    }
    return cosseno_angulo;
}

void tabela () {
    int cont = 10;
    printf("\n------------------------------------\n");
    printf("| Angulo |    Seno    |  Cosseno   |\n");
    printf("|   5    | %.7lf | %.7lf  |\n", seno(5), cosseno(5));
    while (cont <= 30) {
        double seno_cont = seno(cont);
        double cosseno_cont = cosseno(cont);
        if (seno_cont >= 0 && cosseno_cont >= 0 ) {
            printf("|   %i   | %.7lf  | %.7lf  |\n", cont, seno_cont, cosseno_cont);
        }
        else if (seno_cont >= 0) {
            printf("|   %i   | %.7lf  | %.7lf |\n", cont, seno(cont), cosseno(cont));
        }
        else if (cosseno_cont >= 0) {
            printf("|   %i   | %.7lf | %.7lf  |\n", cont, seno(cont), cosseno(cont));
        }
        else {
            printf("|   %i   | %.7lf | %.7lf |\n", cont, seno(cont), cosseno(cont));
        }
        cont += 5;
    }
    printf("------------------------------------\n");
}

int main (void) {
    tabela();
}

//conferir se os quadrante pro cosseno ta funcionando em varios valores (maybe scanf)
