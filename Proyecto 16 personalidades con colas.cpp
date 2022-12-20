/*Programa Realizado por Jonathán Josué Florián Sipaque 7490-20-3403 para Programación III 2022*/
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <queue>

#define color SetConsoleTextAttribute

using namespace std;

void gotoxy();
void menu();
void crear_cuadro();
void llenar_pila();
void mostrar_tabla();
void volver();

HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);

queue<string> personalidad;

void gotoxy(int x, int y) // Ancho,Alto
{
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

int main()
{
    system("title Tabla de las 16 personalidades");
    menu();
    return 0;
}

void menu()
{
    int opcion;
    crear_cuadro();
    gotoxy(45, 3);
    cout << "16 personalidades" << endl;
    gotoxy(35, 6);
    cout << "1. Mostrar tabla de compatibilidad." << endl;
    gotoxy(35, 7);
    cout << "0. Salir del programa." << endl;
    gotoxy(35, 8);
    cout << "Ingrese la opcion que desea ejecutar: " << endl;
    gotoxy(35, 9);
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        mostrar_tabla();
        break;
    case 0:
        gotoxy(38, 16);
        color(hcon, 13);
        cout << "Gracias por usar este programa!" << endl;
        color(hcon, 7);
        gotoxy(35, 27);
        cout << "Ingrese cualquier tecla para salir... " << endl;
        gotoxy(72, 27);
        getch();
        exit(1);
        break;
    default:
        gotoxy(37, 16);
        color(hcon, 4);
        cout << "Ingrese un numero valido del menu" << endl;
        color(hcon, 7);
        break;
    }
    volver();
}

void mostrar_tabla()
{
    crear_cuadro();
    gotoxy(25, 3);
    cout << "\tNivel de compatibilidad entre personalidades" << endl;
    gotoxy(9, 6);
    cout << "Mismo perfil: " << char(219) << char(219) << " "
         << "Grado muy elevado de compatibilidad: ";
    color(hcon, 1);
    cout << char(219) << char(219) << " ";
    color(hcon, 7);
    cout << "Similares en caracter: ";
    color(hcon, 2);
    cout << char(219) << char(219) << " " << endl;
    gotoxy(20, 7);
    color(hcon, 7);
    cout << "Comparten ciertos aspectos: ";
    color(hcon, 6);
    cout << char(219) << char(219) << " ";
    color(hcon, 7);
    cout << "Mayor potencial de conflictos: ";
    color(hcon, 4);
    cout << char(219) << char(219) << endl;
    color(hcon, 7);
    // Esto es para mostrar las filas de personalidades
    llenar_pila();
    int p = 10;
    for (int i = 0; i < 16; i++)
    {
        gotoxy(8, p);
        if (!personalidad.empty())
        {
            cout << personalidad.front();
            personalidad.pop();
        }
        p++;
    }
    // Esto es para mostrar las columnas de personalidades
    llenar_pila();
    p = 13;
    for (int i = 0; i < 16; i++)
    {
        gotoxy(p, 9);
        if (!personalidad.empty())
        {
            cout << personalidad.front();
            personalidad.pop();
        }
        p += 5;
    }
    // Esto es para agregar los cuadros
    int c = 1;
    for (int i = 10; i < 26; i++)
    {
        for (int j = 14; j < 94;)
        {
            gotoxy(j, i);
            if (((c == 1) || (c == 18) || (c == 35) || (c == 52) || (c == 69) || (c == 86) || (c == 103) || (c == 120)) ||
                ((c == 137) || (c == 154) || (c == 171) || (c == 188) || (c == 205) || (c == 222) || (c == 239) || (c == 256)))
            {
                color(hcon, 7);
            }
            else if ((((c == 2) || (c == 3) || (c == 5) || (c == 17) || (c == 20) || (c == 25) || (c == 33) || (c == 39) || (c == 48) || (c == 50) || (c == 51) || (c == 56) || (c == 65)) ||
                      ((c == 70) || (c == 71) || (c == 82) || (c == 85) || (c == 88) || (c == 99) || (c == 101) || (c == 111) || (c == 116) || (c == 118) || (c == 119) || (c == 130))) ||
                     (((c == 138) || (c == 140) || (c == 153) || (c == 155) || (c == 158) || (c == 170) || (c == 172) || (c == 175) || (c == 180) || (c == 185) || (c == 187) || (c == 193)) ||
                      ((c == 206) || (c == 208) || (c == 218) || (c == 221) || (c == 223) || (c == 235) || (c == 238) || (c == 240) || (c == 243) || (c == 253) || (c == 255))))
            {
                color(hcon, 1);
            }
            else if ((((c == 4) || (c == 7) || (c == 13) || (c == 16) || (c == 19) || (c == 22) || (c == 24) || (c == 28) || (c == 36) || (c == 37) || (c == 40) || (c == 45) || (c == 49) || (c == 54) || (c == 55) || (c == 60) || (c == 66) || (c == 67)) ||
                      ((c == 72) || (c == 78) || (c == 84) || (c == 87) || (c == 90) || (c == 91) || (c == 97) || (c == 104) || (c == 107) || (c == 112) || (c == 114) || (c == 117) || (c == 123) || (c == 124) || (c == 134) || (c == 139))) ||
                     (((c == 141) || (c == 142) || (c == 150) || (c == 156) || (c == 157) || (c == 159) || (c == 168) || (c == 169) || (c == 174) || (c == 176) || (c == 186) || (c == 189) || (c == 191) || (c == 192) || (c == 201)) ||
                      ((c == 202) || (c == 204) || (c == 207) || (c == 213) || (c == 217) || (c == 219) || (c == 224) || (c == 231) || (c == 234) || (c == 236) || (c == 237) || (c == 241) || (c == 251) || (c == 252) || (c == 254))))
            {
                color(hcon, 2);
            }
            else if ((((c == 6) || (c == 8) || (c == 9) || (c == 14) || (c == 21) || (c == 23) || (c == 26) || (c == 27) || (c == 34) || (c == 41) || (c == 44) || (c == 47) || (c == 53) || (c == 57) || (c == 59) || (c == 64) || (c == 68) || (c == 75)) ||
                      ((c == 77) || (c == 80) || (c == 81) || (c == 89) || (c == 92) || (c == 94) || (c == 100) || (c == 102) || (c == 108) || (c == 109) || (c == 113) || (c == 115) || (c == 122) || (c == 127) || (c == 129))) ||
                     (((c == 132) || (c == 143) || (c == 144) || (c == 146) || (c == 149) || (c == 152) || (c == 160) || (c == 164) || (c == 166) || (c == 167) || (c == 173) || (c == 178) || (c == 179) || (c == 184) || (c == 190) || (c == 195)) ||
                      ((c == 197) || (c == 199) || (c == 203) || (c == 209) || (c == 214) || (c == 215) || (c == 220) || (c == 227) || (c == 229) || (c == 232) || (c == 233) || (c == 244) || (c == 245) || (c == 247) || (c == 249))))
            {
                color(hcon, 6);
            }
            else if ((((c == 10) || (c == 11) || (c == 12) || (c == 15) || (c == 29) || (c == 30) || (c == 31) || (c == 32) || (c == 38) || (c == 42) || (c == 43) || (c == 46) || (c == 58) || (c == 61) || (c == 62) || (c == 63) || (c == 73)) ||
                      ((c == 74) || (c == 76) || (c == 79) || (c == 83) || (c == 93) || (c == 95) || (c == 96) || (c == 98) || (c == 105) || (c == 106) || (c == 110) || (c == 121) || (c == 125) || (c == 126) || (c == 128) || (c == 131))) ||
                     (((c == 133) || (c == 135) || (c == 136) || (c == 145) || (c == 147) || (c == 148) || (c == 151) || (c == 161) || (c == 162) || (c == 163) || (c == 165) || (c == 177) || (c == 181) || (c == 182) || (c == 183) || (c == 194)) ||
                      ((c == 196) || (c == 198) || (c == 200) || (c == 210) || (c == 211) || (c == 212) || (c == 216) || (c == 225) || (c == 226) || (c == 228) || (c == 230) || (c == 242) || (c == 246) || (c == 248) || (c == 250))))
            {
                color(hcon, 4);
            }
            cout << char(219) << char(219);
            color(hcon, 7);
            j += 5;
            c++;
        }
    }
    color(hcon, 7);
}

void volver()
{
    gotoxy(30, 27);
    cout << "Presione cualquier tecla para volver al menu... ";
    gotoxy(77, 27);
    getch();
    menu();
}

void llenar_pila()
{
    string personal[16] = {"ISTJ", "ISFJ", "ESTJ", "ESFJ", "ISTP", "ISFP", "ESTP", "ESFP", "INFJ", "INFP", "ENFP", "ENFJ", "INTJ", "INTP", "ENTP", "ENTJ"};
    for (int i = 0; i < 16; i++)
    {
        personalidad.push(personal[i]);
    }
}

void crear_cuadro()
{
    system("cls");
    // Esto crea las lineas horizontales
    gotoxy(1, 1);
    cout << char(201);
    gotoxy(1, 28);
    cout << char(200);
    for (int i = 2; i < 100; i++)
    {
        gotoxy(i, 1);
        cout << char(205);
        gotoxy(i, 28);
        cout << char(205);
    }
    // Esto crea las lineas verticales
    gotoxy(100, 1);
    cout << char(187);
    gotoxy(100, 28);
    cout << char(188);
    for (int i = 2; i < 28; i++)
    {
        gotoxy(1, i);
        cout << char(186);
        gotoxy(100, i);
        cout << char(186);
    }
}
/*
Colores
Blanco: las cuatro letras son iguales NUMERO 7
Azul: las primeras 3 letras son iguales NUMERO 1
Verde: las primeras dos letras son iguales NUMERO 2
Amarillo: la primera letra es igual NUMERO 6
Naranja: ninguna letra es igual NUMERO 4
*/