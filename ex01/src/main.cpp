#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat a("Alice", 50);
        Bureaucrat b("Bob", 120);
        Form contract("Contract A", 100, 50);
        std::cout << "Before signing: " << contract << std::endl;

		
        // Bob はランクが低すぎてサインできない
        b.signForm(contract);
        std::cout << "After Bob tries: " << contract << std::endl;

        // Alice は十分なランクなのでサイン成功
        a.signForm(contract);
        std::cout << "After Alice signs: " << contract << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    // 無効なForm（例外テスト）
    try
    {
        Form invalid("Invalid Form", 0, 160); // 範囲外
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception on invalid form: " << e.what() << std::endl;
    }

    return 0;
}