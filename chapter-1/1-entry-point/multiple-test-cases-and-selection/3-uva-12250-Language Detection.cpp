#include <bits/stdc++.h>

using namespace std;

int main() {
  string word, country;

  int count = 1;
  while (cin >> word && word != "#") {
    if (word == "HELLO") country = "ENGLISH";
    else if (word == "HOLA") country = "SPANISH";
    else if (word == "HALLO") country = "GERMAN";
    else if (word == "BONJOUR") country = "FRENCH";
    else if (word == "CIAO") country = "ITALIAN";
    else if (word == "ZDRAVSTVUJTE") country = "RUSSIAN";
    else country = "UNKNOWN";

    cout << "Case " << count << ": " << country << "\n";

    count++;
  }
}