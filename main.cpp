#include <iostream>
#include <vector>
#include "Square.h"
using namespace std;

#include "Point.h"

Point::Point(int px, int py)
{
    x = px;
    y = py;
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int px)
{
    x = px;
}

void Point::setY(int py)
{
    y = py;
}

Square::Square(const string n, int px, int py, unsigned int s)
    : Point(px, py), name(n), side(s) {
}

unsigned int Square::getSide() const
{
    return side;
}

unsigned int Square::getArea() const
{
    return side * side;
}

string Square::getName() const
{
    return name;
}

void Square::setSide(unsigned int s)
{
    side = s;
}

void Square::setArea(unsigned int a)
{
    side = sqrt(a);
}

void Square::setName(string n)
{
    name = n;
}


int main()
{
    int n;
    cin >> n;
    vector<Square> v;

    for (int i = 0; i < n; i++) {
        string s;
        int x, y, side;
        cin >> s >> x >> y >> side;
        Square sq(s, x, y, side);
        v.push_back(sq);
    }

    cout << "\nSquares in increasing order of area\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j].getArea() > v[j + 1].getArea())
            {
                swap(v[j], v[j+1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v[i].getName() << "(" << v[i].getX() << ", " << v[i].getY() << ")"
            << " side=" << v[i].getSide() << ", area=" << v[i].getArea() << "\n";
    }
    cout << "\nSquares in increasing order of max x-coordinate\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int X1 = v[j].getX() + v[j].getSide();
            int X2 = v[j+1].getX() + v[j+1].getSide();
            if (X1 > X2)
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int X = v[i].getX() + v[i].getSide();
        cout << v[i].getName() << "(" << X << ", " << v[i].getY() << ")"
            << " side=" << v[i].getSide() << ", area=" << v[i].getArea() << "\n";
    }

    cout << "\nSquares in increasing order of max y-coordinate\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            int Y1 = v[j].getY() + (int)v[j].getSide();
            int Y2 = v[j + 1].getY() + (int)v[j + 1].getSide();
            if (Y1 > Y2)
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int Y = v[i].getY() + v[i].getSide();
        cout << v[i].getName() << "(" << v[i].getX() << ", " << Y<< ")"
            << " side=" << v[i].getSide() << ", area=" << v[i].getArea() << "\n";
    }
}