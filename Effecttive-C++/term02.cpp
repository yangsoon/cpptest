// 尽量使用const enum inline代替#define

// 1. 使用const代替可以保留符号信息 报错时候可以定位到具体的符号 否则只能看到1.635
#define ASPECT_RATION 1.653
const double AspectRatio = 1.653;

// 2.class专属常量
// 类中的静态成员
class GamePlayer {
public:  
    static int getN() {
        return NumTurns;
    }
private:
    // 常量声明式 如果没有声明初值 一定要有21行的定义式 一定要指定初值
    // const int GamePlayer::NumTurns = 0; // 位于实现文件中
    // static const int NumTurns; 
    // 常量声明式 只声明但是没有定义 没有分配内存 实际上在c++11中不用再定义
    static const int NumTurns = 5; 
    // int scores[NumTurns];
};
const int GamePlayer::NumTurns; // NumTurns定义 分配内存

class CostEstimate {
private: 
 static const double FudgeFactor; // 常量声明位于头文件中
};
const double CostEstimate::FudgeFactor=0; // static class 常量定义 位于实现文件中

#include <iostream>
using std::cout;
using std::endl;
int main() {
    // 有访问权限 需要一个静态函数访问
    cout << GamePlayer::getN() << endl;
}