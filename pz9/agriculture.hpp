#ifndef AGRICULTURE_HPP
#define AGRICULTURE_HPP

#include <iostream>
#include <iomanip>

using namespace std;

class AgrProduct
{
private:
    size_t product_code;
    string product_name;
    string region_name;
    float region_area;
    float productivity;
    float price; // for 1kg
    float transport_loss;
    float worth; // for entire product

public:
    AgrProduct();
    AgrProduct(size_t product_code, string product_name, string region_name,
               float region_area, float productivity, float price,
               float transport_loss, float worth);
    ~AgrProduct();

    size_t get_key() const { return this->product_code; }

    bool operator==(const AgrProduct &ap) const { return (this->product_code == ap.product_code); }
    friend ostream &operator<<(ostream &stream, const AgrProduct &obj);
    friend istream &operator>>(istream &stream, AgrProduct &obj);
};

#endif // AGRICULTURE_HPP