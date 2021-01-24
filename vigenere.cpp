#include <iostream>

std::string encrypter(std::string plainText, std::string key);
std::string decrypter(std::string cipherText, std::string key);
std::pair<std::string, std::string> dataCollector();
void interface();

int main(){
  while(true) {
    interface();
  }
}

void interface() {
  int option;
  std::pair<std::string, std::string> data;

  std::cout << "Welcome to the encryption and decryption" << std::endl;
  std::cout << "1.Encryption 2.Decryption 3.Exit" << std::endl;
  std::cin >> option;

  switch(option) {
    case 1:
      data = dataCollector();
      std::cout << "Encryption:" << std::endl; 
      std::cout << encrypter(data.first, data.second) << std::endl;
      break;

    case 2:
      data = dataCollector();
      std::cout << "Decryption:" << std::endl; 
      std::cout << decrypter(data.first, data.second) << std::endl;
      break;

    case 3:
      exit(1);
    
    default :
      std::cerr << "Invalid code." << std::endl;
      exit(1);
  }
}

std::pair<std::string, std::string> dataCollector() {
  std::string plainText, key;

  std::cout << "Enter a text, please:" << std::endl;
  std::cin >> plainText;

  std::cout << "Enter a key, please:" << std::endl;
  std::cin >> key;

  return {plainText, key};
}

std::string encrypter(std::string plainText, std::string key) {
  std::string cipherText, newKey = key;

  while(newKey.length() < plainText.length()) {
    newKey += key;
  }
  
  for(unsigned i = 0; i < plainText.length(); i++) {
    cipherText += (plainText[i] + newKey[i])%26 +65;
  }

  return cipherText;
}


std::string decrypter(std::string cipherText, std::string key) {
    std::string plainText, newKey = key;

  while(newKey.length() < cipherText.length()) {
    newKey += key;
  }
  
  for(unsigned i = 0; i < cipherText.length(); i++) {
    plainText += (cipherText[i] - newKey[i] +26)%26 +65;
  }

  return plainText;
}