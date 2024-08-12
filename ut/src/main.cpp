#include <fstream>
#include <gtest/gtest.h>

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    auto successFilePath = std::string();
    auto statsFilePath = std::string();
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            if (argv[i] != nullptr &&
                strcmp(argv[i], "--successFilePath") == 0 && (i + 1) < argc &&
                argv[i + 1] != nullptr)
            {
                successFilePath = argv[i + 1];
            }
            else if (argv[i] != nullptr &&
                     strcmp(argv[i], "--statsFilePath") == 0 &&
                     (i + 1) < argc && argv[i + 1] != nullptr)
            {
                statsFilePath = argv[i + 1];
            }
        }
    }

    auto retCode = RUN_ALL_TESTS();
    if (!successFilePath.empty() && retCode == 0)
    {
        std::ofstream success(successFilePath);
    }
    if (!statsFilePath.empty())
    {
        const auto *ut = testing::UnitTest::GetInstance();
        std::ofstream statFile(statsFilePath);
        statFile << "{" << std::endl;
        statFile << "TEST_COUNT : " << ut->test_to_run_count() << ","
                 << std::endl;
        statFile << "PASSED_COUNT : " << ut->successful_test_count()
                 << "," << std::endl;
        statFile << "FAILED_COUNT : " << ut->failed_test_count() << ","
                 << std::endl;
        statFile << "SKIPPED_COUNT : " << ut->skipped_test_count()
                 << std::endl;
        statFile << "}" << std::endl;
    }
    return retCode;
}
