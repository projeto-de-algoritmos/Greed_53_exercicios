#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, x, diferencaMinima, aumento, reducao;
    cin >> n >> x;
 
    vector<int> vetor(n);
 
    // Lê os valores do vetor a partir da entrada padrão
    for(int i=0; i < n; i++) 
        cin >> vetor[i];

    // Ordena o vetor em ordem crescente
    sort(vetor.begin(), vetor.end());
 
    // Inicializa a diferença mínima com o maior intervalo possível inicialmente
    diferencaMinima = vetor[n-1] - vetor[0];
 
    // Itera sobre os elementos do vetor (exceto o primeiro)
    for (int i = 1; i < n; i++) {
        // Calcula o valor de aumento como o máximo entre o valor anterior somado a x e o último valor subtraído por x
        aumento = max(vetor[i-1] + x, vetor[n-1] - x);
        
        // Calcula o valor de redução como o mínimo entre o primeiro valor somado a x e o valor atual subtraído por x
        reducao = min(vetor[0] + x, vetor[i] - x);
        
        // Calcula a diferença entre aumento e redução e compara com a diferença mínima atual
        // Atualiza a diferença mínima se a nova diferença for menor
        diferencaMinima = min(diferencaMinima, aumento - reducao);
    }
 
    // Imprime a diferença mínima encontrada
    cout << diferencaMinima;
}