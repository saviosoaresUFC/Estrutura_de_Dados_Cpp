#include <string>
#include <map>
#include <stack>

using namespace std;

#define atividade "05"
#define nome "Savio de Carvalho Soares"
#define matricula "552882"

// Atividade 5

// Usando a pilha do STL do C++ implemente um avaliador de expressões numéricas cujas expressões, dadas como
// strings de entrada, devem ter as seguintes características:

// - Ser formada for letras, operadores, números e parênteses.

// - As letras formam nomes de variáveis e as constantes podem ser números reais ou inteiros. Exemplo,
// "x+beta-1.0" => possui as variáveis x e beta, os operadores + e - e a constante numérica 1.0

// - Os operadores computáveis são em ordem de precedêcia: "(+-*/^" onde "^" é o operador de potência.

// - Espaços em branco devem ser ignoráveis e outros caracteres diferentes dos apresentados devem ser
// considerados erros. Por exemplo, "alpha+gama0+2!"  => são erros "gama0" pois é uma variável contendo
// um caractere não letra,  Em "2!" o caractere é inválido.

// - O valor das variáveis é uma entrada representada pela estrutura de dados map da STL do C++.
// Veja exemplo de uso do map a seguir:

/*
    int main() {
        map<string, float> m;
        m["x"] = 21.5; // carrega 'x'
        m["beta"] = 14.72; // carrega 'beta'
    }
*/

bool isOperator(char c)
{
  return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op)
{
  if (op == '+' || op == '-')
    return 1;
  if (op == '*' || op == '/')
    return 2;
  if (op == '^')
    return 3;
  return 0;
}

float applyOp(float a, float b, char operacao)
{
  switch (operacao)
  {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  case '^':
    float result = 1;
    for (int i = 0; i < (int)b; i++)
    {
      result *= a;
    }
    return result;
  }
  return 0;
}

float stringToFloat(const string &str){
  float result = 0;
  bool isNegative = false;
  bool isFraction = false;
  float fractionValue = 0.1;

  int i = 0;
  if(str[i] == '-'){
    isNegative = true;
    i++;
  } 

  for (; i < str.size(); i++)
  {
    if(str[i] == '.'){
      isFraction = true;
      continue;
    }

    if(isFraction){
      result += (str[i] - '0') * fractionValue;
      fractionValue *= 0.1;
    } else {
      result = result * 10 + (str[i] - '0');
    }
  }

  if(isNegative){
    result *= -1;
  }

  return result;

}

bool isNumber(const string &str){
  for (int i = 0; i < str.size(); i++)
  {
    if(!isdigit(str[i]) && str[i] != '.'){
      return false;
    }
  }
  return true;
}

float xEval(string x, map<string, float> &m) {
    stack<float> values; 
    stack<char> ops; 
    string token;

    for (int i = 0; i < x.size(); ++i) {
        char c = x[i];

        if (c == ' ') continue;

        if (isdigit(c) || (c == '-' && (i + 1 < x.size() && isdigit(x[i + 1])))) {
            token.clear();
            if (c == '-') token += c;
            while (i < x.size() && (isdigit(x[i]) || x[i] == '.')) {
                token += x[i++];
            }
            values.push(stringToFloat(token));
            --i; 
        }
        else if (isalpha(c)) {
            token.clear();
            while (i < x.size() && isalpha(x[i])) {
                token += x[i++];
            }
            --i;
            if (m.find(token) != m.end()) {
                values.push(m[token]);
            } else {
                return 0; // variável não encontrada
            }
        }
        else if (c == '(') {
            ops.push('(');
        }
        else if (c == ')') {
            while (!ops.empty() && ops.top() != '(') {
                float val2 = values.top();
                values.pop();
                float val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            if (!ops.empty()) ops.pop();
        }
        else if (isOperator(c)) {
            while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                float val2 = values.top();
                values.pop();
                float val1 = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                values.push(applyOp(val1, val2, op));
            }
            ops.push(c);
        }
        else {
            return 0; // caractere inválido
        }
    }

    while (!ops.empty()) {
        float val2 = values.top();
        values.pop();
        float val1 = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        values.push(applyOp(val1, val2, op));
    }

    return values.top();
}
