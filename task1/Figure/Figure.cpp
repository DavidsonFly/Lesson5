// Figure.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>



class Figure
{
private:
    std::string m_name;
    int m_count;

public:
    Figure(std::string name = "", int count = 0)
        :m_name(name), m_count(count)
    {

    }

    std::string get_name()
    {
        return m_name;

    }

    int get_count()
    {
        return m_count;
    }
};

class Triangle : public Figure
{
public:
   
    Triangle(std::string name = "", int count = 0)
        :Figure(name,count)
    {

    }

};

class Quadrangle : public Figure
{
public:
   

    Quadrangle(std::string name = "", int count = 0)
        :Figure(name,count)
    {

    }
};

int main()
{
    setlocale(LC_ALL, "Rus");

    Figure fig;
    
    Triangle figure1("Треугольник", 3);
    Quadrangle figure2("Квадрат", 4);

    std::cout << "Количество сторон:" << std::endl;
    std::cout << fig.get_name() << " Фигура: " << fig.get_count() << std::endl;
    std::cout << figure1.get_name() << ":" << figure1.get_count() << std::endl;
    std::cout << figure2.get_name() << ":" << figure2.get_count() << std::endl;
    


    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
