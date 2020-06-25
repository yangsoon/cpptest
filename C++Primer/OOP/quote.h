#include <string>
#include <iostream>

class Quote {
public:
    // =default 表示我们需要一个自定义的构造函数 也需要一个默认的构造函数
    Quote() = default;
    Quote(const std::string &book, double sales_price):
        bookNo(book), price(sales_price) {}
    
    std::string isbin() const;
    // virtual double net_price(std::size_t n) const = 0;
    virtual double net_price(std::size_t n) const {return n * price;}
    virtual ~Quote() = default;
private:
    std::string bookNo;
// 允许派生类 访问
protected:
    double price = 1.0;
};

// 派生类的声明 只包含类名 不包含派生列表
class Bulk_quote;

// error 不能派生
// class Bulk_quote: public Quote;

// 不想某一个类作为基类 在声明后面加上 final
class Base final {};