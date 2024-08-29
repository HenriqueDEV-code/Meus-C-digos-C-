#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

int main() {
    std::string username, password, database, host;
    std::cout << "Enter database host: ";
    std::cin >> host;
    std::cout << "Enter database username: ";
    std::cin >> username;
    std::cout << "Enter database password: ";
    std::cin >> password;
    std::cout << "Enter database name: ";
    std::cin >> database;

    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        // Criando a conexão com o banco de dados
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://" + host + ":3306", username, password);

        // Conectando ao banco de dados específico
        con->setSchema(database);

        // Solicita o nome do usuário
        std::string user_name;
        std::cout << "Enter your name: ";
        std::cin >> user_name;

        // Preparando a consulta SQL
        sql::PreparedStatement* pstmt;
        pstmt = con->prepareStatement("INSERT INTO users (name) VALUES (?)");
        pstmt->setString(1, user_name);

        // Executando a consulta
        pstmt->execute();

        std::cout << "Name saved to database successfully!" << std::endl;

        delete pstmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
