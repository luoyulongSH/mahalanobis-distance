//
// Created by luoyulong on 17/12/2.
// http://people.revoledu.com/kardi/tutorial/Similarity/MahalanobisDistance.html
//

#include "mahal_distance.h"
#include <cmath>

double MahalDistance::Distance(const std::vector<Point>& points1, const std::vector<Point>& points2)
{
    std::vector<double> cov_a;
    std::vector<double> cov_b;

    CalcCovariance(points1, &cov_a);
    CalcCovariance(points2, &cov_b);

    double inv_all = 1.0 / (points1.size() + points2.size());
    for (size_t i = 0; i < cov_a.size(); ++i)
    {
        cov_a[i] = cov_a[i] * points1.size() * inv_all + cov_b[i] * points2.size() * inv_all;
    }

    double ad_bc = (cov_a[0] * cov_a[2] - cov_a[1] * cov_a[1]);
    if (std::fabs(ad_bc) <= std::numeric_limits<double>::epsilon())
    {
        double mean_a_x, mean_a_y;
        double mean_b_x, mean_b_y;
        CalcMeanXY(points1, &mean_a_x, &mean_a_y);
        CalcMeanXY(points2, &mean_b_x, &mean_b_y);

        double value_x = mean_a_x - mean_b_x;
        double value_y = mean_a_y - mean_b_y;
        return std::sqrt(value_x * value_x + value_y * value_y);
    }
    else
    {
        double inv_ad_bc = 1.0 / (cov_a[0] * cov_a[2] - cov_a[1] * cov_a[1]);
        std::vector<double> inv_cov(4);
        inv_cov[0] = cov_a[2] * inv_ad_bc;
        inv_cov[1] = -cov_a[1] * inv_ad_bc;
        inv_cov[2] = inv_cov[1];
        inv_cov[3] = cov_a[0] * inv_ad_bc;

        double mean_a_x, mean_a_y;
        double mean_b_x, mean_b_y;
        CalcMeanXY(points1, &mean_a_x, &mean_a_y);
        CalcMeanXY(points2, &mean_b_x, &mean_b_y);

        double value_x = mean_a_x - mean_b_x;
        double value_y = mean_a_y - mean_b_y;

        double temp1 = value_x * inv_cov[0] + value_y * inv_cov[1];
        double temp2 = value_x * inv_cov[2] + value_y * inv_cov[3];

        double dist = std::sqrt( temp1 * value_x + temp2 * value_y);

        return dist;
    }

}

void MahalDistance::CalcMeanXY(const std::vector<Point>& points, double* mean_x, double* mean_y)
{
    *mean_x = 0;
    *mean_y = 0;
    for (const Point& point :points)
    {
        *mean_x += point.x;
        *mean_y += point.y;
    }

    *mean_x /= points.size();
    *mean_y /= points.size();
}

void MahalDistance::CalcCovariance(const std::vector<Point>& points, std::vector<double>* cov_vec)
{
    double mean_x = 0, mean_y = 0;
    CalcMeanXY(points, &mean_x, &mean_y);

    cov_vec->resize(3, 0);
    std::vector<double>& cov = *cov_vec;
    for (const Point& point :points)
    {
        cov[0] += std::pow(point.x - mean_x, 2);
        cov[2] += std::pow(point.y - mean_y, 2);
        cov[1] += (point.x - mean_x) * (point.y - mean_y);
    }

    double inv_size = 1.0 / points.size();
    cov[0] *= inv_size;
    cov[1] *= inv_size;
    cov[2] *= inv_size;
}




