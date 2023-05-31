#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;

    // Lê os valores de N e K fornecidos pelo usuário
    cin >> N >> K;

    // Cria um vetor chamado 'vetor' com tamanho N para armazenar os valores
    vector<int> vetor(N);

    // Lê N valores do usuário e atribui aos elementos do vetor 'vetor'
    for (int i = 0; i < N; i++)
        cin >> vetor[i];

    // Cria um vetor chamado 'visitado' com tamanho N e inicializa todos os elementos como falso
    vector<bool> visitado(N, false);

    // Variáveis para controlar os índices de início, fim e contador auxiliar
    int comeco = 0, finale = N / 2, aux = 0;

    // Ordena o vetor em ordem crescente
    sort(vetor.begin(), vetor.end());

    // Loop principal que percorre os elementos do vetor
    while (finale < N) {
        // Verifica se a diferença entre os elementos atuais é maior ou igual a K
        if (vetor[finale] - vetor[comeco] >= K) {
            // Incrementa o contador auxiliar
            aux++;

            // Marca os elementos como visitados
            visitado[comeco] = true;
            visitado[finale] = true;

            // Avança para o próximo elemento
            finale++;

            // Encontra o próximo índice de início não visitado
            while (visitado[comeco])
                comeco++;
        } else {
            // Incrementa o índice de fim
            finale++;
        }
    }

    // Imprime o valor do contador auxiliar
    cout << aux << endl;

    return 0;
}