#include "_main.cc"

int main()
{
    AddValue(1);
    AddValue(1);
    AddValue(1);
    AddValue(2);
    AddValue(2);
    AddValue(3);
    PrintLFU();

    EvictFromCache();
    PrintLFU();

    AddValue(2);
    PrintLFU();

    EvictFromCache();
    PrintLFU();

}