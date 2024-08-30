#define atividade "07"
#define nome "Savio de Carvalho Soares"
#define matricula "552882"

/*
Seja um BIGnUMBER um inteiro positivo ou zero representado por uma lista encadeada. Cada dígito ocupa um nó da estrutura. A significância dos algarismos é de menor para maior a partir da raiz.
Por exemplo, o número 1234 é armazenado pela lista:

|-> 4 -> 3 -> 2 -> 1

Onde |-> representa o ponteiro da raiz e -> outras conexões entre nós. Implemente bigNumber no modelo de classe a seguir,
*/

#include <iostream>
#include <stack>

class bigNumber
{

    struct nodo
    {
        int digit;
        nodo *next;
        nodo(int d) : digit(d), next(nullptr) {}
    };
    nodo *pt;

    void acrescentarDigito(int digit)
    {
        if (!pt)
        {
            pt = new nodo(digit);
        }
        else
        {
            nodo *atual = pt;
            while (atual->next)
            {
                atual = atual->next;
            }
            atual->next = new nodo(digit);
        }
    }

    void removerZeros()
    {
        nodo *atual = pt;
        nodo *prev = nullptr;

        while (atual && atual->digit == 0)
        {
            prev = atual;
            atual = atual->next;
        }

        if (prev)
        {
            delete pt;
            pt = atual;
        }

        if (!pt)
        {
            pt = new nodo(0); // Se tudo zero, retorna para 0.
        }
    }

public:
    bigNumber(int x)
    {
        do
        {
            acrescentarDigito(x % 10);
            x /= 10;
        } while (x > 0);
    }

    bigNumber()
    {
        acrescentarDigito(0);
    }

    void operator+=(int x)
    {
        bigNumber temp(x);
        *this += temp;
    }

    void operator*=(int x)
    {
        bigNumber temp(x);
        *this *= temp;
    }

    void operator+=(bigNumber &bn)
    {
        // addList(bn.pt);
        int time = 0;
        nodo *atual = pt;
        nodo *outroAtual = bn.pt;
        nodo *prev = nullptr;

        while (atual || outroAtual || time)
        {
            int sum = time;
            if (atual)
            {
                sum += atual->digit;
            }
            if (outroAtual)
            {
                sum += outroAtual->digit;
            }

            if (atual)
            {
                atual->digit = sum % 10;
                time = sum / 10;
                prev = atual;
                atual = atual->next;
            }
            else
            {
                prev->next = new nodo(sum % 10);
                time = sum / 10;
                prev = prev->next;
            }

            if (outroAtual)
            {
                outroAtual = outroAtual->next;
            }
        }
    }

    void operator*=(bigNumber &bn)
    {
        bigNumber result;
        int mudanca = 0;

        for (nodo *outroAtual = bn.pt; outroAtual; outroAtual = outroAtual->next)
        {
            bigNumber temp;
            int time = 0;

            for (int i = 0; i < mudanca; ++i)
            {
                temp.acrescentarDigito(0);
            }

            for (nodo *atual = pt; atual; atual = atual->next)
            {
                int product = atual->digit * outroAtual->digit + time;
                temp.acrescentarDigito(product % 10);
                time = product / 10;
            }

            if (time)
            {
                temp.acrescentarDigito(time);
            }

            result += temp;
            ++mudanca;
        }

        *this = result;

        // Remover zeros extras
        removerZeros();
    }

    bool operator==(bigNumber &bn)
    {
        nodo *atual1 = pt;
        nodo *atual2 = bn.pt;

        while (atual1 && atual2)
        {
            if (atual1->digit != atual2->digit)
            {
                return false;
            }
            atual1 = atual1->next;
            atual2 = atual2->next;
        }

        return atual1 == nullptr && atual2 == nullptr;
    }

    void print() const
    {
        std::stack<int> digits;
        nodo *atual = pt;
        while (atual)
        {
            digits.push(atual->digit);
            atual = atual->next;
        }

        while (!digits.empty())
        {
            std::cout << digits.top();
            digits.pop();
        }
        std::cout << std::endl;
    }
};

int main()
{
    bigNumber num1(1234);
    bigNumber num2(5678);

    num1 += num2;
    num1.print(); // Deve imprimir 6912

    num1 *= 2;
    num1.print(); // Deve imprimir 13824

    return 0;
}
