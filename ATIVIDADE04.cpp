#define atividade "04"
#define nome "Savio de Carvalho Soares"
#define matricula "552882"

// 1

class vetor {
   int *u;  // ponteiro para vetor
   int size; // tamanho do vetor
public:
   vetor(int n) { u=new int[n]; size=n; }
   ~vetor() { delete [] u; }
   int& operator[] (int k) { return u[k]; } 
   int len() { return size; }
};

vetor merge(vetor x, vetor y) {
    vetor result(x.len() + y.len());
    int i = 0, j = 0, k = 0;
    while (i < x.len() && j < y.len()) {
        if (x[i] <= y[j]) {
            result[k] = x[i];
            i++;
        } else {
            result[k] = y[j];
            j++;
        }
        k++;
    }
    while (i < x.len()) {
        result[k] = x[i];
        i++;
        k++;
    }
    while (j < y.len()) {
        result[k] = y[j];
        j++;
        k++;
    }
    return result;
}

vetor mergeAll(vetor U[], int n) {
    if (n == 1) return U[0];
    
    int mid = n / 2;
    vetor esquerda = mergeAll(U, mid);
    vetor direita = mergeAll(U + mid, n - mid);
    return merge(esquerda, direita);
}

/*
Exemplo 1

U = { [6,8,5], [3,2,1], [4,0,9] }

{ [6,8,5], [2,1], [4,0,9] } => {3}
{ [6,8,5], [1], [4,0,9] } => {3,2}
{ [6,8,5], [], [4,0,9] } => {3,2,1}
{ [6,8,5], [], [0,9] } => {3,2,1,4}
{ [6,8,5], [], [9] } => {3,2,1,4,0}
{ [8,5], [], [9] } => {3,2,1,4,0,6}
{ [5], [], [9] } => {3,2,1,4,0,6,8}
{ [], [], [9] } => {3,2,1,4,0,6,8,5}
{ [], [], [] } => {3,2,1,4,0,6,8,5,9}

Exemplo 2

U = { [1,3,5], [2,4,6], [7,8,9] }

{ [3,5], [2,4,6], [7,8,9] } => {1}
{ [3,5], [4,6], [7,8,9] } => {1,2}
{ [5], [4,6], [7,8,9] } => {1,2,3}
{ [5], [6], [7,8,9] } => {1,2,3,4}
{ [], [6], [7,8,9] } => {1,2,3,4,5}
{ [], [], [7,8,9] } => {1,2,3,4,5,6}
{ [], [], [8,9] } => {1,2,3,4,5,6,7}
{ [], [], [9] } => {1,2,3,4,5,6,7,8}
{ [], [], [] } => {1,2,3,4,5,6,7,8,9}

*/