//
// Created by luoyulong on 17/12/2.
//

#include <gtest/gtest.h>
#include "mahalanobis_distance/mahal_distance.h"
class TestMahalDistance: public testing::Test
{
public:
    void SetUp() override
    {}

    void TearDown() override
    {
    }

public:

};

TEST_F(TestMahalDistance, test1)
{
    std::vector<Point> points1;
    std::vector<Point> points2;

    points1.emplace_back(2, 2);
    points1.emplace_back(2, 5);
    points1.emplace_back(6, 5);
    points1.emplace_back(7, 3);
    points1.emplace_back(4, 7);
    points1.emplace_back(6, 4);
    points1.emplace_back(5, 3);
    points1.emplace_back(4, 6);
    points1.emplace_back(2, 5);
    points1.emplace_back(1, 3);

    points2.emplace_back(6, 5);
    points2.emplace_back(7, 4);
    points2.emplace_back(8, 7);
    points2.emplace_back(5, 6);
    points2.emplace_back(5, 4);

    MahalDistance mahalDistance;
    double distance = mahalDistance.Distance(points1, points2);

    ASSERT_TRUE((distance - 1.41) <= 0.05);
}


TEST_F(TestMahalDistance, test2)
{
    std::vector<Point> points1;
    std::vector<Point> points2;

    points1.emplace_back(2, 2);
    points1.emplace_back(3, 2);

    points2.emplace_back(6, 5);
    points2.emplace_back(7, 5);

    MahalDistance mahalDistance;
    double distance = mahalDistance.Distance(points1, points2);

    ASSERT_TRUE((distance - 5) <= 0.01);






}

