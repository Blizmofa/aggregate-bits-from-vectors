#include <iostream>
#include <bitset>
#include <array>
#include <vector>

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

// Function to aggregate bits based on layers and collect indexes where all bits are set to 1
std::vector<size_t> aggregateLayers(std::array<BitsetStruct, ARRAY_SIZE> &bitsetArray,
                                    const std::vector<size_t> &layer1,
                                    const std::vector<size_t> &layer2,
                                    const std::vector<size_t> &layer3,
                                    const std::vector<size_t> &layer4,
                                    const std::vector<size_t> &layer5,
                                    const std::vector<size_t> &layer6)
{
    std::vector<size_t> matchedIndexes;

    // Process layer1
    for (size_t index : layer1)
    {
        if (index < ARRAY_SIZE)
        {
            bitsetArray[index].bits.set(0); // Set the first bit for index in layer 1
        }
    }

    // Process layer2
    for (size_t index : layer2)
    {
        if (index < ARRAY_SIZE)
        {
            bitsetArray[index].bits.set(1); // Set the second bit for index in layer 2
        }
    }

    // Process layer3
    for (size_t index : layer3)
    {
        if (index < ARRAY_SIZE)
        {
            bitsetArray[index].bits.set(2); // Set the third bit for index in layer 3
        }
    }

    // Process layer4
    for (size_t index : layer4)
    {
        if (index < ARRAY_SIZE)
        {
            bitsetArray[index].bits.set(3); // Set the fourth bit for index in layer 4
        }
    }

    // Process layer5
    for (size_t index : layer5)
    {
        if (index < ARRAY_SIZE)
        {
            bitsetArray[index].bits.set(4); // Set the fifth bit for index in layer 5
        }
    }

    // Process layer6
    for (size_t index : layer6)
    {
        if (index < ARRAY_SIZE)
        {
            bitsetArray[index].bits.set(5); // Set the sixth bit for index in layer 6
        }
    }

    // Check if all bits are set to 1 for each index and collect matching indexes
    for (size_t i = 0; i < ARRAY_SIZE; ++i)
    {
        if (bitsetArray[i].bits.all())
        {
            matchedIndexes.push_back(i); // Add index to matchedIndexes if all bits are set to 1
        }
    }

    return matchedIndexes;
}

int main()
{
    // Step 1: Create an array of BitsetStruct
    std::array<BitsetStruct, ARRAY_SIZE> bitsetArray;

    // Step 2: Create vectors to store indexes of the array with values up to 9
    std::vector<size_t> layer1 = {1, 2, 3};
    std::vector<size_t> layer2 = {1, 2, 3, 4, 5};
    std::vector<size_t> layer3 = {1, 2, 3, 6, 7};
    std::vector<size_t> layer4 = {1, 2, 3, 9};
    std::vector<size_t> layer5 = {1, 2, 3, 4, 5};
    std::vector<size_t> layer6 = {1, 2, 3, 5, 6};

    // Step 3: Aggregate bits based on layers and collect matched indexes
    std::vector<size_t> matchedIndexes = aggregateLayers(bitsetArray, layer1, layer2, layer3, layer4, layer5, layer6);

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
