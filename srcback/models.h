#pragma once

#include <string>

/** Contains models dataset available in application */
namespace Models {

/** Model related to order dataset */
struct OrderModel {
  std::string orderID;
  std::string pesel;
  std::string licenseNumber;
  std::string variantID;
  std::string orderDate;
  std::string receptionDate;
  std::string price;
};

struct UserModel {
  std::string firstName;
  std::string lastName;
  std::string pesel;
  std::string phoneNumber;
  std::string mailAdress;
  std::string city;
  std::string postalCode;
  std::string street;
  std::string houseNumber;
};

} // namespace Models
