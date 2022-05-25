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

} // namespace Models
