#pragma once
#include <iostream>
#include <cstring> 
using namespace std;

class Reservoir {
    char* name; 
    double width, length, maxDepth; 
    char* type;

public:
    Reservoir();
    explicit Reservoir(const char* name, const char* type, double width, double length, double maxDepth);
    Reservoir(const Reservoir& other);
    ~Reservoir();

    double CalculateVolume() const; // ����������� ������
    double CalculateSurfaceArea() const; // ����������� ������� ������ �����������
    bool IsSameType(const Reservoir& other) const; // �������� �� ���������� ��� ��������
    bool CompareSurfaceArea(const Reservoir& other) const; // ��������� ������� ������ �����������

    const char* GetName() const;
    const char* GetType() const;
    void SetName(const char* newName);
    void SetType(const char* newType);
    double GetWidth() const;
    double GetLength() const;
    double GetMaxDepth() const;
    void SetDimensions(double width, double length, double maxDepth);

    Reservoir& operator=(const Reservoir& other);

    void Display() const;
};