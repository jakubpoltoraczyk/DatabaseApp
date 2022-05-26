#include "sqldatabaseclient.h"

void SQLDataBaseClient::createOrder([[maybe_unused]] Models::OrderModel model) {}

void SQLDataBaseClient::createClient([[maybe_unused]] Models::UserModel model) {}

void SQLDataBaseClient::deleteClient([[maybe_unused]] const std::string& pesel) {}

void SQLDataBaseClient::updateClient([[maybe_unused]] Models::UserModel model) {}

QJsonDocument SQLDataBaseClient::readClients() { return QJsonDocument(); }
