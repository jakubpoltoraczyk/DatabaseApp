#include "mockdatabaseclient.h"

#include <iostream>

#include <QFile>

namespace {
QJsonDocument openJson(const QString& pathToJson) {
  QFile file(pathToJson);
  file.open(QIODevice::ReadOnly);
  auto fileContent = file.readAll();
  file.close();
  return QJsonDocument::fromJson(fileContent);
}
} // namespace

void MockDataBaseClient::createOrder(Models::OrderModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "OrderModel: {" << model.pesel << ", " << model.orderID << ", "
            << model.licenseNumber << ", " << model.variantID << ", " << model.orderDate << ", "
            << model.receptionDate << ", " << model.price << "}" << std::endl;
}

void MockDataBaseClient::createClient(Models::UserModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "UserModel: {" << model.firstName << ", " << model.lastName << ", " << model.pesel
            << ", " << model.phoneNumber << ", " << model.mailAdress << ", " << model.city << ", "
            << model.postalCode << ", " << model.street << ", " << model.houseNumber << "}"
            << std::endl;
}

void MockDataBaseClient::deleteClient(const std::string& pesel) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "Pesel: " << pesel << std::endl;
}

void MockDataBaseClient::updateClient(Models::UserModel model) {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  std::cout << "UserModel: {" << model.firstName << ", " << model.lastName << ", " << model.pesel
            << ", " << model.phoneNumber << ", " << model.mailAdress << ", " << model.city << ", "
            << model.postalCode << ", " << model.street << ", " << model.houseNumber << "}"
            << std::endl;
}

QJsonDocument MockDataBaseClient::readClients() {
  std::cout << __PRETTY_FUNCTION__ << std::endl;
  return openJson(":/TEST/testfiles/clients.json");
}
