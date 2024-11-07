#include <iostream>
using namespace std;

class Sale
{
public:
    // Constructors
    Sale(): price(0) {};
    Sale(double the_price): price(the_price) {};

    // Functions
    virtual double bill() const
    {
        return price;
    };

    double savings(const Sale& other) const //Returns the savings if you buy other instead of the calling object.
    {
        return ( bill() - other.bill() );
    };
    

protected:
    double price;
};

bool operator < (const Sale& first, const Sale& second) //Compares two sales to see which is larger.
{
    return (first.bill() < second.bill());
};



class DiscountSale : public Sale
{
public:
    DiscountSale(): Sale(), discount(0) {};
    DiscountSale(double the_price, double the_discount): Sale(the_price), discount(the_discount) {};
    //Discount is expressed as a percent of the price.
    virtual double bill() const
    {
        double fraction = discount/100;
        return (1 - fraction)*price;
    };
protected:
    double discount;
};


int main()
{
    Sale simple(10.00); //One item at $10.00.
    DiscountSale discount(11.00, 10); //One item at $11.00 with a 10% discount.

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (discount < simple)
    {
        cout << "Discounted item is cheaper.\n";
        cout << "Savings is $" << simple.savings(discount) << endl;
    }
    else

        cout << "Discounted item is not cheaper.\n";

    return 0;
}

