#!/usr/bin/env python
#
# A library that provides a Python interface to the Telegram Bot API
# Copyright (C) 2015-2020
# Leandro Toledo de Souza <devs@python-telegram-bot.org>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser Public License for more details.
#
# You should have received a copy of the GNU Lesser Public License
# along with this program.  If not, see [http://www.gnu.org/licenses/].

import pytest

from telegram import InputLocationMessageContent, Location


@pytest.fixture(scope='class')
def input_location_message_content():
    return InputLocationMessageContent(
        TestInputLocationMessageContent.latitude,
        TestInputLocationMessageContent.longitude,
        live_period=TestInputLocationMessageContent.live_period,
    )


class TestInputLocationMessageContent:
    latitude = -23.691288
    longitude = -46.788279
    live_period = 80

    def test_expected_values(self, input_location_message_content):
        assert input_location_message_content.longitude == self.longitude
        assert input_location_message_content.latitude == self.latitude
        assert input_location_message_content.live_period == self.live_period

    def test_to_dict(self, input_location_message_content):
        input_location_message_content_dict = input_location_message_content.to_dict()

        assert isinstance(input_location_message_content_dict, dict)
        assert (
            input_location_message_content_dict['latitude']
            == input_location_message_content.latitude
        )
        assert (
            input_location_message_content_dict['longitude']
            == input_location_message_content.longitude
        )
        assert (
            input_location_message_content_dict['live_period']
            == input_location_message_content.live_period
        )

    def test_equality(self):
        a = InputLocationMessageContent(123, 456, 70)
        b = InputLocationMessageContent(123, 456, 90)
        c = InputLocationMessageContent(123, 457, 70)
        d = Location(123, 456)

        assert a == b
        assert hash(a) == hash(b)

        assert a != c
        assert hash(a) != hash(c)

        assert a != d
        assert hash(a) != hash(d)
