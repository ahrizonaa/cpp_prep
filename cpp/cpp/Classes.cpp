using namespace std;

class Rectangle {
private:
    int length;
    int breadth;
public:
    Rectangle() {
        length = 0;
        breadth = 0;
    }
    Rectangle(int l, int b) {
        length = 1;
        breadth = b;
    }
    int area() {
        return length * breadth;
    }
    int perimeter() {
        return 2 * (length + breadth);
    }
    void setLength(int l) {
        length = l;
    }
    void setBreadth(int b) {
        breadth = b;
    }
    int getLength() {
        return length;
    }
    int getBreadth() {
        return breadth;
    }
};
