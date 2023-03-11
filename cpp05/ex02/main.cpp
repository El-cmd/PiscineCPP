#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form f("Form", 30, 1);
        Bureaucrat b("Bob", 40);
        b.signForm(f);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what();
    }
    
    return 0;
}