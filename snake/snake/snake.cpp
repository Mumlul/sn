#include <iostream>
#include <conio.h>
#include <windows.h> 

struct Snake_nn {
    int x, y;
    Snake_nn* next;
};
int width=25, height = 10;
class Snake
{
public:
    void Drawmap() {
        //Проприсовка всего поля
        system("cls"); 
        for (int i = 0; i < width; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) { 
                if (x == 0) std::cout << "|";
                if (x == head->x && y == head->y)
                    std::cout << '0';
                else if(Prov_1(x,y)) std::cout << 'o';
                std::cout << " "; 
            }
            std::cout << "|" << std::endl; 
        }
        for (int i = 0; i < width; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
    void Movement() {
        //выбор направления для хода
        if (_kbhit) {
            switch (_getch())
            {
            case 'w':
                direction = 'u';
                break;
            case 'a':
                direction = 'l';
                break;
            case 's':
                direction = 'd';
                break;
            case 'd':
                direction = 'r';
                break;
            default:
                break;
            }
        }
    }

    void Logic() {
        int newX = head->x;
        int newY = head->y;

        switch (direction) {
        case 'u': newY--; break;
        case 'l': newX--; break;
        case 'd': newY++; break;
        case 'r': newX++; break;
        }

        // Проверка на ДТП
        if (newX < 0 || newX >= width || newY < 0 || newY >= height || Prov_1(newX, newY)) {
            //Добавить метод завершения игры
            return;
        }
        Snake_nn* newHead = new Snake_nn{ newX, newY, head };
        head = newHead;
        if (tail != nullptr) {
            Snake_nn* temp = tail;
            tail = tail->next;
            delete temp;
        }
    }

    bool Prov_1(int x, int y) {
        Snake_nn* current = head->next;
        while (current != nullptr) {
            if (current->x == x && current->y == y) {
                return true;
            }
            current = current->next;
        }
        return false;
    }



    Snake() {
        //Конструктор и создание змейки
        head = new Snake_nn{ width / 2, height / 2,nullptr };
        tail = head;
        push_back(tail->x, tail->y--);
        direction = ' ';
    }

    void Food() {
        //создание координат для еды
        fx= rand() % (width - 2) + 1;
        fy= rand() % (height - 2) + 1;
    }

    void push_back(int x, int y) {
        //Добавления в задний проход
        Snake_nn* node = new Snake_nn{ x, y, nullptr };
        if (tail == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }

private:
    //поля
    Snake_nn* head;
    Snake_nn* tail;
    bool gameover = false;
    int fx, fy;
    int score;
    char direction;
};



int main()
{
    Snake snakeGame;          
    int i = 0;
    while (i != 1) {
        snakeGame.Drawmap();
        snakeGame.Movement();
        snakeGame.Logic();
        Sleep(100);
    }
   
    
}


