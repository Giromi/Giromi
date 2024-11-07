
class A {
public:
    int      _b;

private:
    int		_a;

};

class B : public A {
public:
    int        _b;

private:
    int		_a;
};



int main(void) {
    B b;

    b._b = 1;

}
