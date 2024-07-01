#include "gtest/gtest.h"
#include "../FractionLib/Fraction.h"

TEST(FractionTestConstructor, CreateFractionDefaultConstructor)
{
  Fraction f;
  EXPECT_EQ(0, f.getNumerator());
  EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionWithZeroNumerator)
{
  Fraction f(0, 8);
  EXPECT_EQ(0, f.getNumerator());
  EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionWithZeroNumeratorAndNegativeDenominator)
{
	Fraction f(0, -38);
	EXPECT_EQ(0, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionWithZeroDenominator)
{
	EXPECT_THROW(Fraction f(45, 0), std::invalid_argument);
}

TEST(FractionTestConstructor, CreateFractionWithZeroDenominatorAndNegativeNumerator)
{
	EXPECT_THROW(Fraction f(-36, 0), std::invalid_argument);
}

TEST(FractionTestConstructor, CreateFractionWithZeroNumeratorAndDenominator)
{
	EXPECT_THROW(Fraction f(0, 0), std::invalid_argument);
}

TEST(FractionTestConstructor, CreateFractionNumeratorEqualsDenominator)
{
  Fraction f(1, 1);
  EXPECT_EQ(1, f.getNumerator());
  EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionNumeratorEqualsDenominatorBothNegative)
{
	Fraction f(-1, -1);
	EXPECT_EQ(1, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionNumeratorEqualsDenominatorWithNegativeNumerator)
{
	Fraction f(-1, 1);
	EXPECT_EQ(-1, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionNumeratorEqualsDenominatorWithNegativeDenominator)
{
	Fraction f(1, -1);
	EXPECT_EQ(-1, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionNumeratorEqualsDenominatorRequiresNormalization)
{
	Fraction f(5, 5);
	EXPECT_EQ(1, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionNumeratorEqualsDenominatorBothNegativeRequiresNormalization)
{
	Fraction f(-12, -12);
	EXPECT_EQ(1, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionNumeratorModulusEqualsDenominatorModulusWithNegativeNumeratorRequiresNormalization)
{
	Fraction f(-44, 44);
	EXPECT_EQ(-1, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionNumeratorModulusEqualsDenominatorModulusWithNegativeDenominatorRequiresNormalization)
{
	Fraction f(55, -55);
	EXPECT_EQ(-1, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}
TEST(FractionTestConstructor, CreateFractionGreaterThanOne)
{
	Fraction f(15, 8);
	EXPECT_EQ(15, f.getNumerator());
	EXPECT_EQ(8, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionGreaterThanOneWithNegativeNumeratorAndNegativeDenominator)
{
	Fraction f(-25, -11);
	EXPECT_EQ(25, f.getNumerator());
	EXPECT_EQ(11, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionLessThanMinusOneWithNegativeNumerator)
{
	Fraction f(-17, 4);
	EXPECT_EQ(-17, f.getNumerator());
	EXPECT_EQ(4, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionLessThanMinusOneWithNegativeDenominator)
{
	Fraction f(31, -14);
	EXPECT_EQ(-31, f.getNumerator());
	EXPECT_EQ(14, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionlassThanOne)
{
	Fraction f(4, 35);
	EXPECT_EQ(4, f.getNumerator());
	EXPECT_EQ(35, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionLessThanOneWithNegativeNumeratorAndNegativeDenominator)
{
	Fraction f(-11, -25);
	EXPECT_EQ(11, f.getNumerator());
	EXPECT_EQ(25, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionGreaterThanMinusOneWithNegativeNumerator)
{
	Fraction f(4, -17);
	EXPECT_EQ(-4, f.getNumerator());
	EXPECT_EQ(17, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionGreaterThanMinusOneWithNegativeDenominator)
{
	Fraction f(-14, 31);
	EXPECT_EQ(-14, f.getNumerator());
	EXPECT_EQ(31, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionGreaterThanOneRequiresNormalization)
{
	Fraction f(36, 12);
	EXPECT_EQ(3, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionGreaterThanOneWithNegativeNumeratorAndNegativeDenominatorRequiresNormalization)
{
	Fraction f(-66, -44);
	EXPECT_EQ(3, f.getNumerator());
	EXPECT_EQ(2, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionLessThanMinusOneWithNegativeNumeratorRequiresNormalization)
{
	Fraction f(-30, 12);
	EXPECT_EQ(-5, f.getNumerator());
	EXPECT_EQ(2, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionLessThanMinusOneWithNegativeDenominatorRequiresNormalization)
{
	Fraction f(60, -35);
	EXPECT_EQ(-12, f.getNumerator());
	EXPECT_EQ(7, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionLessThanOneRequiresNormalization)
{
	Fraction f(42, 60);
	EXPECT_EQ(7, f.getNumerator());
	EXPECT_EQ(10, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionLessThanOneWithNegativeNumeratorAndNegativeDenominatorRequiresNormalization)
{
	Fraction f(-66, -99);
	EXPECT_EQ(2, f.getNumerator());
	EXPECT_EQ(3, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionGreaterThanMinusOneWithNegativeNumeratorRequiresNormalization)
{
	Fraction f(-12, 60);
	EXPECT_EQ(-1, f.getNumerator());
	EXPECT_EQ(5, f.getDenominator());
}

TEST(FractionTestConstructor, CreateFractionGreaterThanMinusOneWithNegativeDenominatorRequiresNormalization)
{
	Fraction f(35, -42);
	EXPECT_EQ(-5, f.getNumerator());
	EXPECT_EQ(6, f.getDenominator());
}

TEST(FractionTestConstructor, CopyFraction)
{
	Fraction f(-5, 6);
	Fraction f2(f);
	EXPECT_EQ(-5, f2.getNumerator());
	EXPECT_EQ(6, f2.getDenominator());
}

TEST(FractionTestAddition, AddFractionsDenominatorsAreEqual)
{
  Fraction f1(2, 9);
  Fraction f2(5, 9);
  Fraction f3 = f1 + f2;
  EXPECT_EQ(7, f3.getNumerator());
  EXPECT_EQ(9, f3.getDenominator());
}

// Add more tests for addition operator
TEST(FractionTestAddition, AddFractionsDenominatorsAreDiffrent)
{
	Fraction f1(2, 3);
	Fraction f2(5, 9);
	Fraction f3 = f1 + f2;
	EXPECT_EQ(11, f3.getNumerator());
	EXPECT_EQ(9, f3.getDenominator());
}

TEST(FractionTestAddition, AddFractionsNominatorisnegativ)
{
	Fraction f1(-2, 9);
	Fraction f2(5, 9);
	Fraction f3 = f1 + f2;
	EXPECT_EQ(1, f3.getNumerator());
	EXPECT_EQ(3, f3.getDenominator());
}

TEST(FractionTestAddition, AddFractionsNominatorisBothNegativ)
{
	Fraction f1(-2, 9);
	Fraction f2(-3, 9);
	Fraction f3 = f1 + f2;
	EXPECT_EQ(-5, f3.getNumerator());
	EXPECT_EQ(9, f3.getDenominator());
}

TEST(FractionTestAddition, AddAndAssignFractionsDenominatorsAreEqual)
{
	Fraction f1(2, 9);
	Fraction f2(5, 9);
	f1 += f2;
	EXPECT_EQ(7, f1.getNumerator());
	EXPECT_EQ(9, f1.getDenominator());
}

// Add more tests for addition assignment operator
TEST(FractionTestAddition, AddAndAssignFractionsWithDifferentDenominators) {
	Fraction f1(1, 3);
	Fraction f2(2, 6);
	f1 += f2;
	EXPECT_EQ(2, f1.getNumerator());
	EXPECT_EQ(3, f1.getDenominator());
}

TEST(FractionTestAddition, AddAndAssignFractionToItself) {
	Fraction f1(3, 5);
	f1 += f1;
	EXPECT_EQ(6, f1.getNumerator());
	EXPECT_EQ(5, f1.getDenominator());
}

TEST(FractionTestAddition, AddAndAssignNegativeFraction) {
	Fraction f1(1, 7);
	Fraction f2(-2, 7);
	f1 += f2;
	EXPECT_EQ(-1, f1.getNumerator());
	EXPECT_EQ(7, f1.getDenominator());
}

TEST(FractionTestSubtraction, SubtractFractionsDenominatorsAreEqual)
{
	Fraction f1(4, 9);
	Fraction f2(5, 9);
	Fraction f3 = f1 - f2;
	EXPECT_EQ(-1, f3.getNumerator());
	EXPECT_EQ(9, f3.getDenominator());
}

// Add more tests for subtraction operator
TEST(FractionTestSubtraction, SubtractFractionsWithDifferentDenominators) {
	Fraction f1(1, 3);
	Fraction f2(1, 6);
	Fraction result = f1 - f2;
	EXPECT_EQ(1, result.getNumerator());
	EXPECT_EQ(6, result.getDenominator());
}

TEST(FractionTestSubtraction, SubtractFractionFromItself) {
	Fraction f1(5, 8);
	Fraction result = f1 - f1;
	EXPECT_EQ(0, result.getNumerator());
	EXPECT_EQ(1, result.getDenominator());
}

TEST(FractionTestSubtraction, SubtractNegativeFractions) {
	Fraction f1(-1, 4);
	Fraction f2(-1, 4);
	Fraction result = f1 - f2;
	EXPECT_EQ(0, result.getNumerator());
	EXPECT_EQ(1, result.getDenominator());
}
TEST(FractionTestSubtraction, SubtractAndAssignFractionsDenominatorsAreEqual)
{
	Fraction f1(4, 9);
	Fraction f2(5, 9);
	f1 -= f2;
	EXPECT_EQ(-1, f1.getNumerator());
	EXPECT_EQ(9, f1.getDenominator());
}

// TODO: Add more tests for subtraction assignment operator
TEST(FractionTestSubtraction, SubtractAndAssignFractionsWithDifferentDenominators) {
	Fraction f1(3, 4);
	Fraction f2(1, 2);
	f1 -= f2;
	EXPECT_EQ(1, f1.getNumerator());
	EXPECT_EQ(4, f1.getDenominator());
}

TEST(FractionTestSubtraction, SubtractAndAssignNegativeFraction) {
	Fraction f1(6, 7);
	Fraction f2(-1, 7);
	f1 -= f2;
	EXPECT_EQ(1, f1.getNumerator());
	EXPECT_EQ(1, f1.getDenominator());
}

TEST(FractionTestSubtraction, SubtractAndAssignFractionToZero) {
	Fraction f1(0, 1);
	Fraction f2(2, 3);
	f1 -= f2;
	EXPECT_EQ(-2, f1.getNumerator());
	EXPECT_EQ(3, f1.getDenominator());
}

TEST(FractionTestMultiplication, MultiplyFractions)
{
  Fraction f1(3, 4);
  Fraction f2(1, 2);
  Fraction f3 = f1 * f2;
  EXPECT_EQ(3, f3.getNumerator());
  EXPECT_EQ(8, f3.getDenominator());
}

// Add more tests for multiplication operator
TEST(FractionTestMultiplication, MultiplyFractionByItself) {
	Fraction f1(2, 3);
	Fraction result = f1 * f1;
	EXPECT_EQ(4, result.getNumerator());
	EXPECT_EQ(9, result.getDenominator());
}

TEST(FractionTestMultiplication, MultiplyByInverse) {
	Fraction f1(3, 4);
	Fraction f2(4, 3);
	Fraction result = f1 * f2;
	EXPECT_EQ(1, result.getNumerator());
	EXPECT_EQ(1, result.getDenominator());
}

TEST(FractionTestMultiplication, MultiplyByNegativeFraction) {
	Fraction f1(-2, 5);
	Fraction f2(3, 7);
	Fraction result = f1 * f2;
	EXPECT_EQ(-6, result.getNumerator());
	EXPECT_EQ(35, result.getDenominator());
}
TEST(FractionTestMultiplication, MultiplyAndAssignFractions)
{
	Fraction f1(3, 4);
	Fraction f2(1, 2);
	f1 *= f2;
	EXPECT_EQ(3, f1.getNumerator());
	EXPECT_EQ(8, f1.getDenominator());
}

// Add more tests for multiplication assignment operator
TEST(FractionTestMultiplication, MultiplyAndAssignByInverse) {
	Fraction f1(4, 5);
	Fraction f2(5, 4);
	f1 *= f2;
	EXPECT_EQ(1, f1.getNumerator());
	EXPECT_EQ(1, f1.getDenominator());
}

TEST(FractionTestMultiplication, MultiplyAndAssignByNegativeFraction) {
	Fraction f1(3, 8);
	Fraction f2(-2, 3);
	f1 *= f2;
	EXPECT_EQ(-1, f1.getNumerator());
	EXPECT_EQ(4, f1.getDenominator());
}

TEST(FractionTestMultiplication, MultiplyAndAssignFractionByZero) {
	Fraction f1(1, 3);
	Fraction f2(0, 1);
	f1 *= f2;
	EXPECT_EQ(0, f1.getNumerator());
	EXPECT_EQ(1, f1.getDenominator());
}
TEST(FractionTestDivision, DivideZeroByNotZeroFractions)
{
	Fraction f1(0, 1);
	Fraction f2(23, 7);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(0, f3.getNumerator());
	EXPECT_EQ(1, f3.getDenominator());
}

TEST(FractionTestDivision, DivideNotZeroByZeroFractions)
{
	Fraction f1(-3, 35);
	Fraction f2(0, 1);
	EXPECT_THROW(f1 / f2, std::domain_error);
}

TEST(FractionTestDivision, DivideZeroByZeroFractions)
{
	Fraction f1(0, 1);
	Fraction f2(0, 1);
	EXPECT_THROW(f1 / f2, std::domain_error);
}

TEST(FractionTestDivision, DivideFractions)
{
	Fraction f1(3, 4);
	Fraction f2(2, 1);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(3, f3.getNumerator());
	EXPECT_EQ(8, f3.getDenominator());
}

TEST(FractionTestDivision, DividePositiveAndNegativeFractions)
{
	Fraction f1(4, 3);
	Fraction f2(-1, 2);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(-8, f3.getNumerator());
	EXPECT_EQ(3, f3.getDenominator());
}

TEST(FractionTestDivision, DivideNegativeAndPositiveFractions)
{
	Fraction f1(-3, 4);
	Fraction f2(2, 1);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(-3, f3.getNumerator());
	EXPECT_EQ(8, f3.getDenominator());
}

TEST(FractionTestDivision, DivideNegativeAndNegativeFractions)
{
	Fraction f1(-3, 4);
	Fraction f2(2, -5);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(15, f3.getNumerator());
	EXPECT_EQ(8, f3.getDenominator());
}

TEST(FractionTestDivision, DivideFractionsRequiersNormalization)
{
	Fraction f1(3, 28);
	Fraction f2(6, 7);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(1, f3.getNumerator());
	EXPECT_EQ(8, f3.getDenominator());
}

TEST(FractionTestDivision, DividePositiveAndNegativeFractionsRequiersNormalization)
{
	Fraction f1(3, 28);
	Fraction f2(6, -7);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(-1, f3.getNumerator());
	EXPECT_EQ(8, f3.getDenominator());
}

TEST(FractionTestDivision, DivideNegativeAndPositiveFractionsRequiersNormalization)
{
	Fraction f1(-3, 28);
	Fraction f2(6, 7);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(-1, f3.getNumerator());
	EXPECT_EQ(8, f3.getDenominator());
}

TEST(FractionTestDivision, DivideNegativeAndNegativeFractionsRequiersNormalization)
{
	Fraction f1(-3, 28);
	Fraction f2(6, -7);
	Fraction f3 = f1 / f2;
	EXPECT_EQ(1, f3.getNumerator());
	EXPECT_EQ(8, f3.getDenominator());
}


TEST(FractionTestDivision, DivideAndAssignZeroByNotZeroFractions)
{
	Fraction f1(0, 1);
	Fraction f2(23, 7);
	f1 /= f2;
	EXPECT_EQ(0, f1.getNumerator());
	EXPECT_EQ(1, f1.getDenominator());
}

TEST(FractionTestDivision, DivideAndAssignNotZeroByZeroFractions)
{
	Fraction f1(-3, 35);
	Fraction f2(0, 1);
	EXPECT_THROW(f1 /= f2, std::domain_error);
}

TEST(FractionTestDivision, DivideAndAssignZeroByZeroFractions)
{
	Fraction f1(0, 1);
	Fraction f2(0, 1);
	EXPECT_THROW(f1 /= f2, std::domain_error);
}

TEST(FractionTestDivision, DivideAndAssignFractions)
{
	Fraction f1(3, 4);
	Fraction f2(2, 1);
	f1 /= f2;
	EXPECT_EQ(3, f1.getNumerator());
	EXPECT_EQ(8, f1.getDenominator());
}

TEST(FractionTestDivision, DivideAndAssignPositiveAndNegativeFractions)
{
	Fraction f1(4, 3);
	Fraction f2(-1, 2);
	f1 /= f2;
	EXPECT_EQ(-8, f1.getNumerator());
	EXPECT_EQ(3, f1.getDenominator());
}

TEST(FractionTestDivision, DivideAndAssignNegativeAndPositiveFractions)
{
	Fraction f1(-3, 4);
	Fraction f2(2, 1);
	f1 /= f2;
	EXPECT_EQ(-3, f1.getNumerator());
	EXPECT_EQ(8, f1.getDenominator());
}

TEST(FractionTestDivision, DivideAndAssignNegativeAndNegativeFractions)
{
	Fraction f1(-3, 4);
	Fraction f2(2, -5);
	f1 /= f2;
	EXPECT_EQ(15, f1.getNumerator());
	EXPECT_EQ(8, f1.getDenominator());
}

TEST(FractionTestDivision, DivideAndAssignFractionsRequiersNormalization)
{
	Fraction f1(3, 28);
	Fraction f2(6, 7);
	f1 /= f2;
	EXPECT_EQ(1, f1.getNumerator());
	EXPECT_EQ(8, f1.getDenominator());
}

TEST(FractionTestDivision, DivideAndAssignPositiveAndNegativeFractionsRequiersNormalization)
{
	Fraction f1(3, 28);
	Fraction f2(6, -7);
	f1 /= f2;
	EXPECT_EQ(-1, f1.getNumerator());
	EXPECT_EQ(8, f1.getDenominator());
}

TEST(FractionTestDivision, DivideAndAssignNegativeAndPositiveFractionsRequiersNormalization)
{
	Fraction f1(-3, 28);
	Fraction f2(6, 7);
	f1 /= f2;
	EXPECT_EQ(-1, f1.getNumerator());
	EXPECT_EQ(8, f1.getDenominator());
}

TEST(FractionTestDivision, DivideAndAssignNegativeAndNegativeFractionsRequiersNormalization)
{
	Fraction f1(-3, 28);
	Fraction f2(6, -7);
	f1 /= f2;
	EXPECT_EQ(1, f1.getNumerator());
	EXPECT_EQ(8, f1.getDenominator());
}

TEST(FractionTestConvert, ConvertFractionToDouble)
{
  Fraction f(3, 4);
  double d = f;
  EXPECT_DOUBLE_EQ(0.75, d);
}

TEST(FractionTestConvert, ConvertNegativeFractionToDouble)
{
	Fraction f(-3, 42);
	double d = f;
	EXPECT_NEAR(-0.0714, d, 0.0001);
}

TEST(FractionTestUnaryMinus, UnaryMinus)
{
  Fraction f(3, 4);
  Fraction f2 = -f;
  EXPECT_EQ(-3, f2.getNumerator());
  EXPECT_EQ(4, f2.getDenominator());
}

//Add more tests for unary minus operator
TEST(FractionTestUnaryMinus, UnaryMinusOnNegativeFraction) {
	Fraction f(-5, 6);
	Fraction result = -f;
	EXPECT_EQ(5, result.getNumerator());
	EXPECT_EQ(6, result.getDenominator());
}

TEST(FractionTestUnaryMinus, UnaryMinusOnZeroFraction) {
	Fraction f(0, 1);
	Fraction result = -f;
	EXPECT_EQ(0, result.getNumerator());
	EXPECT_EQ(1, result.getDenominator());
}

TEST(FractionTestUnaryMinus, DoubleUnaryMinus) {
	Fraction f(7, 8);
	Fraction result = -(-f);
	EXPECT_EQ(7, result.getNumerator());
	EXPECT_EQ(8, result.getDenominator());
}

//Add tests for comparison operators
TEST(FractionTestComparison, EqualFractions) {
	Fraction f1(3, 4);
	Fraction f2(3, 4);
	EXPECT_TRUE(f1 == f2);
}

TEST(FractionTestComparison, NotEqualFractionsDifferentNumerator) {
	Fraction f1(3, 4);
	Fraction f2(2, 4);
	EXPECT_TRUE(f1 != f2);
}

TEST(FractionTestComparison, NotEqualFractionsDifferentDenominator) {
	Fraction f1(3, 4);
	Fraction f2(3, 5);
	EXPECT_TRUE(f1 != f2);
}

TEST(FractionTestComparison, LessThan) {
	Fraction f1(1, 2);
	Fraction f2(2, 3);
	EXPECT_TRUE(f1 < f2);
}

TEST(FractionTestComparison, LessThanOrEqualLess) {
	Fraction f1(1, 3);
	Fraction f2(2, 3);
	EXPECT_TRUE(f1 <= f2);
}

TEST(FractionTestComparison, LessThanOrEqualEqual) {
	Fraction f1(4, 5);
	Fraction f2(4, 5);
	EXPECT_TRUE(f1 <= f2);
}

TEST(FractionTestComparison, GreaterThan) {
	Fraction f1(3, 4);
	Fraction f2(2, 4);
	EXPECT_TRUE(f1 > f2);
}

TEST(FractionTestComparison, GreaterThanOrEqualGreater) {
	Fraction f1(3, 2);
	Fraction f2(1, 2);
	EXPECT_TRUE(f1 >= f2);
}

TEST(FractionTestComparison, GreaterThanOrEqualEqual) {
	Fraction f1(5, 7);
	Fraction f2(5, 7);
	EXPECT_TRUE(f1 >= f2);
}

TEST(FractionTestInputOutput, OutputFractionEqualsZero)
{
	Fraction f(0, 1);
	std::ostringstream os;
	os << f;
	EXPECT_EQ("0", os.str());
}

TEST(FractionTestInputOutput, OutputFraction)
{
  Fraction f(3, 4);
  std::ostringstream os;
  os << f;
  EXPECT_EQ("3/4", os.str());
}

TEST(FractionTestInputOutput, OutputNegativeFraction)
{
	Fraction f(-13, 4);
	std::ostringstream os;
	os << f;
	EXPECT_EQ("-13/4", os.str());
}

TEST(FractionTestInputOutput, OutputFractionWithDenominatorEqualsOne)
{
	Fraction f(9, 1);
	std::ostringstream os;
	os << f;
	EXPECT_EQ("9", os.str());
}

TEST(FractionTestInputOutput, OutputNegativeFractionWithDenominatorEqualsOne)
{
	Fraction f(-23, 1);
	std::ostringstream os;
	os << f;
	EXPECT_EQ("-23", os.str());
}

TEST(FractionTestInputOutput, InputFractionEqualsZero)
{
	Fraction f;
	std::istringstream is("0 ");
	is >> f;
	EXPECT_EQ(0, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestInputOutput, InputFractionEqualsZeroWithDenominatorEqualsOne)
{
	Fraction f;
	std::istringstream is("0/1");
	is >> f;
	EXPECT_EQ(0, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestInputOutput, InputFractionEqualsZeroWitNegativeDenominator)
{
	Fraction f;
	std::istringstream is("0/-1");
	is >> f;
	EXPECT_EQ(0, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestInputOutput, InputFractionEqualsZeroRequiersNormalization)
{
	Fraction f;
	std::istringstream is("0/34");
	is >> f;
	EXPECT_EQ(0, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestInputOutput, InputFractionEqualsZeroWitNegativeDenominatorRequiersNormalization)
{
	Fraction f;
	std::istringstream is("0/-34");
	is >> f;
	EXPECT_EQ(0, f.getNumerator());
	EXPECT_EQ(1, f.getDenominator());
}

TEST(FractionTestInputOutput, InputFraction)
{
  Fraction f;
  std::istringstream is("3/4");
  is >> f;
  EXPECT_EQ(3, f.getNumerator());
  EXPECT_EQ(4, f.getDenominator());
}

TEST(FractionTestInputOutput, InputNegativeFraction)
{
	Fraction f;
	std::istringstream is("-13/47");
	is >> f;
	EXPECT_EQ(-13, f.getNumerator());
	EXPECT_EQ(47, f.getDenominator());
}

TEST(FractionTestInputOutput, InputPositiveFractionwithNegativeDenominator)
{
	Fraction f;
	std::istringstream is("-13/-47");
	is >> f;
	EXPECT_EQ(13, f.getNumerator());
	EXPECT_EQ(47, f.getDenominator());
}

TEST(FractionTestInputOutput, InputNegativeFractionwithNegativeDenominator)
{
	Fraction f;
	std::istringstream is("13/-47");
	is >> f;
	EXPECT_EQ(-13, f.getNumerator());
	EXPECT_EQ(47, f.getDenominator());
}

TEST(FractionTestInputOutput, InputFractionRequiersNormalization)
{
	Fraction f;
	std::istringstream is("6/8");
	is >> f;
	EXPECT_EQ(3, f.getNumerator());
	EXPECT_EQ(4, f.getDenominator());
}

TEST(FractionTestInputOutput, InputNegativeFractionRequiersNormalization)
{
	Fraction f;
	std::istringstream is("-26/94");
	is >> f;
	EXPECT_EQ(-13, f.getNumerator());
	EXPECT_EQ(47, f.getDenominator());
}

TEST(FractionTestInputOutput, InputPositiveFractionwithNegativeDenominatorRequiersNormalization)
{
	Fraction f;
	std::istringstream is("-26/-94");
	is >> f;
	EXPECT_EQ(13, f.getNumerator());
	EXPECT_EQ(47, f.getDenominator());
}

TEST(FractionTestInputOutput, InputNegativeFractionwithNegativeDenominatorRequiersNormalization)
{
	Fraction f;
	std::istringstream is("26/-94");
	is >> f;
	EXPECT_EQ(-13, f.getNumerator());
	EXPECT_EQ(47, f.getDenominator());
}

TEST(FractionTestInputOutput, InputFractionWithInvalidDenominatorEqualsZero)
{
  Fraction f;
  std::istringstream is("3/0");
  EXPECT_THROW(is >> f, std::invalid_argument);
}
