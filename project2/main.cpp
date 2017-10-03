#include <container.h>
#include <trnx_error.h>
#include <iostream>
#include <string>

using namespace BloombergLP::trnx;

int hashCodeForInt (int a) {
  return a;
}

int hashCodeForString (std::string str) {
  return str.length();
}


int main() {
  HashMap<int, std::string> hm(hashCodeForInt);
  hm.put(1, "Saurabh");
  hm.put(2, "Sakpal");
  hm.put(3, "Swathi");
  hm.put(21, "Nayak");
  hm.put(22, "Gurunath");
  hm.put(23, "Hanamsagar");
  hm.put(11, "Aniket");
  hm.put(12, "Dhuri");
  hm.put(13, "Amruta");
  hm.put(14, "Shintre");

  std::cout<< hm.get(1) << "\n";
  std::cout<< hm.get(2) << "\n";
  std::cout<< hm.get(23) << "\n";
  std::cout<< hm.get(14)<< "\n";
}
