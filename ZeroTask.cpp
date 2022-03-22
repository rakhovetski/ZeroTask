using namespace std;
#include"Container.h"



int main()
{
    //Тест коробок
    Box box1 = Box(1, 2, 3, 4.0, 5);
    Box box2(2, 3, 4, 5.0, 6);
    Box box3(3, 4, 5, 6.0, 7);
    Box box4(4, 5, 6, 7.0, 8);
    Box boxes[] = { box1,box2,box3,box4 };
    cout << box1 << endl;
    cout << box1.sumValue(boxes, 4) << endl;
    cout << box1.notBig(boxes, 4, 20) << endl;
    cout << box1.maxWeight(boxes, 4, 30) << endl;
    cout << box1.boxInBox(boxes, 4) << endl;

    //Тест контейнера
    vector<Box> arrBox = { box1,box2,box3,box4 };
    Container cont(arrBox, 3, 4, 5, 100);
    Box box5(1, 2, 3, 4.0, 5);
    cont.appendBoxInContainer(1,box5);
    cont.deleteBoxInContainer(2);
    cout << cont.countBoxesInContainer() << "\t";
    cout << cont.sumValueInContainer() << "\t";
    cout << endl;
    cout << cont << endl;
    cout << cont[1] << endl;

}
