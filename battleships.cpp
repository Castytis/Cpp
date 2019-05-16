#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h>
  using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
const char LANG_TUSC = char(176);
const char LANG_LAIV = char(219);
const char LANG_SAUTA = 'O';
const char LANG_NERA = 'N'; //char(157);
const char LANG_PTKT = 'X';
class Claukas {
  private:

  char fl[10][10];
  char PlayerFl[10][10];
  int PCShoots = 0;
  int PlayerShoots = 0;
  bool vert;
  int tempX, tempY, x, y, vertNum = 0, horizNum = 0, check = 0;

  public:

    char get_status(int x, int y) {
      return fl[x][y];
    };

  void show_field() {
    cout << "\n\n";
    cout << "   " << " 0123456789" << "   " << " 0123456789\n";
    for (int y = 0; y < 10; y++) {

      cout << "   ";
      cout << y;

      for (int x = 0; x < 10; x++) {
        if(fl[x][y]==LANG_LAIV)
            cout<<LANG_TUSC;
        else
            cout << fl[x][y];
      }
      cout << "   ";
      cout << y;
      for (int x = 0; x < 10; x++) {
        if (PlayerFl[x][y] == LANG_NERA)
          cout << char(176);
        else
          cout << PlayerFl[x][y];
      }
      cout << endl;
    }
  };
  void clear_field() {
    for (int y = 0; y < 10; y++) {
      for (int x = 0; x < 10; x++) {
        fl[x][y] = LANG_TUSC;
        PlayerFl[x][y] = LANG_TUSC;
      }
    }
  };
  string checkWinner() {
    if (PCShoots == 20) {
      return "PC";
    } else if (PlayerShoots == 20) {
      return "Player";
    } else {
      return "";
    }
  }
  bool put_ship(int x, int y, int ilg, bool yra_vert, bool isPC) {
    bool pavyko = true;
    char temp[10][10];
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        if (!isPC) {
          temp[i][j] = PlayerFl[i][j];
        } else {
          temp[i][j] = fl[i][j];
        }
      }
    }
    if (x < 0 || x > 9 || y < 0 || y > 9 || ilg < 1 || ilg > 4 || (!yra_vert && x + ilg > 10) || (yra_vert && y + ilg > 10))
      pavyko = false;
    else
      for (int i = 0; i < ilg && pavyko; i++) {
        if (yra_vert) // Vertikalus
        {
          if (temp[x][y + i] != LANG_TUSC || // center
            temp[x][int(abs(y + i - 1))] != LANG_TUSC || // up
            temp[x + 1 - (x + 1) / 10][int(abs(y + i - 1))] != LANG_TUSC || // up-right
            temp[x + 1 - (x + 1) / 10][y + i] != LANG_TUSC || // right
            temp[x + 1 - (x + 1) / 10][y + i + 1 - (y + i + 1) / 10] != LANG_TUSC || // down-right
            temp[x][y + i + 1 - (y + i + 1) / 10] != LANG_TUSC || // down
            temp[int(abs(x - 1))][y + i + 1 - (y + i + 1) / 10] != LANG_TUSC || // down-left
            temp[int(abs(x - 1))][y + i] != LANG_TUSC || // left
            temp[int(abs(x - 1))][int(abs(y + i - 1))] != LANG_TUSC) // up-left
            pavyko = false;
        } else // Horizontalus
        {
          if (temp[x + i][y] != LANG_TUSC || // center
            temp[x + i][int(abs(y - 1))] != LANG_TUSC || // up
            temp[x + i + 1 - (x + i + 1) / 10][int(abs(y - 1))] != LANG_TUSC || // up-right
            temp[x + i + 1 - (x + i + 1) / 10][y] != LANG_TUSC || // right
            temp[x + i + 1 - (x + i + 1) / 10][y + 1 - (y + 1) / 10] != LANG_TUSC || // down-right
            temp[x + i][y + 1 - (y + 1) / 10] != LANG_TUSC || // down
            temp[int(abs(x + i - 1))][y + 1 - (y + 1) / 10] != LANG_TUSC || // down-left
            temp[int(abs(x + i - 1))][y] != LANG_TUSC || // left
            temp[int(abs(x + i - 1))][int(abs(y - 1))] != LANG_TUSC) // up-left
            pavyko = false;
        }
      }

    return pavyko;
  }
  void place_ships(bool isPC) {
    int x, y;
    bool krypt;
    for (int ilg = 4; ilg >= 1; ilg--)
      for (int kiek = 1; kiek <= 4 - ilg + 1; kiek++) {
        x = rand() % 10;
        y = rand() % 10;
        krypt = (rand() % 2) == 0;
        if (!put_ship(x, y, ilg, krypt, isPC)) {
          kiek--;
        } else {
        if(isPC){
          for (int i = 0; i < ilg; i++)
            if (krypt == 1)
              fl[x][y + i] = LANG_LAIV;
            else
              fl[x + i][y] = LANG_LAIV;
        }
        else{
          for (int i = 0; i < ilg; i++)
            if (krypt == 1)
              PlayerFl[x][y + i] = LANG_LAIV;
            else
              PlayerFl[x + i][y] = LANG_LAIV;
        }
        }
      }
  }
  bool shootPlayer(int x, int y) {
    if (fl[x][y] == LANG_LAIV) {
      fl[x][y] = LANG_PTKT;
      return true;
      PlayerShoots++;
    } else if (fl[x][y] == LANG_TUSC) {
      fl[x][y] = LANG_SAUTA;
      return false;
    } else if (fl[x][y] == LANG_PTKT) {
      fl[x][y] = LANG_PTKT;
      return true;
    } else if (fl[x][y] == LANG_SAUTA) {
      fl[x][y] = LANG_SAUTA;
      return true;
    }
  }

  char shootPC() {
    if (check == 0) {
      do {
        horizNum = 0;
        vertNum = 0;
        x = rand() % 10;
        y = rand() % 10;
      } while (PlayerFl[x][y] == LANG_SAUTA || PlayerFl[x][y] == LANG_PTKT || PlayerFl[x][y] == LANG_NERA);
    } else if (check == 1 && vert == 1) {
      x = tempX;
      y = tempY + 1;
      if (PlayerFl[x][y] == LANG_SAUTA || PlayerFl[x][y] == LANG_NERA) {
        if (vertNum == 1) {
          x = tempX;
          y = tempY;
          check = 1;
          vert = 0;
          shootPC();
        } else {
          x = tempX;
          y = tempY;
          check = 2;
          vert = 1;
          shootPC();
        }
      } else if (x > 9 || x < 0 || y > 9 || y < 0) {
        x = tempX;
        y = tempY;
        check = 1;
        vert = 0;
        shootPC();
      }
    } else if (check == 1 && vert == 0) {
      x = tempX + 1;
      y = tempY;
      if (PlayerFl[x][y] == LANG_SAUTA || PlayerFl[x][y] == LANG_NERA) {
        x = tempX;
        y = tempY;
        check = 2;
        vert = 1;
        shootPC();

      } else if (x > 9 || x < 0 || y > 9 || y < 0) {
        x = tempX;
        y = tempY;
        check = 2;
        vert = 1;
        shootPC();
      }
    } else if (check == 2 && vert == 1 && horizNum == 0) {
      x = tempX;
      y = tempY - 1;
      if (PlayerFl[x][y] == LANG_SAUTA || PlayerFl[x][y] == LANG_NERA) {
        x = tempX;
        y = tempY;
        check = 2;
        vert = 0;
        shootPC();
      } else if (x > 9 || x < 0 || y > 9 || y < 0) {
        x = tempX;
        y = tempY;
        check = 2;
        vert = 0;
        shootPC();
      }
    } else if (check == 2 && vert == 0 && vertNum == 1 || check == 2 && horizNum > 0) {
      x = tempX - 1;
      y = tempY;
      if (PlayerFl[x][y] == LANG_SAUTA || PlayerFl[x][y] == LANG_NERA) {
        x = tempX;
        y = tempY;
        check = 0;
        vert = 1;
        shootPC();

      } else if (x > 9 || x < 0 || y > 9 || y < 0) {
        x = tempX;
        y = tempY;
        check = 0;
        vert = 1;
        shootPC();
      }

    } else {
      check = 0;
      vert = 1;
      vertNum = 0;
      horizNum = 0;
      shootPC();
    }
    if (PlayerFl[x][y] == LANG_PTKT) {
      tempX = x;
      tempY = y;
      shootPC();
    } else if (PlayerFl[x][y] == LANG_LAIV) {
      PlayerFl[x][y] = LANG_PTKT;
      PCShoots++;
      if (PlayerFl[x - 1][y - 1] == LANG_TUSC && x > 0 && y > 0) PlayerFl[x - 1][y - 1] = LANG_NERA;
      if (PlayerFl[x + 1][y + 1] == LANG_TUSC && x < 9 && y < 9) PlayerFl[x + 1][y + 1] = LANG_NERA;
      if (PlayerFl[x + 1][y - 1] == LANG_TUSC && x >= 0 && y > 0 && x < 9 && y <= 9) PlayerFl[x + 1][y - 1] = LANG_NERA;
      if (PlayerFl[x - 1][y + 1] == LANG_TUSC && x > 0 && y >= 0 && x <= 9 && y < 9) PlayerFl[x - 1][y + 1] = LANG_NERA;
      tempX = x;
      tempY = y;
      if (check == 0) {
        check = 1;
        vert = 1;
      }
      if (vert == 1) {
        horizNum = 0;
        vertNum++;
      } else {
        vertNum = 0;
        horizNum++;
      }
      shootPC();
    } else if (PlayerFl[x][y] == LANG_TUSC) {
      PlayerFl[x][y] = LANG_SAUTA;
    }
  }

  void player_placeShips(int x, int y, int ilg, bool krypt) {

    for (int i = 0; i < ilg; i++) {
      if (krypt == 1) {
        PlayerFl[x][y + i] = LANG_LAIV;
      } else {
        PlayerFl[x + i][y] = LANG_LAIV;
      }
    }
    system("cls");
    show_field();

  }
};
int PlayerShipPlaceInterface(Claukas & mano,bool isPC) {
  int x, y;
  bool krypt;
  for (int ilg = 4; ilg >= 1; ilg--)
    for (int kiek = 1; kiek <= 4 - ilg + 1; kiek++) {
      cout<<"\n"<<"Laivo ilgis:"<<ilg<<"\n";
      cout<<"\n"<< "Iveskite x, y kordinates bei krypti(0,1):\n";
      cin >> x >> y >> krypt;
      if (!mano.put_ship(x, y, ilg, krypt, isPC)) {
        kiek--;
        cout << "\n" <<"Pozicija pasirinkta netinkamai!\n";
      } else {
        mano.player_placeShips(x, y, ilg, krypt);
      }
    }
}

int main() {
  int x, y, choice=0;
    std::cout<<"\n"<< R"(                                    |__
                                     |\/
                                     ---
                                     / | [
                              !      | |||
                            _/|     _/|-++'
                        +  +--|    |--|--|_ |-
                     { /|__|  |/\__|  |--- |||__/
                    +---------------___[}-_===_.'__               /\
                ____`-' ||___-{]_| _[}-  |     |_[___\==--          \/   _
 _..._____--==/___]_|__|_____________________________[___\==--__,-----' .7
|                                                                   BB-61/
 \_______________________________________________________________________|

                   ____   _        _       _  _  __
                  / _/ /  ()__    / _ )___ / /_/ /_/ /_
                 \ \/ _ \/ / _ \  / _  / _ `/ __/ __/ / -)
                /___/_//_/_/ .__/ /____/\_,_/\__/\__/_/\__/
                          /_/
)" << '\n';

  system("PAUSE");
  srand(time(NULL));
  Claukas mano;
  mano.clear_field();
  mano.place_ships(true);
  while(choice==0){
  cout<<"\n"<<"Pasirinkite laivu talpinimo metoda:\n";
  cout<<"\n"<<"1. Random\n";
  cout<<"2. Pasirenkant kordinates\n\n";
  cin>>choice;
  switch(choice)
    {
      case 1 : mano.place_ships(false);
                     break;
      case 2 : mano.show_field();PlayerShipPlaceInterface(mano,false);
                     break;
      default : cout<<"\n"<<"Pasirinkimas netinkamas\n";choice=0;
    }
  }
  mano.show_field();

  do {
    do {
      cout <<"\n"<<"Pasirinkite suvio kordinates x,y: ";
      cout << mano.checkWinner();
      cin >> x >> y;
      system("cls");
      mano.shootPlayer(x, y);
      mano.show_field();
    } while (!mano.shootPlayer(x, y));
      system("cls");
      mano.shootPC();
      mano.show_field();
  } while (mano.checkWinner() == "");
  cout << "\n" << "Winner: " << mano.checkWinner() << "\n";
  system("PAUSE");
  return 0;
}
