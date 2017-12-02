//
// Created by luoyulong on 17/12/2.
//

#ifndef CERES_TEST_MAHAL_DISTANCE_H
#define CERES_TEST_MAHAL_DISTANCE_H

#include <vector>
struct Point
{
    double x;
    double y;

    Point(double _x, double _y):x(_x), y(_y)
    {}

};
class MahalDistance {
public:
    double Distance(const std::vector<Point>& points1, const std::vector<Point>& points2);
private:
    void CalcMeanXY(const std::vector<Point>& points, double* mean_x, double* mean_y);

    void CalcCovariance(const std::vector<Point>& points, std::vector<double>* cov_vec);
};


#endif //CERES_TEST_MAHAL_DISTANCE_H
