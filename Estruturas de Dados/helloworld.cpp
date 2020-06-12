#include <iostream>
#include <cctype>
using namespace std;

int main(void)
{
  char ch;
  do {
     cout << "Pressionar S ou s para sair, \nqualquer outra tecla para continuar: "; 
     cin.get(ch);
     ch = toupper(ch);
     if (ch != '\n')
        cin.ignore();
     if (ch != 'S')
        cout << "Deseja continuar?\n";
     else
        cout << "Saindo...";
  } while (ch != 'S');
#ifdef WIN32
  system ("pause");
#endif
  return 0;
}
