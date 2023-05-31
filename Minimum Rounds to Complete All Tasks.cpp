int minimumRounds(vector<int>& tasks) {
    // Ordena as tarefas em ordem crescente
    sort(tasks.begin(), tasks.end());

    // Mapa para armazenar o número de ocorrências de cada tarefa
    map<int, int> ocorrenciaTarefa;

    int count = 0;

    // Conta o número de ocorrências de cada tarefa
    for (int i = 0; i < tasks.size(); i++) {
        ocorrenciaTarefa[tasks[i]]++;
    }

    // Calcula o número mínimo de rodadas necessárias
    for (auto tarefa : ocorrenciaTarefa) {
        if (tarefa.second == 2)
            count += 1;
        else if (tarefa.second >= 3) {
            count = count + ceil(double(tarefa.second) / 3.0);
        }
        else
            return -1;
    }

    return count;
}