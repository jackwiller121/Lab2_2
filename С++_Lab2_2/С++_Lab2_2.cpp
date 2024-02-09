#include <iostream>
#include "windows.h"

class Node {
public:
    Node(std::string currectName, int currectNum, int currectTime) {
        nameTask = currectName;
        numberTask = currectNum;
        timeTask = currectTime;
    }

    std::string nameTask;
    int timeTask;
    int numberTask;

    Node* nextTask;
    Node* previousTask;
};

class SpecialList {
public:
    int sizeCurrent = 0;
    Node* firstTask;
    Node* lastTask;
    Node* currentTask; 
    SpecialList() {
        firstTask = new Node("задача", 1, rand() % 5 + 1);
        firstTask->nextTask = NULL;
        firstTask->previousTask = NULL;
        lastTask = firstTask;

        sizeCurrent++;
    }

    void addRandomTask() {
        system("cls");
        Node* t_node = new Node(lastTask->nameTask, lastTask->numberTask, lastTask->timeTask);
        lastTask->nextTask = t_node;
        t_node->previousTask = lastTask;
        t_node->nextTask = NULL;
        t_node->nameTask = "задача";
        t_node->numberTask++;
        t_node->timeTask = rand() % 5 + 1;
        lastTask = t_node;

        sizeCurrent++;

        std::cout << "Задача: " << t_node->nameTask << ", со временем выполнения: " << t_node->timeTask << "секунд(ы), была сгенерирована!" << std::endl << std::endl;
    }

    void push(std::string nameTask, int timeTask) {
        system("cls");
        Node* t_node = new Node(nameTask, lastTask->numberTask, timeTask);
        lastTask->nextTask = t_node;
        t_node->previousTask = lastTask;
        t_node->nextTask = NULL;
        t_node->numberTask++;
        lastTask = t_node;

        sizeCurrent++;
        std::cout << "Задача: " << nameTask << ", с временем работы: " << timeTask << " секунд(ы), была добавлена в конец очереди!" << std::endl << std::endl;

    }

    void goForward() {
        system("cls");
        currentTask = firstTask;

        while (currentTask->nextTask != NULL) {
            std::cout << "Задача: " << currentTask->nameTask << " " << currentTask->numberTask << std::endl;
            for (int i = 1; i <= currentTask->timeTask; i++) {
                Sleep(1000);
                std::cout << "Выполнение: " << i << " секунд" << std::endl;
            }
            std::cout << "Задача выполнена" << std::endl;
            std::cout << sizeCurrent - 1 << " задач осталось" << std::endl << std::endl;
            currentTask = currentTask->nextTask;

            delete currentTask->previousTask;
            currentTask->previousTask == NULL;
            sizeCurrent--;

            if (currentTask->nextTask == NULL) { 
                std::cout << "Задача: " << currentTask->nameTask << " " << currentTask->numberTask << std::endl;
                for (int i = 1; i <= currentTask->timeTask; i++) {
                    Sleep(1000);
                    std::cout << "Выполнение: " << i << " секунд" << std::endl;
                }
                std::cout << "Задача выполнена" << std::endl;
                std::cout << "Больше задач нет" << std::endl << std::endl;

                system("pause");

                delete currentTask;
                currentTask == NULL;

                sizeCurrent--;
                return;
            }
        }
    }

    void goBackwards() {
        system("cls");
        currentTask = lastTask;
        while (currentTask->previousTask != NULL) {
            std::cout << "Задача: " << currentTask->nameTask << " " << currentTask->numberTask << std::endl;
            for (int i = 1; i <= currentTask->timeTask; i++) {
                Sleep(1000);
                std::cout << "Выполнение: " << i << " секунд" << std::endl;
            }
            std::cout << "Задача выполнена" << std::endl;
            std::cout << sizeCurrent - 1 << " задач осталось" << std::endl << std::endl;

            currentTask = currentTask->previousTask;

            delete currentTask->nextTask;
            currentTask->nextTask == NULL;
            sizeCurrent--;

            if (currentTask->previousTask == NULL) {
                std::cout << "Задача: " << currentTask->nameTask << " " << currentTask->numberTask << std::endl;
                for (int i = 1; i <= currentTask->timeTask; i++) {
                    Sleep(1000);
                    std::cout << "Выполнение: " << i << " секунд" << std::endl;
                }
                std::cout << "Задача выполнена" << std::endl;
                std::cout << "Задач больше нет" << std::endl;

                system("pause");

                delete currentTask;
                currentTask == NULL;
                sizeCurrent--;
                return;
            }
        }
    }

    void getFirst() {
        system("cls");
        std::cout << "Название: " << firstTask->nameTask << "\t";
        std::cout << "Номер: " << firstTask->numberTask << "\t";
        std::cout << "Cекунд на выполнение: " << firstTask->timeTask << std::endl << std::endl;
    }
    void getLast() {
        system("cls");
        std::cout << "Название: " << lastTask->nameTask << "\t";
        std::cout << "Номер: " << lastTask->numberTask << "\t";
        std::cout << "Cекунд на выполнение: " << lastTask->timeTask << std::endl << std::endl;
    }
    void getCurrent() {
        system("cls");
        std::cout << "Название: " << currentTask->nameTask << "\t";
        std::cout << "Номер: " << currentTask->numberTask << "\t";
        std::cout << "Cекунд на выполнение: " << currentTask->timeTask << std::endl << std::endl;
    }
    void deleteFirst() {
        system("cls");
        std::cout << "Первая задача была удалена" << std::endl;
        firstTask = firstTask->nextTask;
        delete firstTask->previousTask;
        firstTask->previousTask = NULL;
        sizeCurrent--;
    }
    void deleteLast() {
        system("cls");
        std::cout << "Последняя задача была удалена" << std::endl;
        lastTask = lastTask->previousTask;
        delete lastTask->nextTask;
        lastTask->nextTask = NULL;
        sizeCurrent--;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(NULL));

    int MenuStatus = 0;
    SpecialList list;
    while (MenuStatus != 10) {
        
        std::cout << "Выбери действие:" << std::endl << std::endl;
        std::cout << "1. Добавить случайную задачу" << std::endl << "2. Добавить свою задачу" << std::endl << "3. Удалить первую задачу" << std::endl << "4. Удалить последнию задачу" << std::endl << "5. Начать с начала" << std::endl;
        std::cout << "6. Начать с конца" << std::endl << "7. Показать первую задачу" << std::endl << "8. Показать последнию задачу" << std::endl << "9. Показать текущию задачу" << std::endl << "10. Выход" << std::endl << std::endl;
        std::cin >> MenuStatus;
        if (MenuStatus == 1) list.addRandomTask();
        if (MenuStatus == 2) 
        {
            system("cls");
            std::string MenuNameTask;
            int MenuTimeTask;
            std::cout << "Напишите имя задачи: ";
            std::cin >> MenuNameTask;
            system("cls");
            std::cout << "Напишите время выполнения задачи: ";
            std::cin >> MenuTimeTask;
            system("cls");
            list.push(MenuNameTask, MenuTimeTask);
        }
        if (MenuStatus == 3)  list.deleteFirst(); 
        if (MenuStatus == 4)  list.deleteLast(); 
        if (MenuStatus == 5) 
        {
            list.goForward();
            MenuStatus = 0;
        }
        if (MenuStatus == 6) 
        {
            list.goBackwards();
            MenuStatus = 0;
        }
        if (MenuStatus == 7)  list.getFirst(); 
        if (MenuStatus == 8)  list.getLast(); 
        if (MenuStatus == 9)  list.getFirst(); 
    }
}
