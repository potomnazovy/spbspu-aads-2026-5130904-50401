#include <boost/test/unit_test.hpp>
#include "list.hpp"

BOOST_AUTO_TEST_SUITE(ListTests)
BOOST_AUTO_TEST_CASE(DefConstructTest)
{
  vasyakin::List< int > list;
  BOOST_CHECK_EQUAL(list.get_size(), 0);
  BOOST_CHECK(list.begin() == list.end());
}

BOOST_AUTO_TEST_CASE(ValConstructTest)
{
  vasyakin::List< int > list(52);
  BOOST_CHECK_EQUAL(list.get_size(), 1);
  BOOST_CHECK(list.begin() != list.end());
  BOOST_CHECK_EQUAL(*list.begin(), 52);
}

BOOST_AUTO_TEST_SUITE_END()