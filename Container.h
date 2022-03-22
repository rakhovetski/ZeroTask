#pragma once
#include<vector>
#include"Box.h"



    class Container {
    public:
        vector<Box> array;
        int length;
        int width;
        int height;
        int maxWeight;

        Container(vector<Box> array, int length, int width, int height, int maxWeight);


        void appendBoxInContainer(int i, Box box);
        void deleteBoxInContainer(int i);

        int countBoxesInContainer();

        double sumWeightInContainer();

        int sumValueInContainer();
        Box returnBoxByIndex(int i);

        Box& operator[](const int index);

    };

    istream& operator >> (istream& in, Container& container);
    ostream& operator <<(ostream& out, Container& container);


    class MyExpetion : public exception {
    private:
        string m_error;
    public:
        MyExpetion(string error) : m_error(error) {

        }
        const char* what() const noexcept { return m_error.c_str(); }
    };

