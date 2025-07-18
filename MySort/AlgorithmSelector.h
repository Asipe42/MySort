#pragma once
#include <string>

class AlgorithmSelector
{
public:
    enum class EAlgorithmType
    {
        None,
        Selection,
        Bubble,
        Insertion,
        Quick
    };

    EAlgorithmType Select();

private:
    void PrintMenu() const;
};
