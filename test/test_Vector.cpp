#include <gtest.h>
#include "MyVector.h"

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4, 1);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v1(4);

  TVector<int> v2(v1);

  EXPECT_EQ(v1, v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v1(4);
  TVector<int> v2(v1);
  v1[0] = 5;

  EXPECT_NE(v1[0], v2[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<int> v1(4);

  ASSERT_ANY_THROW(v1[-5]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v1(4);

  ASSERT_ANY_THROW(v1[5]);
}

TEST(TVector, can_assign_vector_to_itself)
{
  ASSERT_NO_THROW(TVector<TVector<int> > v2());
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v1(4);
  TVector<int> v2(4);

  ASSERT_NO_THROW(v2 = v1);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v1(4);
  TVector<int> v2(5);

  ASSERT_NO_THROW(v2 = v1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v1(1);
  v1[0] = 10;
  TVector<int> v2(1);
  v2[0] = 10;

  EXPECT_EQ(v1 == v2, true);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v1(10);

  EXPECT_EQ(v1 == v1, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v1(10);
  TVector<int> v2(20);

  EXPECT_EQ(v1 == v2, false);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> v1(2);
  v1[0] = 10;
  v1[1] = 20;

  TVector<int> res(2);
  res[0] = 12;
  res[1] = 22;

  EXPECT_EQ(v1 + 2, res);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v1(2);
  v1[0] = 4;
  v1[1] = 4;
  TVector<int> res(2);
  res[0] = 2;
  res[1] = 2;

  EXPECT_EQ(v1 - 2, res);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  TVector<int> v1(2);
  v1[0] = 4;
  v1[1] = 4;
  TVector<int> res(2);
  res[0] = 8;
  res[1] = 8;

  EXPECT_EQ(v1 * 2, res);
}

TEST(TVector, can_divide_scalar_by_vector)
{
  TVector<int> v1(2);
  v1[0] = 4;
  v1[1] = 4;
  TVector<int> res(2);
  res[0] = 2;
  res[1] = 2;

  EXPECT_EQ(v1 / 2, res);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> v1(10);
  TVector<int> v2(10);

  ASSERT_NO_THROW(v2 - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> v1(20, 10);
  TVector<int> v2(10, 5);

  ASSERT_ANY_THROW(v2 - v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> v1(10);
  TVector<int> v2(10);

  ASSERT_NO_THROW(v2 * v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v1(20, 10);
  TVector<int> v2(10, 5);

  ASSERT_ANY_THROW(v2 * v1);
}
