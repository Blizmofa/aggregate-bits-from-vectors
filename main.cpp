#include <iostream>
#include <bitset>
#include <array>
#include <vector>
#include <set>
#include <algorithm>

const size_t ARRAY_SIZE = 10; // Adjust the size of the array as needed

// Define a BitsetStruct for each element in the array
struct BitsetStruct
{
    std::bitset<6> bits;
    BitsetStruct()
    {
        // Initialize all bits to 0
        bits.reset();
    }
};

// Function to print the bitset for a given index
void printBitset(const std::bitset<6> &bits)
{
    for (int i = 5; i >= 0; --i)
    {
        std::cout << bits[i];
    }
}

// Function to aggregate bits based on layers and collect indexes where all bits are set to 1
std::vector<size_t> aggregateLayers(std::array<BitsetStruct, ARRAY_SIZE> &bitsetArray,
                                    const std::vector<std::vector<size_t>> &layers)
{
    // Define bit positions corresponding to each layer
    std::vector<size_t> bitPositions = {0, 1, 2, 3, 4, 5};

    // Print bitsets before aggregation
    std::cout << "Bitsets Before Aggregation:" << std::endl;
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << "Index " << i << ": ";
        printBitset(bitsetArray[i].bits);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Process each layer
    for (size_t layerIdx = 0; layerIdx < layers.size(); ++layerIdx)
    {
        for (size_t index : layers[layerIdx])
        {
            if (index < ARRAY_SIZE)
            {
                bitsetArray[index].bits.flip(bitPositions[layerIdx]);
            }
        }
    }

    std::vector<size_t> matchedIndexes;

    // Collect indexes where all bits are set to 1 based on the layers provided
    // Time Complexity: O(layers.size() * m_i) where m_i is the size of each layer
    // Space Complexity: O(1) (stack)
    for (size_t layerIdx = 0; layerIdx < layers.size(); ++layerIdx)
    {
        for (size_t index : layers[layerIdx])
        {
            if (index < ARRAY_SIZE && bitsetArray[index].bits.all())
            {
                // Check if index is not already in matchedIndexes
                if (std::find(matchedIndexes.begin(), matchedIndexes.end(), index) == matchedIndexes.end())
                {
                    matchedIndexes.push_back(index);
                }
            }
        }
    }

    // Print bitsets after aggregation
    std::cout << "Bitsets After Aggregation:" << std::endl;
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        std::cout << "Index " << i << ": ";
        printBitset(bitsetArray[i].bits);
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return matchedIndexes;
}

int main()
{
    // Step 1: Create an array of BitsetStruct
    std::array<BitsetStruct, ARRAY_SIZE> bitsetArray;

    std::vector<size_t> layer1 = {1, 2, 3};
    std::vector<size_t> layer2 = {1, 2, 3, 4, 5};
    std::vector<size_t> layer3 = {1, 2, 3, 6, 7};
    std::vector<size_t> layer4 = {1, 2, 3, 9};
    std::vector<size_t> layer5 = {1, 2, 3, 4, 5};
    std::vector<size_t> layer6 = {1, 2, 3, 5, 6};

    // Step 2: Create vectors to store indexes of the array with values up to 9
    std::vector<std::vector<size_t>> layers = {
        layer1,
        layer2,
        layer3,
        layer4,
        layer5,
        layer6};

    // Step 3: Aggregate bits based on layers and collect matched indexes
    std::vector<size_t> matchedIndexes = aggregateLayers(bitsetArray, layers);

    // Step 4: Output the matched indexes
    if (!matchedIndexes.empty())
    {
        std::cout << "Indexes where all bits are set to 1: ";
        for (size_t index : matchedIndexes)
        {
            std::cout << index << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No indexes found where all bits are set to 1." << std::endl;
    }

    return 0;
}