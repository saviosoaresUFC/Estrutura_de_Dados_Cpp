#include <iostream>
#include <fstream>

#define atividade "3"
#define nome "Savio de Carvalho Soares"
#define matricula "552882"

namespace aluno
{
    /*
    Representa uma fração reduzida, ou seja, numerador e denominador são primos entre si.
    */
    class frac
    {
        int numerador, denominador;
        static int mdc(int a, int b)
        {
            return b != 0 ? mdc(b, a % b) : a;
        }

    public:
        frac(int n = 0, int d = 1) : numerador(n), denominador(d)
        {
            // configura operador ==
            int divisor = mdc(numerador, denominador);
            numerador /= divisor;
            denominador /= divisor;
        }
        // Operadores
        bool operator>(frac &divisao)
        {
            // configura operador >
            return (numerador * divisao.denominador) > (divisao.numerador * denominador);
        }
        bool operator==(frac &divisao)
        {
            // configura operador ==
            if(numerador == divisao.numerador && denominador == divisao.denominador)
                return true;
        }
        frac operator+(frac &divisao)
        {
            // soma
            int auxiliar_numerador = numerador * divisao.denominador + denominador * divisao.numerador;
            int auxiliar_den = denominador * divisao.denominador;

            int divisor = mdc(auxiliar_numerador, auxiliar_den);

            auxiliar_numerador /= divisor;
            auxiliar_den /= divisor;

            return frac(auxiliar_numerador, auxiliar_den);
        }
        int getNum() { return numerador; }
        int getDen() { return denominador; }
    };

    frac *loadFracs(char *fileFracs)
    {
        /*
        Retorna frações num arquivo e as coloca em um vetor alocaso dinamicamente.

        O conteúdo de tais arquivos segue o formato do esquema a seguir,

        -----------
        4           | -> 4 frações
        1   2       | -> fração 1/2
        3   5       | -> fração 1/5
        2   9       ! -> fração 2/9
        7   11      ! -> fração 7/11
        -------------
        */
        std::ifstream file(fileFracs);

        int numFracs;
        file >> numFracs;

        frac *fracs = new frac[numFracs];

        for (int i = 0; i < numFracs; i++)
        {
            int n, d;
            file >> n >> d;
            fracs[i] = frac(n, d);
        }

        file.close();
        return fracs;
    }

    frac sumFracs(frac fracs[], int n)
    {
        /*
         Retorna soma de frações do vetor de entrada.
      */
        if (n == 1)
            return fracs[0];

        frac soma = fracs[0];
        for (int i = 1; i < n; i++)
        {
            soma = soma + fracs[i];
        }

        return soma;
    }

    void sortFracs(frac fracs[], int n)
    {
        /*
           ordena vetor de drações de entrada. Note que um ponteiro do vetor real é passado como argumento. O tamanho passaso  do vetor é dado por n.
        */
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (fracs[i] > fracs[j])
                {
                    frac aux = fracs[i];
                    fracs[i] = fracs[j];
                    fracs[j] = aux;
                }
            }
        }
    }
}
