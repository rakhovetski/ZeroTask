#include"Box.h"


Box::Box(int lenght, int width, int height, double weight, int value) {
    this->length = lenght;
    this->width = width;
    this->height = height;
    this->weight = weight;
    this->value = value;
}

int Box::getLength() {
    return length;
}
int Box::getWidth() {
    return width;
}
int Box::getHeight() {
    return height;
}
double Box::getWeight() {
    return weight;
}
int Box::getValue() {
    return value;
}
void Box::setLenght(int lenght) {
    this->length = lenght;
}
void Box::setWidth(int width) {
    this->width = width;
}
void Box::setHeight(int height) {
    this->height = height;
}
void Box::setWeight(double weight) {
    this->weight = weight;
}
void Box::setValue(int value) {
    this->value = value;
}

int Box::sumValue(Box boxes[],int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += boxes[i].value;
    }
    return sum;
}


bool Box::notBig(Box boxes[],int size, int res) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += boxes[i].length;
        sum += boxes[i].width;
        sum += boxes[i].height;
    }
    if (res >= sum) return true;
    else return false;
}

double Box::maxWeight(Box boxes[],int size, int maxV) {
    double maxWeight = 0;
    for (int j = 0; j < size; j++)
    {
        if ((boxes[j].getHeight() * boxes[j].getLength() * boxes[j].getWidth() <= maxV) && (maxWeight <= boxes[j].getWeight()))
        {
            maxWeight = boxes[j].weight;
        }
    }
    return maxWeight;
}




bool Box::boxInBox(Box boxes[], int size) {
    int l = 0;
    int b = 0;
    float k = (float(1 + (size - 1)) / 2) * float(size - 1);
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((boxes[i].getHeight() * boxes[i].getLength() * boxes[i].getWidth() < boxes[j].getWidth() * boxes[j].getLength() * boxes[j].getHeight()))
            {
                b++;
            }
        }
    }
    if (int(k) == b)
    {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if ((boxes[i].getHeight() < boxes[j].getHeight() && boxes[i].getWidth() < boxes[j].getWidth() && boxes[i].getLength() < boxes[j].getLength()))
                {
                    l++;
                }
            }
        }
        if (int(k) != l) {
            return false;
        }
        return true;
    }
}

ostream& operator <<(ostream& out, Box& box) {
    out << "Box(" << box.getHeight() << ", " << box.getWidth() << ", " << box.getLength() << ", " << box.getWeight() << ", " << box.getValue() << ")";
    return out;
}

istream& operator >> (istream& in, Box& box) {
    in >> box.height;
    in >> box.width;
    in >> box.length;
    in >> box.weight;
    in >> box.value;
    return in;
}

bool operator == (Box& boxes1, Box& boxes2) {
    return ((boxes1.getHeight() == boxes2.getHeight()) && (boxes1.getLength() == boxes2.getLength()) && (boxes1.getWeight() == boxes2.getWeight()) && (boxes1.getWidth() == boxes2.getWidth()) && (boxes1.getValue() == boxes2.getValue()));
}

