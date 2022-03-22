#include"Container.h"


Container::Container(vector<Box> array, int length, int width, int height, int maxWeight) {
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i].getWeight();
    }
    if (sum > maxWeight) {
        throw exception("Error");

    }
    this->array = array;
    this->length = length;
    this->width = width;
    this->height = height;
    this->maxWeight = maxWeight;
}


void Container::appendBoxInContainer(int i, Box box) {
    double sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i].getWeight();
    }
    auto iter1 = array.cbegin();
    if ((sum + box.getWeight()) > maxWeight) {
        throw MyExpetion("Too much weight");
    }
    array.insert(iter1 + i, box);
}

void Container::deleteBoxInContainer(int i) {
    auto iter = array.cbegin();
    array.erase(iter + i - 1);
}

int Container::countBoxesInContainer() {
    return array.size();
}

double Container::sumWeightInContainer() {
    double sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i].getWeight();
    }
    return sum;
}

int Container::sumValueInContainer() {
    int sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += array[i].getValue();
    }
    return sum;
}

Box Container::returnBoxByIndex(int i) {
    return array[i];
}

Box& Container::operator[](const int index) {
    return array[index];
}

ostream& operator <<(ostream& out, Container& container) {
    out << "Container(" << container.length << ", " << container.width << ", " << container.height << ", " << container.maxWeight << ", ";
    for (int i = 0; i < container.array.size(); i++) {
        out << container.array[i] << ", ";
    }
    out << ")";
    return out;
}

istream& operator >> (istream& in, Container& container) {
    in >> container.height;
    in >> container.width;
    in >> container.length;
    in >> container.maxWeight;
    for (int i = 0; i < container.array.size(); i++) {
        in >> container.array[i];
    }
    return in;
}
