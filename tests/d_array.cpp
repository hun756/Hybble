#include <gtest/gtest.h>
#include "d_array.hpp"
#include <vector>
#include <stdexcept>

TEST(DynamicArrayTest, LifeTimeManagement)
{
}

TEST(DynamicArrayTest, InitializeWithList)
{
}

TEST(DynamicArrayTest, Elements)
{
    DSinCpp::DArray<int> dArr{1, 2, 3};

    ASSERT_EQ(dArr.size(), 3);
    ASSERT_EQ(dArr[0], 1);
    ASSERT_EQ(dArr[1], 2);
    ASSERT_EQ(dArr[2], 3);

    dArr.pushBack(4);

    ASSERT_EQ(dArr[3], 4);
    ASSERT_EQ(dArr.size(), 4);

    dArr.popBack();
    ASSERT_EQ(dArr.size(), 3);
}

TEST(DynamicArrayTest, CapacityControl)
{
    auto *dArr = new DSinCpp::DArray<int>{1, 2, 3};

    ASSERT_EQ(dArr->capacity(), 3);

    dArr->pushBack(4);
    ASSERT_EQ(dArr->capacity(), 6);

    dArr->pushBack(5);
    ASSERT_EQ(dArr->capacity(), 6);

    dArr->pushBack(6);
    dArr->pushBack(7);
    ASSERT_EQ(dArr->capacity(), 12);

    dArr->popBack();
    ASSERT_FALSE(dArr->capacity() == 12);
    ASSERT_TRUE(dArr->capacity() == 6);

    dArr->popBack();
    dArr->popBack();
    dArr->popBack();

    ASSERT_FALSE(dArr->capacity() == 4);
    ASSERT_FALSE(dArr->capacity() == 3);
    ASSERT_TRUE(dArr->capacity() == 6);

    delete dArr;
    dArr = nullptr;


    dArr = new DSinCpp::DArray<int>{1, 2, 3, 4, 5, 6, 7, 8};
    ASSERT_EQ(dArr->capacity(), dArr->size());

    const size_t size = dArr->size();
    const size_t cap = dArr->capacity();

    for (size_t i = size; i > (cap / 2); --i)
    {
        dArr->popBack();
        if (i != cap / 2 + 1)
            ASSERT_FALSE(dArr->capacity() == dArr->size());
    }

    ASSERT_EQ(dArr->size(), dArr->capacity());

    delete dArr;
    dArr = nullptr;


    //>--------------------------------
    dArr = new DSinCpp::DArray<int>();

    for (size_t i = 0; i < 20; ++i)
    {
        dArr->pushBack(i + 1);
        ASSERT_EQ(dArr->at(i), i + 1);
        ASSERT_EQ(dArr->size(), dArr->at(i));

        if (i < 4)
            ASSERT_EQ(dArr->capacity(), 4);
        else if (dArr->capacity() == dArr->size())
            continue;
        else
            ASSERT_TRUE(dArr->size() < dArr->capacity());
    }

    ASSERT_EQ(dArr->size(), 20);
    ASSERT_EQ(dArr->capacity(), 32);

    struct Person
    {
        int name;
        uint16_t age;
    };

    std::vector<Person> testVector;

    DSinCpp::DArray<Person> personArr;
    ASSERT_EQ(personArr.capacity(), 4);

    delete dArr;
}

TEST(DynamicArrayTest, SizeControl)
{
}

TEST(DynamicArrayTest, PopEmptyMethods)
{
    DSinCpp::DArray<int> dArr{};

    EXPECT_THROW(
        {
            try
            {
                dArr.popBack();
            }
            catch (const std::out_of_range &e)
            {
                EXPECT_STREQ("Error...! [ DArray<>::popBack ] -> Reason: Array is Empty.!", e.what());
                throw;
            }
        },
        std::out_of_range);
}

TEST(DynamicArrayTest, EmplaceBackinUserDefinedTypes)
{

    struct Vector2
    {

        float scalarX;
        float scalarY;

        Vector2() : scalarX(0.0f), scalarY(0.0f)
        {
        }

        explicit Vector2(float scalar) : scalarX(scalar), scalarY(scalar)
        {
        }

        Vector2(float scalarX, float scalarY) : scalarX(scalarX), scalarY(scalarY)
        {
        }

        Vector2 &operator=(const Vector2 &other) = default;
    };

    DSinCpp::DArray<Vector2> dArr;

    std::vector<std::pair<float, float>> testVector{
        {2.0, 2.7},
        {2, 3},
        {5.43, 6.756},
        {2.0, 2.7},
        {0.01, 0.06},
        {(double)0.012132, (double)0.066547},
    };

    dArr.emplaceBack(2.0f, 2.7f);
    dArr.emplaceBack(2.0f, 3.0f);
    dArr.emplaceBack(5.43, 6.756);
    dArr.emplaceBack(2.0, 2.7);
    dArr.emplaceBack(0.01, 0.06);
    dArr.emplaceBack(0.012132f, 0.066547f);

    for (size_t i = 0; i < testVector.size(); ++i)
    {
        ASSERT_EQ(testVector[i].first, dArr[i].scalarX);
        ASSERT_EQ(testVector[i].second, dArr[i].scalarY);
    }
}

TEST(DynamicArrayTest, ElementsSizeAndCapacity)
{
    struct TestVector
    {
        int elementCount;
        int capacity;
    };

    std::vector<TestVector> testVector;
}

TEST(DynamicArrayTest, IndexOverFlow)
{
    DSinCpp::DArray<int> dArr{1, 2, 3, 4};

    EXPECT_THROW(
        {
            try
            {
                dArr[5] = 468;
            }
            catch (const std::out_of_range &e)
            {
                EXPECT_STREQ("Error..! The index you want to reach is exceed the bounds of the array.", e.what());
                throw;
            }
        },
        std::out_of_range);
}

TEST(DynamicArrayTest, ThrowNegativeIndex)
{
    DSinCpp::DArray<int> dArr{1, 2, 3, 4};

    EXPECT_THROW(
        {
            try
            {
                dArr[-5] = 468;
            }
            catch (const std::out_of_range &e)
            {
                EXPECT_STREQ("Error..! The index you want to reach is exceed the bounds of the array.", e.what());
                throw;
            }
        },
        std::out_of_range);
}