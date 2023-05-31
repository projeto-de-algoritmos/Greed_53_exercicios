#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int N, K;

	cin >> N >> K;
	
	vector<int> vetor(N);

	for(int i=0; i < N; i++)
		cin >> vetor[i];
	
	vector<bool> visitado(N, false);

	int comeco = 0, finale = N/2, aux = 0;

	sort(vetor.begin(), vetor.end());

	while(finale < N){
		if(vetor[finale] - vetor[comeco] >= K){
			aux++;
			visitado[comeco] = true;
			visitado[finale] = true;
			finale++;

			while(visitado[comeco])
				comeco++;
		}
		else
			finale++;
	}
	cout << aux << endl;

	return 0;
}