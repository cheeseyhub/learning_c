#include <iostream>

int main() {
  // Get User name
  // Get what he likes
  // Get his date of birth
  // print

  std::string name, like, date;

  std::cout << "What is your name ?";
  std::cin >> name;

  std::cout << "What do you like ?";
  std::cin >> like;

  std::cout << "What is your date of birth ?";
  std::cin >> date;

  std::cout << "Assalam-o-Alikum!" << name << "\n";
  std::cout << "You like " << like << " Years old" << "\n";

  return 0;
}
