#include <iostream>
#include <vector>

std::vector<int> Sort(std::vector<int>& massive);
std::vector<int> Merge(std::vector<int>& frstMassive, std::vector<int>& scndMassive);

int main()
{
    std::vector<int> startMassive;
    std::vector<int> resultMassive;

    startMassive.push_back(5);
    startMassive.push_back(2);
    startMassive.push_back(4);
    startMassive.push_back(6);
    startMassive.push_back(1);
    startMassive.push_back(3);
    startMassive.push_back(2);

    resultMassive = Sort(startMassive);

    for (auto iter = resultMassive.begin(); iter != resultMassive.end(); iter++)
        std::cout << *iter << ' ';

    return 0;
}

/*
    Здравствуйте! Это реализация на C++.
    В задании сказано, что нужно реализовать лишь функцию Merge(),
    но я решил, что ещё скину и Sort()
*/


std::vector<int> Sort(std::vector<int>& massive)
{
    int count = massive.size();

    if (count == 1)
        return massive;
    else
    {
        int centre = floor(count / 2);
        std::vector<int> frstPiece;
        std::vector<int> scndPiece;

        for (int i = 0; i < count; i++)
        {
            if (i <= centre - 1)
                frstPiece.push_back(massive[i]);
            else
                scndPiece.push_back(massive[i]);
        }

        std::vector<int> mergePiece;

        frstPiece = Sort(frstPiece);
        scndPiece = Sort(scndPiece);
        mergePiece = Merge(frstPiece, scndPiece);

        return mergePiece;
    }
}

std::vector<int> Merge(std::vector<int>& frstMassive, std::vector<int>& scndMassive)
{
    std::vector<int> result;
    int count = scndMassive.size() + frstMassive.size();
    int flagA = 0;
    int flagB = 0;

    for (int i = 0; i < count; i++)
    {
        if (frstMassive.size() == flagA)
        {
            result.push_back(scndMassive[flagB]);
            flagB++;
        }
        else if (scndMassive.size() == flagB)
        {
            result.push_back(frstMassive[flagA]);
            flagA++;
        }
        else if (frstMassive[flagA] < scndMassive[flagB])
        {
            result.push_back(frstMassive[flagA]);
            flagA++;
        }
        else
        {
            result.push_back(scndMassive[flagB]);
            flagB++;
        }

    }

    return result;
}

