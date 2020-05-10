//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#include "WeatherTestCase.h"
#include "WeatherMock.h"

using ::testing::Return;

void WeatherTestCase::SetUp() {
    response_Paris.status_code = 200;
    response_Paris.text =
            "{\"cod\":\"200\",\"message\":0.0036,\"cnt\":40,\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":25.00}}]}";

    response_London.status_code = 200;
    response_London.text =
            "{\"cod\":\"200\",\"message\":0.0036,\"cnt\":40,\"list\":[{\"dt\":1485799200,\"main\":{\"temp\":20.00}}]}";

    response_401.status_code = 401;
}

TEST_F(WeatherTestCase, Test1) {
    EXPECT_CALL(weatherMock, Get("London"))
            .Times(1)
            .WillRepeatedly(Return(response_London));
    ASSERT_NO_THROW(weatherMock.Get("London"));
}

TEST_F(WeatherTestCase, Test2) {
    ASSERT_NO_THROW(weatherMock.SetApiKey("Key"));
}

TEST_F(WeatherTestCase, Test3) {
    EXPECT_CALL(weatherMock, Get("London"))
            .Times(1)
            .WillRepeatedly(Return(response_London));
    EXPECT_CALL(weatherMock, Get("Paris"))
            .Times(1)
            .WillRepeatedly(Return(response_Paris));

    ASSERT_EQ(weatherMock.GetDifferenceString("Paris", "London"),
              "Weather in Paris is warmer than in London by 5 degrees");
}

TEST_F(WeatherTestCase, Test4)
{
    EXPECT_CALL(weatherMock, Get("London"))
            .Times(1)
            .WillRepeatedly(Return(response_London));
    EXPECT_CALL(weatherMock, Get("Paris"))
            .Times(1)
            .WillRepeatedly(Return(response_Paris));

    ASSERT_EQ(weatherMock.GetDifferenceString("London", "Paris"),
              "Weather in London is colder than in Paris by 5 degrees");
}

TEST_F(WeatherTestCase, Test5)
{
    EXPECT_CALL(weatherMock, Get("NullResponse"))
            .Times(1)
            .WillRepeatedly(Return(response_401));

    ASSERT_THROW(weatherMock.GetResponseForCity("NullResponse"), std::invalid_argument);
}
