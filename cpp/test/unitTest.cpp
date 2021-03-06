#include "../MatLib/matrix.hpp"
#define BOOST_TEST_MODULE MatLib Test
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(multiply_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix1 = {
            {{{0, 1, 2},
                              {3, 4, 5},
                              {6, 7, 8}
            }}};
    MatLib::matrix<float, 3, 3> matrix2 = {
            {{{0, 1, 2},
                              {3, 4, 5},
                              {6, 7, 8}
             }}};
    MatLib::matrix<int, 3, 3> matrix1i = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<int, 3, 3> matrix2i = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix = {
            {{{15, 18, 21},
                              {42, 54, 66},
                              {69, 90, 111}
            }}};
    MatLib::matrix<int, 3, 3> expectedMatrixi = {
            {{{15, 18, 21},
                     {42, 54, 66},
                     {69, 90, 111}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix2 = {
            {{{0, 5, 10},
                     {15, 20, 25},
                     {30, 35, 40}
             }}};
    BOOST_TEST((matrix1 * matrix2) == expectedMatrix);
    BOOST_TEST((matrix1i * matrix2i) == expectedMatrixi);
    BOOST_TEST((matrix1 * 5) == expectedMatrix2);
}

BOOST_AUTO_TEST_CASE(divide_test, *boost::unit_test::tolerance(0.01)) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix1 = {
            {{{10, 11, 12},
                     {13, 14, 15},
                     {16, 17, 18}
             }}};
    MatLib::matrix<float, 3, 3> matrix2 = {
            {{{7, 6, 7},
                     {3, 7, 5},
                     {14, 15, 16}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix = {
            {{{-1.2, -0.4, 1.4},
                     {-0.3, -0.1, 1.1},
                     {0.6, 0.2, 0.8}
             }}};
    MatLib::matrix<double, 3, 3> matrix3 = {
                    {{{10, 15, 20},
                             {5, 6, 8},
                             {14, 7, 88}
                     }}};
    MatLib::matrix<double, 3, 3> expectedMatrix2 = {
            {{{2, 3, 4},
                     {1, 1.2, 1.6},
                     {2.8, 1.4, 17.6}
             }}};
    BOOST_TEST((matrix1 / matrix2) == expectedMatrix);
    BOOST_TEST((matrix3 / 5) == expectedMatrix2);
}

BOOST_AUTO_TEST_CASE(addition_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix1 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> matrix2 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix12 = {
            {{{0, 2, 4},
                     {6, 8, 10},
                     {12, 14, 16}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix1S = {
            {{{7, 8, 9},
                     {10, 11, 12},
                     {13, 14, 15}
             }}};
    BOOST_TEST((matrix1 + matrix2) == expectedMatrix12);
    BOOST_TEST((matrix1 + 7) == expectedMatrix1S);
    expectedMatrix1S += 1;
    MatLib::matrix<float, 3, 3> expectedTest = {
            {{{8, 9, 10},
                     {11, 12, 13},
                     {14, 15, 16}
             }}};
    BOOST_TEST(expectedMatrix1S == expectedTest);
}

BOOST_AUTO_TEST_CASE(subtraction_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix1 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> matrix2 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix12 = {
            {{{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix1S = {
            {{{-5, -4, -3},
                     {-2, -1, 0},
                     {1, 2, 3}
             }}};
    MatLib::matrix<float, 3, 3> negMatrix = {
            {{{-0, -1, -2},
                     {-3, -4, -5},
                     {-6, -7, -8}
             }}};
    BOOST_TEST((matrix1 - matrix2) == expectedMatrix12);
    BOOST_TEST((matrix1 - 5) == expectedMatrix1S);
    BOOST_TEST(-matrix1 == negMatrix);
}

BOOST_AUTO_TEST_CASE(determinant_test, *boost::unit_test::tolerance(0.01)) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 2, 2> matrix2x2 = {
            {{{0, 1},
                     {3, 4}
             }}};
    MatLib::matrix<float, 4, 4> matrix4x4 = {
            {{{0, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    MatLib::matrix<int, 4, 4> matrix4x4i = {
            {{{0, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    MatLib::matrix<double, 5, 5> matrix5x5 = {
            {{{5, 35, 2, 3, 39.4},
                     {12.004, 15, 12, 7, 31},
                     {24, 9, 10, 11.3, 4.4},
                     {12, 47.234, 5, 14, 14},
                     {3.32, 6, 1, 26, 5}
             }}};
    BOOST_TEST(matrix2x2.getDeterminant() == -3);
    BOOST_TEST(matrix3x3.getDeterminant() == 0);
    BOOST_TEST(matrix4x4.getDeterminant() == -5904);
    BOOST_TEST(matrix4x4i.getDeterminant() == -5904);
    BOOST_TEST(matrix5x5.getDeterminant() == 5182129.02628431);
}

BOOST_AUTO_TEST_CASE(row_echelon_test, *boost::unit_test::tolerance(0.01)) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{3, 4, 5},
                     {0, 1, 2},
                     {0, 0, 0}
             }}};
    auto [result3x3, isAddition] = matrix3x3.getRowEchelon();
    BOOST_TEST(result3x3 == expectedMatrix3x3);
    MatLib::matrix<float, 4, 4> matrix4x4 = {
            {{{5, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    MatLib::matrix<float, 4, 4> expectedMatrix4x4 = {
            {{{5, 8, 2, 3},
                     {0, -1.4, 10.4, 4.6},
                     {0, 0, 27.7140007, 17.1429996},
                     {0, 0, 0, -74.5670013}
             }}};
    auto [result4x4, isAddition4x4] = matrix4x4.getRowEchelon();
    BOOST_TEST(result4x4 == expectedMatrix4x4);
}

BOOST_AUTO_TEST_CASE(transpose_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{0, 3, 6},
                     {1, 4, 7},
                     {2, 5, 8}
             }}};
    BOOST_TEST(matrix3x3.getTranspose() == expectedMatrix3x3);
    MatLib::matrix<int, 4, 4> matrix4x4 = {
            {{{5, 8, 2, 3},
                     {4, 5, 12, 7},
                     {4, 9, 10, 11},
                     {12, 77, 14, 14}
             }}};
    MatLib::matrix<int, 4, 4> expectedMatrix4x4 = {
            {{{5, 4, 4, 12},
                     {8, 5, 9, 77},
                     {2, 12, 10, 14},
                     {3, 7, 11, 14}
             }}};
    BOOST_TEST(matrix4x4.getTranspose() == expectedMatrix4x4);
}

BOOST_AUTO_TEST_CASE(augment_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> matrix3x32 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 6> expectedMatrix3x3 = {
            {{{0, 1, 2, 0,  1, 2},
                     {3, 4, 5, 3, 4, 5},
                     {6, 7, 8, 6, 7, 8}
             }}};
    BOOST_TEST(matrix3x3.getAugment(matrix3x32) == expectedMatrix3x3);
}

BOOST_AUTO_TEST_CASE(identity_test) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{1, 0, 0},
                     {0, 1, 0},
                     {0, 0, 1}
             }}};
    BOOST_TEST(matrix3x3.getIdentity() == expectedMatrix3x3);
}

BOOST_AUTO_TEST_CASE(inverse_test, *boost::unit_test::tolerance(0.01)) // NOLINT
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{3, 7, 8},
                     {5, 1, 5},
                     {7, 2, 5}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{-0.0632911697, -0.240506232	, 0.341772079},
                     {0.12658228, -0.518987358	, 0.316455722},
                     {0.0379746817, 0.544303775, -0.405063301}
             }}};
    BOOST_TEST(matrix3x3.getInverse() == expectedMatrix3x3);
}

BOOST_AUTO_TEST_CASE(orthogonal_test)  // NOLINT
{
    MatLib::matrix<int, 2, 2> matrix4x4 = {
                   {{{1, 0},
                     {0, 1}
             }}};
    BOOST_TEST(matrix4x4.isOrthogonal() == true);
}

BOOST_AUTO_TEST_CASE(sort_test)  // NOLINT // helps check begin and rebegin iterators.
{
    MatLib::matrix<float, 3, 3> matrix3x3 = {
            {{{3, 7, 8},
                     {5, 1, 5},
                     {7, 2, 5}
             }}};
    MatLib::matrix<float, 3, 3> expectedMatrix3x3 = {
            {{{1, 2, 3},
                     {5, 5, 5},
                     {7, 7, 8}
             }}};
    std::sort(matrix3x3.begin(), matrix3x3.end());
    BOOST_TEST(matrix3x3 == expectedMatrix3x3);
    MatLib::matrix<float, 3, 3> expectedReversed = {
            {{{8, 7, 7},
                     {5, 5, 5},
                     {3, 2, 1}
             }}};
    std::sort(matrix3x3.rbegin(), matrix3x3.rend());
    BOOST_TEST(matrix3x3 == expectedReversed);
}

BOOST_AUTO_TEST_CASE(find_test)  // NOLINT
{
    MatLib::matrix<int, 3, 3> matrix3x3 = {
            {{{3, 7, 0},
                     {5, 1, 2},
                     {0, 2, 5}
             }}};
    BOOST_TEST((*std::find(matrix3x3.cbegin(), matrix3x3.cend(), 0)) == 0);
    BOOST_TEST((*std::find(matrix3x3.crbegin(), matrix3x3.crend(), 0)) == 0);
}

BOOST_AUTO_TEST_CASE(empty_test)  // NOLINT
{
    MatLib::matrix<int, 3, 3> matrix3x3 = {
            {{{3, 7, 0},
                     {5, 1, 2},
                     {5, 2, 5}
             }}};
    MatLib::matrix<int, 0, 0> emptyMatrix;
    
    BOOST_TEST(matrix3x3.empty() == false);
    BOOST_TEST(emptyMatrix.empty() == true);
}

BOOST_AUTO_TEST_CASE(fill_test)  // NOLINT
{
    MatLib::matrix<int, 3, 3> fillMatrix;
    fillMatrix.fill(4);
    MatLib::matrix<int, 3, 3> resultMatrix = {{{{4, 4, 4},
                                                {4, 4, 4},
                                                {4, 4, 4}}}};
    BOOST_TEST(fillMatrix == resultMatrix);
}

BOOST_AUTO_TEST_CASE(swap_test)  // NOLINT
{
    MatLib::matrix<int, 3, 3> matrix3x3 = {
                                         {{{0, 1, 2},
                                           {3, 4, 5},
                                           {6, 7, 8}
             }}};
    MatLib::matrix<int, 3, 3> matrix3x32 = {
                                         {{{3, 7, 0},
                                           {5, 1, 2},
                                           {5, 2, 5}
             }}};
    MatLib::matrix<int, 3, 3> matrix3x3R = {
            {{{3, 7, 0},
                     {5, 1, 2},
                     {5, 2, 5}
             }}};
    MatLib::matrix<int, 3, 3> matrix3x32R = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    matrix3x3.swap(matrix3x32);
    BOOST_TEST(matrix3x3 == matrix3x3R);
    BOOST_TEST(matrix3x32 == matrix3x32R);
}

BOOST_AUTO_TEST_CASE(at_test)  // NOLINT
{
    MatLib::matrix<int, 3, 3> matrix3x3 = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 8}
             }}};
    const MatLib::matrix<int, 3, 3> matrix3x3c = {
            {{{0, 1, 2},
                     {3, 4, 5},
                     {6, 7, 22}
             }}};
    BOOST_TEST(matrix3x3.at(0, 0) == 0);
    BOOST_TEST(matrix3x3.at(2, 1) == 7);
    BOOST_TEST(matrix3x3c.at(2, 2) == 22);
    try{
        matrix3x3.at(20, 0) = 0; 
    }
    catch(std::out_of_range& except){
        BOOST_TEST(except.what() == "Element out of range");
    }
}

BOOST_AUTO_TEST_CASE(iterator_test)  // NOLINT
{
    MatLib::matrix<int, 4, 4> matrix4x4 = {
            {{{0, 1, 2, 3},
                     {4, 5, 6, 7},
                     {7, 9, 10, 11},
                     {12, 13, 14, 15}
             }}};
    const MatLib::matrix<int, 4, 4> constMatrix = {
            {{{0, 1, 2, 3},
                     {4, 5, 6, 7},
                     {7, 9, 10, 11},
                     {12, 13, 14, 15}
             }}};
    BOOST_TEST(*matrix4x4.data() == 0);
    BOOST_TEST(*constMatrix.data() == 0);
    BOOST_TEST(matrix4x4.front() == 0);
    BOOST_TEST(constMatrix.front() == 0);
    BOOST_TEST(matrix4x4.back() == 15);
    BOOST_TEST(constMatrix.back() == 15);
}