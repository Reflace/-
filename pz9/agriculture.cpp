#include "agriculture.hpp"

AgrProduct::AgrProduct()
{
    product_code = 0;
    product_name = "";
    region_name = "";
    region_area = 0;
    productivity = 0;
    price = 0;
    transport_loss = 0;
    worth = 0;
}

AgrProduct::AgrProduct(size_t product_code, string product_name, string region_name,
                       float region_area, float productivity, float price,
                       float transport_loss, float worth)
{
    this->product_code = product_code;
    this->product_name = product_name;
    this->region_name = region_name;
    this->region_area = region_area;
    this->productivity = productivity;
    this->price = price;
    this->transport_loss = transport_loss;
    this->worth = worth;
}

AgrProduct::~AgrProduct()
{
    product_code = 0;
    product_name.clear();
    region_name.clear();
    region_area = 0;
    productivity = 0;
    price = 0;
    transport_loss = 0;
    worth = 0;
}

ostream &operator<<(ostream &stream, const AgrProduct &obj)
{
    stream << left << setw(30) << "Код продукта:" << obj.product_code << endl;
    stream << left << setw(30) << "Наименование:" << obj.product_name << endl;
    stream << left << setw(30) << "Название региона:" << obj.region_name << endl;
    stream << left << setw(30) << "Площадь региона:" << obj.region_area << " га" << endl;
    stream << left << setw(30) << "Урожайность:" << obj.productivity << " кг/га" << endl;
    stream << left << setw(30) << "Цена за 1кг:" << obj.price << " уе" << endl;
    stream << left << setw(30) << "Потери при транспортировке:" << obj.transport_loss << " %" << endl;
    stream << left << setw(30) << "Цена:" << obj.worth << " уе" << endl;
    return stream;
}

istream &operator>>(istream &stream, AgrProduct &obj)
{
    stream >> obj.product_code >> obj.product_name >> obj.region_name >> obj.region_area >>
        obj.productivity >> obj.price >> obj.transport_loss >> obj.worth;
    return stream;
}
