#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <chrono>

namespace gen {
    long factorial(int n) {
        if (n < 0) {
            return 0;
        }

        long result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }

    long nCk(int n, int k) {
        if (n < 0 || k < 0 || k > n) {
            return 0;
        }

        return gen::factorial(n) / (gen::factorial(k) * gen::factorial(n - k));
    }

    std::vector<long> pascalTriangleRow(int n) {
        int length = n + 1;
        auto row = std::vector<long>(length);

        for (int i = 0; i <= length; i++) {
            long nck = gen::nCk(n, i);
            row[i] = nck;
        }
        return row;
    }

    std::vector<long> lozanicTriangle(int n) {
        std::vector<long> firstRow = gen::pascalTriangleRow(0);

        if (n == 0) return firstRow;

        std::vector<long> prevRow = firstRow;
        for (int i = 1; i <= n; i++) {
            auto currentRow = std::vector<long>(prevRow.size() + 1);
            auto vectorSize = currentRow.size() - 1;
            for (int j = 0; j <= vectorSize; j++) {
                if (j == 0 or j == vectorSize) {
                    currentRow[j] = 1;
                    continue;
                }

                double prevLimit = j - .5;
                currentRow[j] = prevRow[std::floor(prevLimit)] + prevRow[std::ceil(prevLimit)];

                if (i % 2 == 0 and j % 2 == 1)
                    currentRow[j] -= gen::nCk(i / 2 - 1, (j - 1) / 2);
            }
            prevRow = currentRow;
        }

        return prevRow;
    }
}

namespace alg {
    void measure(const std::string &algorithmName, bool (*algorithm)(const std::vector<long>&, long, int, int, int*),
                 const std::vector<long> &vector, long key, int first, int second) {
        auto begin = std::chrono::steady_clock::now();

        int counter = 0;
        bool result = algorithm(vector, key, first, second, &counter);

        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);

        std::cout << algorithmName << " ended in " <<  duration.count() << " ms"
        << " and " << counter << " iterations" << std::endl;
        std::cout << "Result: " << std::to_string(result) << std::endl << std::endl;
    }

    bool ternarySearch(const std::vector<long> &vector, long key, int left = 0, int right = -1, int *ctr = nullptr) {
        if (right == -1)
            right = vector.size() - 1;

        while (true) {
            (*ctr)++;
            if (left <= right) {
                int mid1 = left + (right - left) / 3;
                int mid2 = right - (right - left) / 3;

                if (vector[mid1] == key) {
                    std::cout << vector[mid1] << std::endl;
                    return true;
                }
                else if (vector[mid2] == key) {
                    std::cout << vector[mid2] << std::endl;
                    return true;
                }
                else if (key > vector[mid2]) {
                    std::cout << vector[mid2] << std::endl;
                    left = mid2 + 1;
                }
                else if (key < vector[mid1]) {
                    std::cout << vector[mid1] << std::endl;
                    right = mid1 - 1;
                }
                else {
                    std::cout << vector[mid1] << std::endl;
                    std::cout << vector[mid2] << std::endl;
                    left = mid1 + 1;
                    right = mid2 - 1;
                }
            }
            else
                return false;
        }
    }

    bool interpolationSearch(const std::vector<long> &vector, long key, int low = 0, int high = -1, int *ctr = nullptr) {
        if (high == -1)
            high = vector.size() - 1;

        while (low <= high) {
            (*ctr)++;
            int mid = low + (high - low) * (key - vector[low]) / (vector[high] - vector[low]);

            std::cout << vector[mid] << std::endl;

            if (key == vector[mid]) {
                return true;
            }
            else if (key < vector[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return false;
    }
}

int main() {
    std::string userInput;
    bool shouldContinueExecuting = true;
    std::vector<long> searchVector;

    while (shouldContinueExecuting) {
        std::cout << "Choose option:" << std::endl;
        std::cout << "[1] Generate row of Lozincki(?) Triangle" << std::endl;
        std::cout << "[2] Start Search (Ternary + interpolation)" << std::endl;
        std::cout << "[3] Exit" << std::endl;

        int choice;
        bool isInputCorrect = true;
        while (isInputCorrect) {
            std::cin >> userInput;
            try {
                choice = std::stoi(userInput);
                isInputCorrect = false;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Please enter numbers only. Wrong input!" << std::endl;
                continue;
            }
        }
        std::cout << std::endl;

        switch (choice) {
            case 1: {
                std::cout << "Enter n lozincki triangle (n = 0, 1, 2...)"  << std::endl;
                std::cin >> userInput;
                int row = std::stoi(userInput);
                searchVector = gen::lozanicTriangle(row);

                std::cout << std::endl;
                std::cout << "Row lozincki triangle with " << row << " is:" << std::endl;
                for (const long &element : searchVector) {
                    std::cout << std::to_string(element) << " ";
                }
                std::cout << std::endl;

                break;
            }
            case 2: {
                if (searchVector.empty()) {
                    std::cout << "Choose option one first, in order to generate rows"  << std::endl;
                    std::cout << std::endl;

                    continue;
                }

                std::cout << "Enter search key: "  << std::endl;
                std::cin >> userInput;
                std::cout << std::endl;

                long key = std::stol(userInput);
                int midPoint = std::ceil(searchVector.size() / 2);

                alg::measure("Ternary: ",
                             alg::ternarySearch, searchVector, key, 0, midPoint);

                alg::measure("Interpolation: ",
                             alg::interpolationSearch, searchVector, key, 0, midPoint);

                break;
            }
            case 3: {
                std::cout << "Exiting..." << std::endl;
                shouldContinueExecuting = false;
                break;
            }
            default:
                std::cout << "Uknown option!" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
