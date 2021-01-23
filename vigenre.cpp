// Notas
//
// adicionar uso de caracteres minusculos
// adicionar uso de caracteres numericos
// adicionar uso de caracteres especiais

#include <iostream>

std::string encrypter(std::string plainText, std::string key);
std::string decrypter(std::string cipherText, std::string key);
std::pair<std::string, std::string> interface();

int main(){
  auto [plainText, key] = interface();

  std::cout << "Encryption:" << std::endl; 
  std::cout << encrypter(plainText, key) << std::endl;

  std::cout << "Decryption:" << std::endl;
  std::cout << decrypter(plainText, key) << std::endl;
}

std::pair<std::string, std::string> interface() {
  std::string plainText, key;

  std::cout << "Enter a plaintext, please:" << std::endl;
  std::getline(std::cin, plainText);

  std::cout << "Enter a key, please:" << std::endl;
  std::getline(std::cin, key);

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