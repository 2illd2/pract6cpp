#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>

using namespace std;

// Класс Dish - описывает блюдо
class Dish {
private:
    string name;
    string cuisineType;
    double price;
    int quantity;
public:
    Dish(string name, string cuisineType, double price, int quantity)
        : name(name), cuisineType(cuisineType), price(price), quantity(quantity) {}

    // Геттеры и сеттеры
    string getName() const { return name; }
    string getCuisineType() const { return cuisineType; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }
    void setPrice(double newPrice) { price = newPrice; }
};

// Класс Ingredient - описывает ингредиент
class Ingredient {
private:
    string name;
    string category;
    double price;
    int quantity;
public:
    Ingredient(string name, string category, double price, int quantity)
        : name(name), category(category), price(price), quantity(quantity) {}

    // Геттеры и сеттеры
    string getName() const { return name; }
    string getCategory() const { return category; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }
    void setPrice(double newPrice) { price = newPrice; }
};

// Класс Drink - описывает напиток
class Drink {
private:
    string name;
    string type;
    double price;
    int quantity;
public:
    Drink(string name, string type, double price, int quantity)
        : name(name), type(type), price(price), quantity(quantity) {}

    // Геттеры и сеттеры
    string getName() const { return name; }
    string getType() const { return type; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    void setQuantity(int newQuantity) { quantity = newQuantity; }
    void setPrice(double newPrice) { price = newPrice; }
};

// Класс AsianStore - управляет магазином азиатской кухни
class AsianStore {
private:
    vector<Dish> dishes;
    vector<Ingredient> ingredients;
    vector<Drink> drinks;
    vector<string> salesHistory;

public:
    // Методы для управления товарами
    void addProduct(const Dish& dish) { dishes.push_back(dish); }
    void addProduct(const Ingredient& ingredient) { ingredients.push_back(ingredient); }
    void addProduct(const Drink& drink) { drinks.push_back(drink); }
    void removeProduct(string productName);
    void showProducts() const;
    void sellProduct(string productName, int quantity);
    void showSalesHistory() const;
    void updateProduct(string productName, double newPrice, int newQuantity);
    void showInventoryReport() const;
};

// Реализация методов класса AsianStore
void AsianStore::removeProduct(string productName) {
    for (auto it = dishes.begin(); it != dishes.end(); ++it) {
        if (it->getName() == productName) {
            dishes.erase(it);
            return;
        }
    }
    for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
        if (it->getName() == productName) {
            ingredients.erase(it);
            return;
        }
    }
    for (auto it = drinks.begin(); it != drinks.end(); ++it) {
        if (it->getName() == productName) {
            drinks.erase(it);
            return;
        }
    }
    cout << "Товар не найден!" << endl;
}

void AsianStore::showProducts() const {
    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");

    cout << "Блюда в наличии:" << endl;
    for (const auto& dish : dishes) {
        cout << dish.getName() << " - Кухня: " << dish.getCuisineType() << ", Цена: " << dish.getPrice()
            << " - В наличии: " << dish.getQuantity() << endl;
    }
    cout << endl;
    cout << "Ингредиенты в наличии:" << endl;
    for (const auto& ingredient : ingredients) {
        cout << ingredient.getName() << " - Категория: " << ingredient.getCategory() << ", Цена: " << ingredient.getPrice()
            << " - В наличии: " << ingredient.getQuantity() << endl;
    }
    cout << endl;
    cout << "Напитки в наличии:" << endl;
    for (const auto& drink : drinks) {
        cout << drink.getName() << " - Тип: " << drink.getType() << ", Цена: " << drink.getPrice()
            << " - В наличии: " << drink.getQuantity() << endl;
    }
    cout << endl;
}

void AsianStore::sellProduct(string productName, int quantity) {
    for (auto& dish : dishes) {
        if (dish.getName() == productName) {
            if (dish.getQuantity() >= quantity) {
                dish.setQuantity(dish.getQuantity() - quantity);
                salesHistory.push_back(productName + " (блюдо) - " + to_string(quantity) + " шт.");
                cout << "Продажа успешно выполнена!" << endl;
                return;
            }
            else {
                cout << "Недостаточно товара в наличии!" << endl;
                return;
            }
        }
    }
    for (auto& ingredient : ingredients) {
        if (ingredient.getName() == productName) {
            if (ingredient.getQuantity() >= quantity) {
                ingredient.setQuantity(ingredient.getQuantity() - quantity);
                salesHistory.push_back(productName + " (ингредиент) - " + to_string(quantity) + " шт.");
                cout << "Продажа успешно выполнена!" << endl;
                return;
            }
            else {
                cout << "Недостаточно товара в наличии!" << endl;
                return;
            }
        }
    }
    for (auto& drink : drinks) {
        if (drink.getName() == productName) {
            if (drink.getQuantity() >= quantity) {
                drink.setQuantity(drink.getQuantity() - quantity);
                salesHistory.push_back(productName + " (напиток) - " + to_string(quantity) + " шт.");
                cout << "Продажа успешно выполнена!" << endl;
                return;
            }
            else {
                cout << "Недостаточно товара в наличии!" << endl;
                return;
            }
        }
    }
    cout << "Товар не найден!" << endl;
}

void AsianStore::showSalesHistory() const {
    cout << "История продаж:" << endl;
    for (const auto& sale : salesHistory) {
        cout << sale << endl;
    }
    cout << endl;
}

void AsianStore::updateProduct(string productName, double newPrice, int newQuantity) {
    for (auto& dish : dishes) {
        if (dish.getName() == productName) {
            dish.setPrice(newPrice);
            dish.setQuantity(newQuantity);
            cout << "Информация о товаре успешно обновлена!" << endl;
            return;
        }
    }
    for (auto& ingredient : ingredients) {
        if (ingredient.getName() == productName) {
            ingredient.setPrice(newPrice);
            ingredient.setQuantity(newQuantity);
            cout << "Информация о товаре успешно обновлена!" << endl;
            return;
        }
    }
    for (auto& drink : drinks) {
        if (drink.getName() == productName) {
            drink.setPrice(newPrice);
            drink.setQuantity(newQuantity);
            cout << "Информация о товаре успешно обновлена!" << endl;
            return;
        }
    }
    cout << "Товар не найден!" << endl;
}

// Пример использования
int main() {

    SetConsoleCP(1251);
    setlocale(LC_ALL, "Russian");
    AsianStore asianStore;

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить товар" << endl;
        cout << "2. Удалить товар" << endl;
        cout << "3. Изменить товар" << endl;
        cout << "4. Показать все товары" << endl;
        cout << "5. Продать товар" << endl;
        cout << "6. Показать историю продаж" << endl;
        cout << "7. Выйти из программы" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            cout << "Выберите тип товара (1 - блюдо, 2 - ингредиент, 3 - напиток): ";
            int typeChoice;
            cin >> typeChoice;
            if (typeChoice == 1) {
                string name, cuisineType;
                double price;
                int quantity;
                cout << "Введите название блюда: ";
                cin >> name;
                cout << "Введите тип кухни: ";
                cin >> cuisineType;
                cout << "Введите цену: ";
                cin >> price;
                cout << "Введите количество: ";
                cin >> quantity;
                asianStore.addProduct(Dish(name, cuisineType, price, quantity));
            }
            else if (typeChoice == 2) {
                string name, category;
                double price;
                int quantity;
                cout << "Введите название ингредиента: ";
                cin >> name;
                cout << "Введите категорию ингредиента: ";
                cin >> category;
                cout << "Введите цену: ";
                cin >> price;
                cout << "Введите количество: ";
                cin >> quantity;
                asianStore.addProduct(Ingredient(name, category, price, quantity));
            }
            else if (typeChoice == 3) {
                string name, type;
                double price;
                int quantity;
                cout << "Введите название напитка: ";
                cin >> name;
                cout << "Введите тип напитка: ";
                cin >> type;
                cout << "Введите цену: ";
                cin >> price;
                cout << "Введите количество: ";
                cin >> quantity;
                asianStore.addProduct(Drink(name, type, price, quantity));
            }
            else {
                cout << "Неверный выбор типа товара!" << endl;
            }
            break;
        }
        case 2: {
            string productName;
            cout << "Введите название товара, который хотите удалить: ";
            cin >> productName;
            asianStore.removeProduct(productName);
            break;
        }
        case 3: {
            string productName;
            double newPrice;
            int newQuantity;
            cout << "Введите название товара, который хотите изменить: ";
            cin >> productName;
            cout << "Введите новую цену: ";
            cin >> newPrice;
            cout << "Введите новое количество: ";
            cin >> newQuantity;
            asianStore.updateProduct(productName, newPrice, newQuantity);
            break;
        }
        case 4: {
            asianStore.showProducts();
            break;
        }
        case 5: {
            string productName;
            int quantity;
            cout << "Введите название товара, который хотите продать: ";
            cin >> productName;
            cout << "Введите количество: ";
            cin >> quantity;
            asianStore.sellProduct(productName, quantity);
            break;
        }
        case 6: {
            asianStore.showSalesHistory();
            break;
        }
        case 7: {
            cout << "До свидания!" << endl;
            return 0;
        }
        default: {
            cout << "Неверный выбор действия!" << endl;
            break;
        }
        }
    } while (true);

    return 0;
}
