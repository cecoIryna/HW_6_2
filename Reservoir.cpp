#include <Windows.h>
#pragma warning(disable : 4996)
#include <cstring>
using namespace std;

#include "Reservoir.h"

Reservoir::Reservoir() : name(nullptr), width(0), length(0), maxDepth(0), type(nullptr) {}

Reservoir::Reservoir(const char* n, const char* t, double w, double l, double d)
    : width(w), length(l), maxDepth(d) {
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    type = new char[strlen(t) + 1];
    strcpy(type, t);
}

Reservoir::Reservoir(const Reservoir& other) : width(other.width), length(other.length), maxDepth(other.maxDepth) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    type = new char[strlen(other.type) + 1];
    strcpy(type, other.type);
}

Reservoir::~Reservoir() {
    delete[] name;
    delete[] type;
}

// Определение объема
double Reservoir::CalculateVolume() const {
    return width * length * maxDepth;
}

// Определение площади водной поверхности
double Reservoir::CalculateSurfaceArea() const {
    return width * length;
}

// Проверка на одинаковый тип водоемов
bool Reservoir::IsSameType(const Reservoir& other) const {
    return strcmp(type, other.type) == 0;
}

// Сравнение площади водной поверхности
bool Reservoir::CompareSurfaceArea(const Reservoir& other) const {
    if (IsSameType(other)) {
        return CalculateSurfaceArea() > other.CalculateSurfaceArea();
    }
    return false;
}

const char* Reservoir::GetName() const {
    return name;
}

const char* Reservoir::GetType() const {
    return type;
}

void Reservoir::SetName(const char* newName) {
    delete[] name;
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

void Reservoir::SetType(const char* newType) {
    delete[] type;
    type = new char[strlen(newType) + 1];
    strcpy(type, newType);
}

double Reservoir::GetWidth() const {
    return width;
}

double Reservoir::GetLength() const {
    return length;
}

double Reservoir::GetMaxDepth() const {
    return maxDepth;
}

void Reservoir::SetDimensions(double w, double l, double d) {
    width = w;
    length = l;
    maxDepth = d;
}

Reservoir& Reservoir::operator=(const Reservoir& other) {
    if (this != &other) {
        delete[] name;
        delete[] type;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);

        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}

void Reservoir::Display() const {
    cout << "Name: " << name << "\nType: " << type
        << "\nDimensions (W x L x D): " << width << " x " << length << " x " << maxDepth
        << "\nVolume: " << CalculateVolume()
        << "\nSurface Area: " << CalculateSurfaceArea() << endl;
}