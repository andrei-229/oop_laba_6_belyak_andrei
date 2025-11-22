#include <iostream>
#include <string>
#include <limits>
#include "editor.h"

void printMenu() {
    std::cout << "\n╔═══════════════════════════════════════════════╗" << std::endl;
    std::cout << "║   Редактор подземелья Balagur Fate 3         ║" << std::endl;
    std::cout << "╚═══════════════════════════════════════════════╝" << std::endl;
    std::cout << "1. Добавить NPC" << std::endl;
    std::cout << "2. Показать всех NPC" << std::endl;
    std::cout << "3. Сохранить в файл" << std::endl;
    std::cout << "4. Загрузить из файла" << std::endl;
    std::cout << "5. Запустить боевой режим" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

void printNPCTypes() {
    std::cout << "\nДоступные типы NPC:" << std::endl;
    std::cout << "1. Dragon (Дракон)" << std::endl;
    std::cout << "2. Frog (Жаба)" << std::endl;
    std::cout << "3. Knight (Странствующий рыцарь)" << std::endl;
    std::cout << "\nПравила боя:" << std::endl;
    std::cout << "  - Жаба ест всех (включая других жаб)" << std::endl;
    std::cout << "  - Рыцарь убивает драконов" << std::endl;
    std::cout << "  - Дракон убивает рыцарей" << std::endl;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    Editor editor;
    int choice;
    
    std::cout << "Добро пожаловать в редактор подземелья Balagur Fate 3!" << std::endl;
    printNPCTypes();
    
    while (true) {
        printMenu();
        
        if (!(std::cin >> choice)) {
            std::cout << "Ошибка ввода! Введите число." << std::endl;
            clearInput();
            continue;
        }
        clearInput();
        
        try {
            switch (choice) {
                case 1: {
                    std::string type, name;
                    double x, y;
                    
                    std::cout << "\nВведите тип NPC (1-Dragon, 2-Frog, 3-Knight): ";
                    std::getline(std::cin, type);
                    
                    std::cout << "Введите уникальное имя NPC: ";
                    std::getline(std::cin, name);
                    
                    std::cout << "Введите координату X (0-500): ";
                    if (!(std::cin >> x)) {
                        std::cout << "Ошибка ввода координаты X!" << std::endl;
                        clearInput();
                        break;
                    }
                    
                    std::cout << "Введите координату Y (0-500): ";
                    if (!(std::cin >> y)) {
                        std::cout << "Ошибка ввода координаты Y!" << std::endl;
                        clearInput();
                        break;
                    }
                    clearInput();
                    
                    editor.addNPC(type, name, x, y);
                    break;
                }
                
                case 2: {
                    editor.printAll();
                    break;
                }
                
                case 3: {
                    std::string filename;
                    std::cout << "\nВведите имя файла для сохранения: ";
                    std::getline(std::cin, filename);
                    
                    editor.saveToFile(filename);
                    break;
                }
                
                case 4: {
                    std::string filename;
                    std::cout << "\nВведите имя файла для загрузки: ";
                    std::getline(std::cin, filename);
                    
                    editor.loadFromFile(filename);
                    break;
                }
                
                case 5: {
                    double range;
                    std::cout << "\nВведите дальность боя (в метрах): ";
                    if (!(std::cin >> range)) {
                        std::cout << "Ошибка ввода дальности!" << std::endl;
                        clearInput();
                        break;
                    }
                    clearInput();
                    
                    if (range <= 0) {
                        std::cout << "Дальность должна быть положительным числом!" << std::endl;
                        break;
                    }
                    
                    editor.startBattle(range);
                    break;
                }
                
                case 0: {
                    std::cout << "\nДо свидания!" << std::endl;
                    return 0;
                }
                
                default: {
                    std::cout << "\nНеверный выбор! Попробуйте снова." << std::endl;
                    break;
                }
            }
        } catch (const std::exception& e) {
            std::cout << "Ошибка: " << e.what() << std::endl;
        }
    }
    
    return 0;
}
