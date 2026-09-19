#include "iostream"
#include <cctype>
using namespace std;

// element wise insertion
int main() {

  string s = "hello";

  // to print length or s.size()
  cout << s.length();

  // accessing characters
  cout << s[0];
  cout << s[1];

  // traverse a string
  for (int i = 0; i < s.size(); i++) {
    cout << s[i] << " ";
  }

  // reverse traversal
  for (int i = s.size(); i > 0; i--) {
    cout << s[i] << " ";
  }

  // comparing strings
  string compare = "hoye";
  if (s == compare) {
    cout << "same";
  }

  // add a character
  s.push_back('t');

  // remove a character
  s.pop_back();

  // substring finder
  cout << s.substr(0, 3);

  // find a word
  string hello_world = "hello world";
  cout << hello_world.find("world");

  // convert character case
  char ch = 'a';
  ch = toupper(ch);

  // conver lower case
  ch = tolower(ch);

  isalpha(ch); // alphabet?
  isdigit(ch); // digit?
  isalnum(ch); // alphabet or digit?
  isspace(ch); // whitespace?

  return 0;
}