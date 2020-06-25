#include "quote.h"

std::string Quote::isbin() const {
    return bookNo;
}

class Bulk_quote: public Quote {
public:
    Bulk_quote() = default;
    // 遵循基类接口 通过调用基类的构造函数来初始化那些从基类中继承的对象
    Bulk_quote(const std::string& book, double p, 
                std::size_t qty, double disc) : 
                Quote(book, p),  min_qty(qty), discount(disc) {}
    double net_price(std::size_t cnt) const override {
        if(cnt >= min_qty) {
            return cnt * (1-discount) * price;
        } else {
            return cnt + price;
        }
    };
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};

double print_total(std::ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbin()
        << " # sold: " << n << "total due: " << ret << std::endl;
    return ret;
}