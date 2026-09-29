#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Структура для зберігання інформації про книгу та вказівника на наступний елемент
typedef struct Book {
    char title[100];     // назва книги
    float price;         // ціна
    int pages;           // число сторінок
    char language[50];   // мова
    float weight;        // вага (в кілограмах)
    int year;            // рік видання
    struct Book* next;   // вказівник на наступну книгу у списку
} Book;

// Функція для створення нового елемента списку (книги)
Book* createBook(const char* title, float price, int pages, const char* language, float weight, int year) {
    Book* newBook = (Book*)malloc(sizeof(Book));
    if (newBook == NULL) {
        printf("Помилка виділення пам'яті!\n");
        exit(1);
    }
    
    // Копіюємо рядки безпечно
    strncpy(newBook->title, title, sizeof(newBook->title) - 1);
    newBook->title[sizeof(newBook->title) - 1] = '\0';
    
    strncpy(newBook->language, language, sizeof(newBook->language) - 1);
    newBook->language[sizeof(newBook->language) - 1] = '\0';
    
    newBook->price = price;
    newBook->pages = pages;
    newBook->weight = weight;
    newBook->year = year;
    newBook->next = NULL;
                                                                                                                     
    return newBook;
}

// Функція для додавання книги в кінець списку
void appendBook(Book** head, const char* title, float price, int pages, const char* language, float weight, int year) {
    Book* newBook = createBook(title, price, pages, language, weight, year);
    
    // Якщо список порожній, нова книга стає головою списку
    if (*head == NULL) {
        *head = newBook;
        return;
    }
    
    // Інакше йдемо до кінця списку і додаємо книгу туди
    Book* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newBook;
}

// Функція для виведення всього списку книг на екран
void printBooks(Book* head) {
    Book* temp = head;
    int count = 1;
    
    printf("--- Серія книг про Гаррі Поттера ---\n\n");
    
    while (temp != NULL) {
        printf("Книга #%d:\n", count++);
        printf("  Назва: %s\n", temp->title);
        printf("  Ціна: %.2f грн\n", temp->price);
        printf("  Кількість сторінок: %d\n", temp->pages);
        printf("  Мова: %s\n", temp->language);
        printf("  Вага: %.2f кг\n", temp->weight);
        printf("  Рік видання: %d\n\n", temp->year);
        
        temp = temp->next;
    }
}

// Функція для звільнення виділеної пам'яті
void freeBooks(Book* head) {
    Book* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp); // Звільняємо пам'ять поточного вузла
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    // Вказівник на початок списку
    Book* library = NULL;
    
    // Наповнюємо список книгами
    appendBook(&library, "Гаррі Поттер і філософський камінь", 350.50, 318, "Українська", 0.45, 1997);
    appendBook(&library, "Гаррі Поттер і таємна кімната", 360.00, 352, "Українська", 0.48, 1998);
    appendBook(&library, "Гаррі Поттер і в'язень Азкабану", 380.00, 384, "Українська", 0.52, 1999);
    appendBook(&library, "Гаррі Поттер і келих вогню", 450.75, 672, "Українська", 0.85, 2000);
    appendBook(&library, "Гаррі Поттер і Орден Фенікса", 470.00, 816, "Українська", 0.95, 2003);
    
    // Виводимо інформацію на екран
    printBooks(library);
    
    // Обов'язково очищаємо пам'ять перед завершенням програми
    freeBooks(library);
    
    return 0;
}