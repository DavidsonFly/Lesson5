// Figures_methods.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>

class Figure
{
protected:
    std::string name;
    int sides;

public:
    Figure(std::string name, int sides): name(name), sides(sides){}

    virtual void print_info()
    {
        std::cout << name << ":" << std::endl;
        std::cout << "Правильная" << std::endl;
        std::cout << "Количество сторон:" << " " << sides << std::endl;
    }

    virtual bool check()
    {
        return sides == 0;
    }
};

class Triangle :public Figure
{
protected:
    std::vector <double> lengths;
    std::vector <double> angles;

public:
    Triangle(std::string name,double sideA, double sideB, double sideC, double angleA, double angleB, double angleC)
        :Figure(name,3), lengths({sideA, sideB, sideC}), angles({angleA, angleB, angleC,}) {}

    void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны:";
        char sideNames[] = { 'a', 'b', 'c' };
        for (int i = 0; i < lengths.size(); ++i)
        {
            std::cout << sideNames[i] << " = " << lengths[i];
            if (i != lengths.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;

        std::cout << "Углы:";
        char angleNames[] = { 'A', 'B', 'C' };
        for ( int i = 0; i < angles.size(); ++i)
        {
            std::cout << angleNames[i] << " = " << angles[i];
            if (i!= angles.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    bool check() override
    {
        if (!Figure::check())
        {
            double sum = 0;
            for (const auto& angle : angles)
            {
                sum += angle;
            }
            return sum == 180.0;
        }
        return false;
    }
};

class RightTriangle : public Triangle
{

   public:
    RightTriangle(std::string name,double sideA, double sideB)
        : Triangle("Прямоугольный треугольник", sideA, sideB, std::sqrt(sideA* sideA + sideB * sideB), 90.0, 45.0, 45.0) {}


    bool check() override 
    {
        return Triangle::check() && angles[2] == 90.0;
    }
};

class Identical_triangle : public Triangle
{
public:
    Identical_triangle(std::string name, double baseAngle, double sides)
        : Triangle("Равнобедренный треугольник", sides, sides, sides, baseAngle, baseAngle, 180.0 - 2 * baseAngle) {}


    bool check() override 
    {
        return Triangle::check() && lengths[0] == lengths[1] && angles[0] == angles[2];
    }
};

class Equal_triangle :public Triangle
{
public:
    Equal_triangle(const std::string& name, double side)
        : Triangle(name, side, side, side ,  60.0, 60.0, 60.0 ) {}

    bool check() override {
        return Triangle::check() && lengths[0] == lengths[1] && lengths[1] == lengths[2];
    }
};

//---------------------------------------------------------------------------------------------------//

class Quadrilateral :public Figure
{
protected:
    std::vector <double> lengths;
    std::vector <double> angles;

public:
    Quadrilateral(std::string name, double sideA, double sideB, double sideC,double sideD,double angleA, double angleB, double angleC, double angleD)
        :Figure(name, 4), lengths({ sideA,sideB,sideC,sideD }), angles({ angleA, angleB, angleC, angleD }){}

        void print_info() override
    {
        Figure::print_info();
        std::cout << "Стороны:";
        char sideNames[] = { 'a', 'b', 'c','d'};
        for (int i = 0; i < lengths.size(); ++i)
        {
            std::cout << sideNames[i] << " = " << lengths[i];
            if (i != lengths.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;

        std::cout << "Углы:";
        char angleNames[] = { 'A', 'B', 'C' };
        for (int i = 0; i < angles.size(); ++i)
        {
            std::cout << angleNames[i] << " = " << angles[i];
            if (i != angles.size() - 1) std::cout << ", ";
        }
        std::cout << std::endl;
    }

    bool check() override
    {
        if (!Figure::check())
        {
            double sum = 0;
            for (const auto& angle : angles)
            {
                sum += angle;
            }
            return sum == 360.0;
        }
        return false;
    }
};

class Rectangle :public Quadrilateral
{
public:
    Rectangle(std::string name,double side1, double side2)
        :Quadrilateral(name, side1, side2, side1, side2, 90.0, 90.0, 90.0, 90.0) {}

    bool check() override 
    {
        return Quadrilateral::check() && lengths[0] == lengths[2] && lengths[1] == lengths[3] && angles[0] == 90.0;
    }
};

class Square :public Rectangle
{
public:
    Square(std::string name,double side)
        :Rectangle("Квадрат", side, side) {}
    bool check() override {
        return Rectangle::check() && lengths[0] == lengths[1];
    }
};
    
class Parallelogram :public Quadrilateral
{
public:
    Parallelogram(std::string name, double side1, double side2, double angle)
        : Quadrilateral(name, side1, side2, side1, side2, angle, 180.0 - angle, angle, 180.0 - angle) {}

    bool check() override {
        return Quadrilateral::check() && lengths[0] == lengths[2] && lengths[1] == lengths[3];
    }
};

class Rhombus :public Parallelogram
{
public:
    Rhombus(std::string name, double side, double angle)
        :Parallelogram("Ромб", side, side,angle){}

    bool check() override {
        return Parallelogram::check() && angles[0] == angles[2] && angles[1] == angles[3] && lengths[0] == lengths[1];
    }
};
int main()
{
    setlocale(LC_ALL, "Rus");

    std::vector<Figure*> figures;
    figures.push_back(new Figure("Фигура", 0));
    figures.push_back(new Triangle("Треугольник", 10.0, 20.0, 30.0, 50.0, 60.0, 70.0));
    figures.push_back(new RightTriangle("Прямоугольный треугольник",10.0, 20.0));
    figures.push_back(new Identical_triangle("Равнобедренный треугольник", 10.0, 50.0));
    figures.push_back(new Equal_triangle("Равносторонний треугольник", 30.0));
    figures.push_back(new Quadrilateral("Четырёхугольник", 10.0, 20.0, 30.0, 40.0 ,  50.0, 60.0, 70.0, 80.0 ));
    figures.push_back(new Rectangle("Прямоугольник",10.0, 20.0));
    figures.push_back(new Square("Квадрат", 20.0));
    figures.push_back(new Parallelogram("Параллелограмм", 20.0, 30.0, 30.0));
    figures.push_back(new Rhombus("Ромб", 30.0, 30.0));

    for (const auto& figure : figures) {
        figure->print_info();
        if (figure->check()) {
            std::cout << "Правильная" << std::endl;
        }
        else {
            std::cout << "Неправильная" << std::endl;
        }
        std::cout << std::endl;
    }

    
    for (const auto& figure : figures) {
        delete figure;
    }

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
