#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, x, diferencaMinima, aumento, reducao;
    cin >> n >> x;
 
    vector<int> vetor(n);
    
    for(int i=0; i < n; i++) 
        cin >> vetor[i];
        
    //ordena o vetor
    sort(vetor.begin(), vetor.end());
 
    diferencaMinima = vetor[n-1] - vetor[0];
 
    for (int i = 1; i < n; i++) {
        aumento = max(vetor[i-1] + x, vetor[n-1] - x);
        reducao = min(vetor[0] + x, vetor[i] - x);
        diferencaMinima = min(diferencaMinima, aumento - reducao);
    }
 
    cout<< diferencaMinima << endl;
}