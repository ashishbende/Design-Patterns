// subtypes should be immediately substitutable for their base types

#include<iostream>

class Rectangle{
    protected:
        int width;
        int height;
    public:
    Rectangle(int width, int height)
        : width(width), height(height) {}
    
    int getWidth() const { return width;} 
    int getHeight() const { return height;}
    virtual void setWidth(int width){
        this->width = width;
    } 

    virtual void setHeight(int height){
        this->height = height;
    }

    int getArea() const {
        return width*height;
    }
};

void Process(Rectangle& r){
    int width = r.getWidth();
    r.setHeight(10);
    std::cout   << "Expected area is " << (width*10)
                << ", and we got " << r.getArea() << std::endl;
}
class Square : public Rectangle{
    public:
        Square(int side)
            : Rectangle(side, side) {}
        
        void setHeight(int side) override{
            this->width = this->height = side;
        }

        void setWidth(int side) override{
            this->width = this->height = side;            
        }
};


int main(){
    Rectangle r{3,4};
    Process(r);   

    // we are violating liskov's principle
    // couple of ways to solve this ->
    // have a boolean inside rectangle class indicating whether it is a square.
    // use factory
    Square s{2};
    Process(s);
    return 0;
}