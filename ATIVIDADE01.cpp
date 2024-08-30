#define atividade "1"
#define nome "Savio de Carvalho"
#define matricula "552882"

//AS FUNÇÕES A SEGUIR DEVEM SER 
// IMPLEMENTADAS USANDO RECURSIVIDADE.
// FUNÇÕES AUXILIATES PODEM SER 
// USADAS DESDE QUE SEJAM TAMBÉM RECURSIVAS.

// 1
// calcula o mdc de dois inteiros dados.   
int mdc(int a, int b  ) {
    if (b == 0){
      return a;
    }
    return mdc(b, a % b);
}

// 2
// Carregar no vetor M de tamanho n os n primeiros primos começando em 2
// Note que o argumento de entrada M é saída neste problema.
bool isPrime(int n, int i = 2) {
    if (n <= 2) {
        return (n == 2) ? true : false;
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    return isPrime(n, i + 1);
}


void loadPrimeVec(int M[], int n)  {
    static int i = 2;
    if (n == 0) {
        return;
    }
    if (isPrime(i)) {
        M[0] = i;
        i++;
        loadPrimeVec(M + 1, n - 1);
    } else {
        i++;
        loadPrimeVec(M, n);
    }
}