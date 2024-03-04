#include <iostream>

int main()
{
    int entryDays{};
    std::cout << "Enter a number of days :";
    std::cin >> entryDays;

    int centuries{entryDays/(100*360)};
    int years{(entryDays%(360*100))/360};
    int months{(entryDays%360)/30};
    int weeks{(entryDays%30)/7};
    int days{(entryDays%30)%7};

    std::cout << entryDays << " days are " << centuries << " century(ies), " << years << " year(s), " << months << " months, " << weeks << " week(s) and " << days << " day(s)" <<std::endl;
}