#include <gtest/gtest.h>
#include "Time.h"

TEST(Time, defaulConstructor)
{
    Time t;
    ASSERT_EQ(t.getHours(), 0);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, Parametr_ctor_normalization)
{
    Time t(23, 59, 59);
    ASSERT_EQ(t.getHours(), 23);
    ASSERT_EQ(t.getMinutes(), 59);
    ASSERT_EQ(t.getSeconds(), 59);
}

TEST(Time, Parametr_ctor_negative_input)
{
    Time t(-5, -40, -23);
    ASSERT_EQ(t.getHours(), 0);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, Parameter_ctorNormalization)
{
    Time t(1, 120, 90);
    ASSERT_EQ(t.getHours(), 3);
    ASSERT_EQ(t.getMinutes(), 1);
    ASSERT_EQ(t.getSeconds(), 30);
}

TEST(Time, SetHours)
{
    Time t;
    t.setHours(5);
    ASSERT_EQ(t.getHours(), 5);
}

TEST(Time, SetHours_invalid)
{
    Time t;
    t.setHours(5.4);
    ASSERT_EQ(t.getHours(), 5);
}

TEST(Time, SetHours_invalid_2)
{
    Time t;
    t.setHours(5.6);
    ASSERT_EQ(t.getHours(), 5);
}

TEST(Time, SetHours_negativ)
{
    Time t;
    t.setHours(-5);
    ASSERT_EQ(t.getHours(), 0);
}

TEST(Time, SetMinutes)
{
    Time t;
    t.setMinutes(30);
    ASSERT_EQ(t.getMinutes(), 30);
}


TEST(Time, SetSeconds)
{
    Time t;
    t.setSeconds(45);
    ASSERT_EQ(t.getSeconds(), 45);
}

TEST(Time, Setters_Normalization_seconds)
{
    Time t;
    t.setSeconds(3661);
    ASSERT_EQ(t.getHours(), 1);
    ASSERT_EQ(t.getMinutes(), 1);
    ASSERT_EQ(t.getSeconds(), 1);
}

TEST(Time, Setters_Normalization_Minutes)
{
    Time t;
    t.setMinutes(3661);
    ASSERT_EQ(t.getHours(), 61);
    ASSERT_EQ(t.getMinutes(), 1);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, Setters_Normalization_Hours)
{
    Time t;
    t.setHours(366);
    ASSERT_EQ(t.getHours(), 366);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, AddSeconds)
{
    Time t(0, 0, 55);
    t.addSeconds(10);
    ASSERT_EQ(t.getMinutes(), 1);
    ASSERT_EQ(t.getSeconds(), 5);
}

TEST(Time, AddSeconds_negative)
{
    Time t(0, 0, 55);
    t.addSeconds(-10);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 45);
}

TEST(Time, AddMinutes)
{
    Time t(0, 55, 0);
    t.addMinutes(10);
    ASSERT_EQ(t.getHours(), 1);
    ASSERT_EQ(t.getMinutes(), 5);
}

TEST(Time, AddMinutes_negative)
{
    Time t(0, 55, 0);
    t.addMinutes(-10);
    ASSERT_EQ(t.getHours(), 0);
    ASSERT_EQ(t.getMinutes(), 45);
}

TEST(Time, AddHours)
{
    Time t(23, 0, 0);
    t.addHours(2);
    ASSERT_EQ(t.getHours(), 25);
}

TEST(Time, AddHours_negative)
{
    Time t(23, 0, 0);
    t.addHours(-2);
    ASSERT_EQ(t.getHours(), 21);
}

TEST(Time, OperatorPlus)
{
    Time t1(1, 30, 30);
    Time t2(2, 15, 45);
    Time t3 = t1 + t2;
    ASSERT_EQ(t3.getHours(), 3);
    ASSERT_EQ(t3.getMinutes(), 46);
    ASSERT_EQ(t3.getSeconds(), 15);
}

TEST(Time, OperatorMinus)
{
    Time t1(3, 30, 30);
    Time t2(2, 15, 15);
    Time t3 = t1 - t2;
    ASSERT_EQ(t3.getHours(), 1);
    ASSERT_EQ(t3.getMinutes(), 15);
    ASSERT_EQ(t3.getSeconds(), 15);
}

TEST(Time, OperatorMinusLessThanZero)
{
    Time t1(3, 30, 30);
    Time t2(4, 15, 15);
    Time t3 = t1 - t2;
    ASSERT_EQ(t3.getHours(), 0);
    ASSERT_EQ(t3.getMinutes(), 0);
    ASSERT_EQ(t3.getSeconds(), 0);
}

TEST(Time, OperatorPlusEqual)
{
    Time t1(1, 30, 30);
    Time t2(0, 30, 30);
    t1 += t2;
    ASSERT_EQ(t1.getHours(), 2);
    ASSERT_EQ(t1.getMinutes(), 1);
    ASSERT_EQ(t1.getSeconds(), 0);
}

TEST(Time, OperatorMinusEqual)
{
    Time t1(2, 0, 0);
    Time t2(1, 30, 30);
    t1 -= t2;
    ASSERT_EQ(t1.getHours(), 0);
    ASSERT_EQ(t1.getMinutes(), 29);
    ASSERT_EQ(t1.getSeconds(), 30);
}

TEST(Time, OperatorMinusEqualLessthanZero)
{
    Time t1(2, 0, 0);
    Time t2(2, 30, 30);
    t1 -= t2;
    ASSERT_EQ(t1.getHours(), 0);
    ASSERT_EQ(t1.getMinutes(), 0);
    ASSERT_EQ(t1.getSeconds(), 0);
}

TEST(Time, OperatorLessThan)
{
    Time t1(1, 0, 0);
    Time t2(2, 0, 0);
    ASSERT_TRUE(t1 < t2);
}

TEST(Time, OperatorGreaterThan)
{
    Time t1(3, 0, 0);
    Time t2(2, 0, 0);
    ASSERT_TRUE(t1 > t2);
}

TEST(Time, OperatorLessThanOrEqual)
{
    Time t1(2, 0, 0);
    Time t2(2, 0, 0);
    ASSERT_TRUE(t1 <= t2);
}

TEST(Time, OperatorGreaterThanOrEqual)
{
    Time t1(2, 0, 0);
    Time t2(1, 59, 59);
    ASSERT_TRUE(t1 >= t2);
}

TEST(Time, OperatorEqual)
{
    Time t1(1, 1, 1);
    Time t2(1, 1, 1);
    ASSERT_TRUE(t1 == t2);
}

TEST(Time, OperatorNotEqual)
{
    Time t1(1, 1, 1);
    Time t2(2, 2, 2);
    ASSERT_TRUE(t1 != t2);
}

TEST(Time, OperatorInsertion)
{
    Time t(11, 34, 56);
    std::ostringstream os;
    os << t;
    ASSERT_EQ(os.str(), "11:34:56");
}

TEST(Time, OperatorExtractionValid)
{
    std::istringstream is("12:34:56");
    Time t;
    is >> t;
    ASSERT_EQ(t.getHours(), 12);
    ASSERT_EQ(t.getMinutes(), 34);
    ASSERT_EQ(t.getSeconds(), 56);
}

TEST(Time, OperatorExtractionRequaeringNormalization)
{
    std::istringstream is("25:61:61");
    Time t;
    is >> t;
    ASSERT_EQ(t.getHours(), 26);
    ASSERT_EQ(t.getMinutes(), 2);
    ASSERT_EQ(t.getSeconds(), 1);
}

TEST(Time, OperatorExtractionNegativ)
{
    std::istringstream is("25:-61:61");
    Time t;
    is >> t;
    ASSERT_EQ(t.getHours(), 0);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, OperatorPlusEqualsAddsSeconds)
{
    Time t(1, 0, 30);
    t += 45;
    ASSERT_EQ(t.getHours(), 1);
    ASSERT_EQ(t.getMinutes(), 1);
    ASSERT_EQ(t.getSeconds(), 15);
}

TEST(Time, OperatorPlusEqualsAddWithneededNormalization)
{
    Time t(23, 59, 30);
    t += 35;
    ASSERT_EQ(t.getHours(), 24);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 5);
}

TEST(Time, OperatorPlusEqualsWithNegativeSeconds)
{
    Time t(1, 0, 0);
    t += -120;
    ASSERT_EQ(t.getHours(), 0);
    ASSERT_EQ(t.getMinutes(), 58);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, OperatorPlusAddsSeconds)
{
    Time t(2, 30, 0);
    Time result = t + 90;
    ASSERT_EQ(result.getHours(), 2);
    ASSERT_EQ(result.getMinutes(), 31);
    ASSERT_EQ(result.getSeconds(), 30);
}

TEST(Time, OperatorPlusAddowithnormalzation)
{
    Time t(23, 59, 59);
    Time result = t + 2;
    ASSERT_EQ(result.getHours(), 24);
    ASSERT_EQ(result.getMinutes(), 0);
    ASSERT_EQ(result.getSeconds(), 1);
}

TEST(Time, OperatorPlusWithNegativeSeconds)
{
    Time t(0, 1, 0);
    Time result = t + (-30);
    ASSERT_EQ(result.getHours(), 0);
    ASSERT_EQ(result.getMinutes(), 0);
    ASSERT_EQ(result.getSeconds(), 30);
}

TEST(Time, OperatorMinusEqualsSubtractsSeconds)
{
    Time t(1, 1, 30);
    t -= 60;
    ASSERT_EQ(t.getHours(), 1);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 30);
}

TEST(Time, OperatorMinusEqualsWithNegativeSeconds)
{
    Time t(1, 0, 0);
    t -= -120;
    ASSERT_EQ(t.getHours(), 1);
    ASSERT_EQ(t.getMinutes(), 2);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, OperatorMinusSubtractsSeconds)
{
    Time t(2, 30, 0);
    Time result = t - 90;
    ASSERT_EQ(result.getHours(), 2);
    ASSERT_EQ(result.getMinutes(), 28);
    ASSERT_EQ(result.getSeconds(), 30);
}

TEST(Time, OperatorMinusWithNegativeSeconds)
{
    Time t(0, 2, 0);
    Time result = t - (-30);
    ASSERT_EQ(result.getHours(), 0);
    ASSERT_EQ(result.getMinutes(), 2);
    ASSERT_EQ(result.getSeconds(), 30);
}

TEST(Time, OperatorMultiplyMultipliesTime)
{
    Time t(2, 15, 10);
    t *= 2;
    ASSERT_EQ(t.getHours(), 4);
    ASSERT_EQ(t.getMinutes(), 30);
    ASSERT_EQ(t.getSeconds(), 20);
}

TEST(Time, OperatorMultiplyMultipliesTime2)
{
    Time t(0, 30, 15);
    Time result = t * 3;
    ASSERT_EQ(result.getHours(), 1);
    ASSERT_EQ(result.getMinutes(), 30);
    ASSERT_EQ(result.getSeconds(), 45);
}

TEST(Time, OperatorMultiplyWithNegativeFactor)
{
    Time t(0, 20, 0);
    Time result = t * (-2);
    ASSERT_EQ(result.getHours(), 0);
    ASSERT_EQ(result.getMinutes(), 0);
    ASSERT_EQ(result.getSeconds(), 0);
}

TEST(Time, PreIncrementIncreasesSecondsByOne)
{
    Time t(10, 59, 59);
    ++t;
    ASSERT_EQ(t.getHours(), 11);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, PostIncrementIncreasesSecondsByOne)
{
    Time t(10, 59, 59);
    Time old = t++;
    ASSERT_EQ(old.getHours(), 10);
    ASSERT_EQ(old.getMinutes(), 59);
    ASSERT_EQ(old.getSeconds(), 59);
    ASSERT_EQ(t.getHours(), 11);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, PreDecrementDecreasesSecondsByOne)
{
    Time t(11, 0, 0);
    --t;
    ASSERT_EQ(t.getHours(), 10);
    ASSERT_EQ(t.getMinutes(), 59);
    ASSERT_EQ(t.getSeconds(), 59);
}

TEST(Time, PreDecrementDecreasesSecondsByOneZero)
{
    Time t(0, 0, 0);
    --t;
    ASSERT_EQ(t.getHours(), 0);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, PostDecrementDecreasesSecondsByOneZero)
{
    Time t(0, 0, 0);
    --t;
    ASSERT_EQ(t.getHours(), 0);
    ASSERT_EQ(t.getMinutes(), 0);
    ASSERT_EQ(t.getSeconds(), 0);
}

TEST(Time, PostDecrementDecreasesSecondsByOne)
{
    Time t(11, 0, 0);
    Time old = t--;
    ASSERT_EQ(old.getHours(), 11);
    ASSERT_EQ(old.getMinutes(), 0);
    ASSERT_EQ(old.getSeconds(), 0);
    ASSERT_EQ(t.getHours(), 10);
    ASSERT_EQ(t.getMinutes(), 59);
    ASSERT_EQ(t.getSeconds(), 59);
}

TEST(Time, FunctionCallOperatorSetsTime)
{
    Time t;
    t(13, 14, 15);
    ASSERT_EQ(t.getHours(), 13);
    ASSERT_EQ(t.getMinutes(), 14);
    ASSERT_EQ(t.getSeconds(), 15);
}

TEST(Time, FunctionCallOperatorHandlesNegative)
{
    Time t;
    t(-25, 60, 60);
    ASSERT_EQ(t.getHours(), 1);
    ASSERT_EQ(t.getMinutes(), 1);
    ASSERT_EQ(t.getSeconds(), 0);
}
