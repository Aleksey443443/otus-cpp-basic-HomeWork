#include <iostream>
#include <windows.h>
#include <ctime>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <memory>
#include <cstdlib>


using namespace std;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); // создание хендла потока вывода
const int width = 50, height = 30; // размеры поля, по которому бегает зверьё


class herbivore{

	int array_X =  rand() % (width - 2) + 1; // установка стартовой абсциссы зверья
	int array_Y = rand() % (height - 2) + 1; // установка стартовой ординаты зверья
	int dx = 1, dy = 0; // создание смещений по осям для движения зверья
    char head = 1; // символ для отображения  зверья
    COORD c; // объект для хранения координат

public:
herbivore(){
    SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зверья
	SetConsoleTextAttribute(h, 10); // устанавливаем зеленый цвет для отрисовки зверья
	putchar(head); // отображаем символ головы зверья
         
		dx =-1+ rand()%3; //задаём случайное смещение зверья по оси х
        dy = -1+ rand()%3;//задаём случайное смещение зверья по оси у

		int X = array_X + dx; // определяем значение абсциссы зверья после смещения
		int Y = array_Y + dy; // то же самое для ординаты
		

		c.X = array_X; // устанавливаем в объект координат позицию хвоста зверья
		c.Y = array_Y;
		SetConsoleCursorPosition(h, c); // двигаем туда курсор
		putchar(' '); // и отображаем пробел (затирка хвоста)


		c.X = array_X = X; // устанавливаем новую позицию зверья
		c.Y = array_Y = Y;
		
		SetConsoleCursorPosition(h, c); // двигаем туда курсора
		putchar(head); }
		
		
~herbivore(){}



	int GetX(){
		int a;
		a=c.X;
		return a;	
	}	
	int GetY(){
		int b;
		b=c.Y;
		return b;	
	}	
		

		

int play(){
	
    SetConsoleCursorPosition(h, c); // отправляем курсор на позицию зверья
	SetConsoleTextAttribute(h, 10); // устанавливаем зеленый цвет для отрисовки зверья
	putchar(head); // отображаем символ головы зверья
    dx =-1+ rand()%3; //задаём случайное смещение зверья по оси х
     dy = -1+ rand()%3;//задаём случайное смещение зверья по оси у

		int X = array_X + dx; // определяем значение абсциссы зверья после смещения
		int Y = array_Y + dy; // то же самое для ординаты
		

				c.X = array_X; // устанавливаем в объект координат позицию хвоста зверья
				c.Y = array_Y;
				SetConsoleCursorPosition(h, c); // двигаем туда курсор
				putchar(' '); // и отображаем пробел (затирка хвоста)


				c.X = array_X = X; // устанавливаем новую позицию зверья
				c.Y = array_Y = Y;
		
				SetConsoleCursorPosition(h, c); // двигаем туда курсора
				putchar(head); // отображаем символ зверья
		

 
}	
};

void do_step(vector<herbivore>& v){
	for (size_t i =0; i<v.size();i++){
	v[i].play();
	
	}
}

void fill_board(size_t board[width][height], vector<herbivore>& v){
	for(size_t i=0; i<width;++i){
		for(size_t j=0;j<height;++j){
			board[i][j]=-1;
		}
	}

	for(size_t i=0; i<v.size();++i){
		for(size_t j=0; i<v.size();++j){
	board[v[i].GetX()][v[j].GetY()]=i;
	
		}
	
	}
}


void find_collissions(size_t board[width][height], vector<herbivore>& v){


		static int s=0;
	s++;
	int c=5;
		if(c==s){

vector<std::unique_ptr<herbivore>> objects;// 	ТУТ Я ЧУТКА ЗАХАРДКОДИЛ, ЧТО БЫ ПОСМОТРЕТЬ КАК БУДУТ СОЗДАВАТЬСЯ НОВЫЕ ОБЪЕКТЫ КЛАССА, НО ЧТО ТО ПОШЛО НЕ ТАК..

objects.emplace_back(std::make_unique<herbivore>());
}
}


int main()
{
herbivore hr1;// создание зверя 1
herbivore hr2;

vector <herbivore> v;

size_t board[width][height];

	    srand(time(0)); // запуск генератора случайных чисел
     	rand(); // холостой ход генератора случаный чисел
        system("mode con cols=51 lines=31"); // установка размеров окна консоли
         MoveWindow(GetConsoleWindow(), 50, 50, 2000, 2000, true); // установка стартовой позиции окна консоли (50 и 50 - это пиксели
      	// относительно верхнего левого угла монитора

        CONSOLE_CURSOR_INFO cci = { sizeof(cci), false }; // создание параметров на отображение курсора
        SetConsoleCursorInfo(h, &cci); //связывание параметров и хендла
        SetConsoleTextAttribute(h, 4); // установка цвета, которым рисуется рамка поля
      	for (int y = 0; y < height; y++) // стандартный двойной цикл на отрисовку рамки
       	{
		for (int x = 0; x < width; x++)
		{
			char s;
			if (x == 0 && y == 0) // в верхнем левом углу поля - символ соответствующего угла
				s = 218;
			else if (x == 0 && y == height - 1) // нижний левый угол
				s = 192;
			else if (y == 0 && x == width - 1) // верхний правый угол
				s = 191;
			else if (y == height - 1 && x == width - 1) // нижний правый угол
				s = 217;
			else if (y == 0 || y == height - 1) // верхняя и нижняя граница поля
				s = 196;
			else if (x == 0 || x == width - 1) // левая и правая граница поля
				s = 179;
			else s = ' '; // во всех остальных случаях должен быть просто пробел (означает пустую область поля)
			putchar(s); // выводим символ
		}
		cout << endl;
     	}

     	int sleep_time = 100; // переменная частоты кадров 
        bool flag = true; // переменная для управления ходом цикла

       
   
	do // собственно цикл игры
	{
	Sleep(sleep_time); // задержка потока программы на заданный ранее интервал

    hr1.play();//игра зверя 1
    hr2.play();

  
   

do_step(v);
fill_board(board, v);
find_collissions(board,v);
 

    }
   
    while (flag); // выходим из цикла, если сброшена управляющая переменная
    system("cls"); // очищаем экран
	system("pause");



}


