
#pragma once

#include <gtest/gtest.h>
#include "WeatherMock.h"
#include <cpr/cpr.h>

class WeatherTestCase : public ::testing::Test {
public:
    void SetUp() override;

    WeatherMock weatherMock;

    cpr::Response response_Paris;
    cpr::Response response_London;
    cpr::Response response_401;

};



