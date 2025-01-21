#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>

// Estrutura para armazenar os dados do usuário
struct User {
    int id;
    std::string name;
    std::tm birthday;
};

// Função auxiliar para converter a data de string para std::tm
std::tm stringToDate(const std::string& date) {
    std::tm tm = {};
    strptime(date.c_str(), "%Y-%m-%d", &tm);
    return tm;
}

// Função para ler o arquivo CSV e separar os dados em variáveis apropriadas
std::vector<User> readCSV(const std::string& filename) {
    std::vector<User> users;
    std::ifstream file(filename);
    std::string line, word;

    // Verificar se o arquivo foi aberto com sucesso
    if (!file.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return users;
    }

    // Ignorar a primeira linha (cabeçalho)
    std::getline(file, line);

    // Ler o arquivo linha por linha
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        User user;

        // Ler e atribuir ID (inteiro)
        std::getline(ss, word, ',');
        user.id = std::stoi(word);

        // Ler e atribuir Nome (string)
        std::getline(ss, word, ',');
        user.name = word;

        // Ler e atribuir Data de Nascimento (data tm da lib <ctime>)
        std::getline(ss, word, ',');
        user.birthday = stringToDate(word);

        users.push_back(user);
    }

    // Fechar o arquivo
    file.close();
    return users;
}

int main() {
    std::string filename = "users.csv";

    // Ler os dados do arquivo CSV e criar um vetor "users". Ao final do processamento, cada usuário estará em "users".
    std::vector<User> users = readCSV(filename);

    // Aqui você pode adicionar a lógica para inserir os usuários nas árvores BST e AVL

    return 0;
}

