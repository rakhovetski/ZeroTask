#pragma once
using namespace std;
#include <iostream>
#include "stdio.h"


    class Box {
    public:
        int length;
        int width;
        int height;
        double weight;
        int value;

        Box(int lenght, int width, int height, double weight, int value);
        int getLength();
        int getWidth();
        int getHeight();
        double getWeight();
        int getValue();
        void setLenght(int lenght);
        void setWidth(int width);
        void setHeight(int height);
        void setWeight(double weight);
        void setValue(int value);

        int sumValue(Box boxes[], int size);
        friend istream& operator >>(istream&, Box&);

        bool notBig(Box boxes[], int size, int res);

        double maxWeight(Box boxes[], int size, int maxV);

        bool boxInBox(Box boxes[], int size);
    };



    ostream& operator <<(ostream& out, Box& box);
    istream& operator >> (istream& in, Box& box);
    bool operator == (Box& boxes1, Box& boxes2);




