// This file is a part of toml++ and is subject to the the terms of the MIT license.
// Copyright (c) 2019-2020 Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/tomlplusplus/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT
//-----
// this file was generated by generate_conformance_tests.py - do not modify it directly

#include "tests.h"
using namespace toml::impl;

TOML_PUSH_WARNINGS
TOML_DISABLE_ALL_WARNINGS // unused variable spam

namespace
{
	static constexpr auto array_empty = R"(thevoid = [[[[[]]]]])"sv;
	static constexpr auto array_nospaces = R"(ints = [1,2,3])"sv;
	static constexpr auto array_string_quote_comma_2 = R"(title = [ " \", ",])"sv;
	static constexpr auto array_string_quote_comma = R"(title = [
"Client: \"XXXX\", Job: XXXX",
"Code: XXXX"
])"sv;
	static constexpr auto array_string_with_comma = R"(title = [
"Client: XXXX, Job: XXXX",
"Code: XXXX"
])"sv;
	static constexpr auto array_table_array_string_backslash = R"(foo = [ { bar="\"{{baz}}\""} ])"sv;
	static constexpr auto arrays_hetergeneous = R"(mixed = [[1, 2], ["a", "b"], [1.1, 2.1]])"sv;
	static constexpr auto arrays_nested = R"(nest = [["a"], ["b"]])"sv;
	static constexpr auto arrays = R"(ints = [1, 2, 3]
floats = [1.1, 2.1, 3.1]
strings = ["a", "b", "c"]
dates = [
  1987-07-05T17:45:00Z,
  1979-05-27T07:32:00Z,
  2006-06-01T11:00:00Z,
]
comments = [
         1,
         2, #this is ok
])"sv;
	static constexpr auto bool_ = R"(t = true
f = false)"sv;
	static constexpr auto comments_at_eof = R"(# This is a full-line comment
key = "value" # This is a comment at the end of a line)"sv;
	static constexpr auto comments_at_eof2 = R"(# This is a full-line comment
key = "value" # This is a comment at the end of a line)"sv;
	static constexpr auto comments_everywhere = R"(# Top comment.
  # Top comment.
# Top comment.

# [no-extraneous-groups-please]

[group] # Comment
answer = 42 # Comment
# no-extraneous-keys-please = 999
# Inbetween comment.
more = [ # Comment
  # What about multiple # comments?
  # Can you handle it?
  #
          # Evil.
# Evil.
  42, 42, # Comments within arrays are fun.
  # What about multiple # comments?
  # Can you handle it?
  #
          # Evil.
# Evil.
# ] Did I fool you?
] # Hopefully not.)"sv;
	static constexpr auto datetime_timezone = R"(bestdayever = 2017-06-06T12:34:56-05:00)"sv;
	static constexpr auto double_quote_escape = R"(test = "\"one\"")"sv;
	static constexpr auto empty = R"()"sv;
	static constexpr auto escaped_escape = R"(answer = "\\x64")"sv;
	static constexpr auto example = R"(best-day-ever = 1987-07-05T17:45:00Z

[numtheory]
boring = false
perfection = [6, 28, 496])"sv;
	static constexpr auto exponent_part_float = R"(million = 1e6
minustenth = -1E-1
beast = 6.66E2)"sv;
	static constexpr auto float_exponent = R"(lower = 3e2
upper = 3E2
neg = 3e-2
pos = 3E+2
zero = 3e0
pointlower = 3.1e2
pointupper = 3.1E2)"sv;
	static constexpr auto float_underscore = R"(before = 3_141.5927
after = 3141.592_7
exponent = 3e1_4)"sv;
	static constexpr auto float_ = R"(pi = 3.14
pospi = +3.14
negpi = -3.14
zero-intpart = 0.123)"sv;
	static constexpr auto implicit_and_explicit_after = R"([a.b.c]
answer = 42

[a]
better = 43)"sv;
	static constexpr auto implicit_and_explicit_before = R"([a]
better = 43

[a.b.c]
answer = 42)"sv;
	static constexpr auto implicit_groups = R"([a.b.c]
answer = 42)"sv;
	static constexpr auto inline_table_array = R"(people = [{first_name = "Bruce", last_name = "Springsteen"},
          {first_name = "Eric", last_name = "Clapton"},
          {first_name = "Bob", last_name = "Seger"}])"sv;
	static constexpr auto inline_table = R"(name = { first = "Tom", last = "Preston-Werner" }
point = { x = 1, y = 2 }
simple = { a = 1 }
str-key = { "a" = 1 }
table-array = [{ "a" = 1 }, { "b" = 2 }])"sv;
	static constexpr auto integer_underscore = R"(kilo = 1_000)"sv;
	static constexpr auto integer = R"(answer = 42
posanswer = +42
neganswer = -42
zero = 0)"sv;
	static constexpr auto key_equals_nospace = R"(answer=42)"sv;
	static constexpr auto key_numeric = R"(1 = 1)"sv;
	static constexpr auto key_space = R"("a b" = 1)"sv;
	static constexpr auto key_special_chars = R"("~!@$^&*()_+-`1234567890[]|/?><.,;:'" = 1)"sv;
	static constexpr auto keys_with_dots = R"(plain = 1
"with.dot" = 2

[plain_table]
plain = 3
"with.dot" = 4

[table.withdot]
plain = 5
"key.with.dots" = 6)"sv;
	static constexpr auto long_float = R"(longpi = 3.141592653589793
neglongpi = -3.141592653589793)"sv;
	static constexpr auto long_integer = R"(answer = 9223372036854775807
neganswer = -9223372036854775808)"sv;
	static constexpr auto multiline_string = R"(multiline_empty_one = """"""
multiline_empty_two = """
"""
multiline_empty_three = """\
    """
multiline_empty_four = """\
   \
   \
   """

equivalent_one = "The quick brown fox jumps over the lazy dog."
equivalent_two = """
The quick brown \


  fox jumps over \
    the lazy dog."""

equivalent_three = """\
       The quick brown \
       fox jumps over \
       the lazy dog.\
       """)"sv;
	static constexpr auto nested_inline_table_array = R"(a = [ { b = {} } ])"sv;
	static constexpr auto newline_crlf = R"(os = "DOS"
newline = "crlf")"sv;
	static constexpr auto newline_lf = R"(os = "unix"
newline = "lf")"sv;
	static constexpr auto raw_multiline_string = R"(oneline = '''This string has a ' quote character.'''
firstnl = '''
This string has a ' quote character.'''
multiline = '''
This string
has ' a quote character
and more than
one newline
in it.''')"sv;
	static constexpr auto raw_string = R"(backspace = 'This string has a \b backspace character.'
tab = 'This string has a \t tab character.'
newline = 'This string has a \n new line character.'
formfeed = 'This string has a \f form feed character.'
carriage = 'This string has a \r carriage return character.'
slash = 'This string has a \/ slash character.'
backslash = 'This string has a \\ backslash character.')"sv;
	static constexpr auto right_curly_brace_after_boolean = R"(black = { python=">3.6", version=">=18.9b0", allow_prereleases=true })"sv;
	static constexpr auto string_empty = R"(answer = "")"sv;
	static constexpr auto string_nl = R"(nl_mid = "val\nue"
nl_end = """value\n"""

lit_nl_end = '''value\n'''
lit_nl_mid = 'val\nue'
lit_nl_uni = 'val\ue')"sv;
	static constexpr auto string_simple = R"(answer = "You are not drinking enough whisky.")"sv;
	static constexpr auto string_with_pound = R"(pound = "We see no # comments here."
poundcomment = "But there are # some comments here." # Did I # mess you up?)"sv;
	static constexpr auto table_array_implicit = R"([[albums.songs]]
name = "Glory Days")"sv;
	static constexpr auto table_array_many = R"([[people]]
first_name = "Bruce"
last_name = "Springsteen"

[[people]]
first_name = "Eric"
last_name = "Clapton"

[[people]]
first_name = "Bob"
last_name = "Seger")"sv;
	static constexpr auto table_array_nest = R"([[albums]]
name = "Born to Run"

  [[albums.songs]]
  name = "Jungleland"

  [[albums.songs]]
  name = "Meeting Across the River"

[[albums]]
name = "Born in the USA"
  
  [[albums.songs]]
  name = "Glory Days"

  [[albums.songs]]
  name = "Dancing in the Dark")"sv;
	static constexpr auto table_array_one = R"([[people]]
first_name = "Bruce"
last_name = "Springsteen")"sv;
	static constexpr auto table_array_table_array = R"([[a]]
    [[a.b]]
        [a.b.c]
            d = "val0"
    [[a.b]]
        [a.b.c]
            d = "val1")"sv;
	static constexpr auto table_empty = R"([a])"sv;
	static constexpr auto table_no_eol = R"([table])"sv;
	static constexpr auto table_sub_empty = R"([a]
[a.b])"sv;
	static constexpr auto table_whitespace = R"(["valid key"])"sv;
	static constexpr auto table_with_literal_string = R"(['a']
[a.'"b"']
[a.'"b"'.c]
answer = 42)"sv;
	static constexpr auto table_with_pound = R"(["key#group"]
answer = 42)"sv;
	static constexpr auto table_with_single_quotes = R"(['a']
[a.'b']
[a.'b'.c]
answer = 42)"sv;
	static constexpr auto underscored_float = R"(electron_mass = 9_109.109_383e-3_4)"sv;
	static constexpr auto underscored_integer = R"(million = 1_000_000)"sv;
	static constexpr auto unicode_escape = R"(answer4 = "\u03B4"
answer8 = "\U000003B4")"sv;
	#if UNICODE_LITERALS_OK
	static constexpr auto unicode_literal = R"(answer = "δ")"sv;
	#endif // UNICODE_LITERALS_OK
}

TOML_POP_WARNINGS

TEST_CASE("conformance - burntsushi/valid")
{
	parsing_should_succeed(FILE_LINE_ARGS, array_empty, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(thevoid)"sv, toml::array{
					toml::inserter{toml::array{
						toml::inserter{toml::array{
							toml::inserter{toml::array{
								toml::inserter{toml::array{}},
							}},
						}},
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, array_nospaces, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(ints)"sv, toml::array{
					1,
					2,
					3,
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, array_string_quote_comma_2, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(title)"sv, toml::array{
					R"( ", )"sv,
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, array_string_quote_comma, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(title)"sv, toml::array{
					R"(Client: "XXXX", Job: XXXX)"sv,
					R"(Code: XXXX)"sv,
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, array_string_with_comma, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(title)"sv, toml::array{
					R"(Client: XXXX, Job: XXXX)"sv,
					R"(Code: XXXX)"sv,
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, array_table_array_string_backslash, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(foo)"sv, toml::array{
					toml::table{{
						{ R"(bar)"sv, R"("{{baz}}")"sv },
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, arrays_hetergeneous, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(mixed)"sv, toml::array{
					toml::array{
						1,
						2,
					},
					toml::array{
						R"(a)"sv,
						R"(b)"sv,
					},
					toml::array{
						1.1,
						2.1,
					},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, arrays_nested, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(nest)"sv, toml::array{
					toml::array{
						R"(a)"sv,
					},
					toml::array{
						R"(b)"sv,
					},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, arrays, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(ints)"sv, toml::array{
					1,
					2,
					3,
				}
			},
			{ 
				R"(floats)"sv, toml::array{
					1.1,
					2.1,
					3.1,
				}
			},
			{ 
				R"(strings)"sv, toml::array{
					R"(a)"sv,
					R"(b)"sv,
					R"(c)"sv,
				}
			},
			{ 
				R"(dates)"sv, toml::array{
					toml::date_time{ { 1987, 7, 5 }, { 17, 45, 0, 0u }, { 0, 0 } },
					toml::date_time{ { 1979, 5, 27 }, { 7, 32, 0, 0u }, { 0, 0 } },
					toml::date_time{ { 2006, 6, 1 }, { 11, 0, 0, 0u }, { 0, 0 } },
				}
			},
			{ 
				R"(comments)"sv, toml::array{
					1,
					2,
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, bool_, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(f)"sv, false },
			{ R"(t)"sv, true },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, comments_at_eof, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(key)"sv, R"(value)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, comments_at_eof2, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(key)"sv, R"(value)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, comments_everywhere, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(group)"sv, toml::table{{
					{ R"(answer)"sv, 42 },
					{ 
						R"(more)"sv, toml::array{
							42,
							42,
						}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, datetime_timezone, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(bestdayever)"sv, toml::date_time{ { 2017, 6, 6 }, { 12, 34, 56, 0u }, { -5, 0 } } },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, double_quote_escape, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(test)"sv, R"("one")"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, empty, [](toml::table&& tbl)
	{
		auto expected = toml::table{};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, escaped_escape, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(answer)"sv, R"(\x64)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, example, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(best-day-ever)"sv, toml::date_time{ { 1987, 7, 5 }, { 17, 45, 0, 0u }, { 0, 0 } } },
			{ 
				R"(numtheory)"sv, toml::table{{
					{ R"(boring)"sv, false },
					{ 
						R"(perfection)"sv, toml::array{
							6,
							28,
							496,
						}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, exponent_part_float, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(million)"sv, 1000000.0 },
			{ R"(minustenth)"sv, -0.1 },
			{ R"(beast)"sv, 666.0 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, float_exponent, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(lower)"sv, 300.0 },
			{ R"(upper)"sv, 300.0 },
			{ R"(neg)"sv, 0.03 },
			{ R"(pos)"sv, 300.0 },
			{ R"(zero)"sv, 3.0 },
			{ R"(pointlower)"sv, 310.0 },
			{ R"(pointupper)"sv, 310.0 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, float_underscore, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(before)"sv, 3141.5927 },
			{ R"(after)"sv, 3141.5927 },
			{ R"(exponent)"sv, 300000000000000.0 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, float_, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(pi)"sv, 3.14 },
			{ R"(pospi)"sv, 3.14 },
			{ R"(negpi)"sv, -3.14 },
			{ R"(zero-intpart)"sv, 0.123 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, implicit_and_explicit_after, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(a)"sv, toml::table{{
					{ R"(better)"sv, 43 },
					{ 
						R"(b)"sv, toml::table{{
							{ 
								R"(c)"sv, toml::table{{
									{ R"(answer)"sv, 42 },
								}}
							},
						}}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, implicit_and_explicit_before, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(a)"sv, toml::table{{
					{ R"(better)"sv, 43 },
					{ 
						R"(b)"sv, toml::table{{
							{ 
								R"(c)"sv, toml::table{{
									{ R"(answer)"sv, 42 },
								}}
							},
						}}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, implicit_groups, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(a)"sv, toml::table{{
					{ 
						R"(b)"sv, toml::table{{
							{ 
								R"(c)"sv, toml::table{{
									{ R"(answer)"sv, 42 },
								}}
							},
						}}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, inline_table_array, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(people)"sv, toml::array{
					toml::table{{
						{ R"(first_name)"sv, R"(Bruce)"sv },
						{ R"(last_name)"sv, R"(Springsteen)"sv },
					}},
					toml::table{{
						{ R"(first_name)"sv, R"(Eric)"sv },
						{ R"(last_name)"sv, R"(Clapton)"sv },
					}},
					toml::table{{
						{ R"(first_name)"sv, R"(Bob)"sv },
						{ R"(last_name)"sv, R"(Seger)"sv },
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, inline_table, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(name)"sv, toml::table{{
					{ R"(first)"sv, R"(Tom)"sv },
					{ R"(last)"sv, R"(Preston-Werner)"sv },
				}}
			},
			{ 
				R"(point)"sv, toml::table{{
					{ R"(x)"sv, 1 },
					{ R"(y)"sv, 2 },
				}}
			},
			{ 
				R"(simple)"sv, toml::table{{
					{ R"(a)"sv, 1 },
				}}
			},
			{ 
				R"(str-key)"sv, toml::table{{
					{ R"(a)"sv, 1 },
				}}
			},
			{ 
				R"(table-array)"sv, toml::array{
					toml::table{{
						{ R"(a)"sv, 1 },
					}},
					toml::table{{
						{ R"(b)"sv, 2 },
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, integer_underscore, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(kilo)"sv, 1000 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, integer, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(answer)"sv, 42 },
			{ R"(neganswer)"sv, -42 },
			{ R"(posanswer)"sv, 42 },
			{ R"(zero)"sv, 0 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, key_equals_nospace, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(answer)"sv, 42 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, key_numeric, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(1)"sv, 1 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, key_space, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(a b)"sv, 1 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, key_special_chars, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(~!@$^&*()_+-`1234567890[]|/?><.,;:')"sv, 1 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, keys_with_dots, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(plain)"sv, 1 },
			{ R"(with.dot)"sv, 2 },
			{ 
				R"(plain_table)"sv, toml::table{{
					{ R"(plain)"sv, 3 },
					{ R"(with.dot)"sv, 4 },
				}}
			},
			{ 
				R"(table)"sv, toml::table{{
					{ 
						R"(withdot)"sv, toml::table{{
							{ R"(plain)"sv, 5 },
							{ R"(key.with.dots)"sv, 6 },
						}}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, long_float, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(longpi)"sv, 3.141592653589793 },
			{ R"(neglongpi)"sv, -3.141592653589793 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, long_integer, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(answer)"sv, INT64_MAX },
			{ R"(neganswer)"sv, INT64_MIN },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, multiline_string, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(multiline_empty_one)"sv, R"()"sv },
			{ R"(multiline_empty_two)"sv, R"()"sv },
			{ R"(multiline_empty_three)"sv, R"()"sv },
			{ R"(multiline_empty_four)"sv, R"()"sv },
			{ R"(equivalent_one)"sv, R"(The quick brown fox jumps over the lazy dog.)"sv },
			{ R"(equivalent_two)"sv, R"(The quick brown fox jumps over the lazy dog.)"sv },
			{ R"(equivalent_three)"sv, R"(The quick brown fox jumps over the lazy dog.)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, nested_inline_table_array, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(a)"sv, toml::array{
					toml::table{{
						{ R"(b)"sv, toml::table{} },
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, newline_crlf, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(os)"sv, R"(DOS)"sv },
			{ R"(newline)"sv, R"(crlf)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, newline_lf, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(os)"sv, R"(unix)"sv },
			{ R"(newline)"sv, R"(lf)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, raw_multiline_string, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(oneline)"sv, R"(This string has a ' quote character.)"sv },
			{ R"(firstnl)"sv, R"(This string has a ' quote character.)"sv },
			{ R"(multiline)"sv, R"(This string
has ' a quote character
and more than
one newline
in it.)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, raw_string, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(backspace)"sv, R"(This string has a \b backspace character.)"sv },
			{ R"(tab)"sv, R"(This string has a \t tab character.)"sv },
			{ R"(newline)"sv, R"(This string has a \n new line character.)"sv },
			{ R"(formfeed)"sv, R"(This string has a \f form feed character.)"sv },
			{ R"(carriage)"sv, R"(This string has a \r carriage return character.)"sv },
			{ R"(slash)"sv, R"(This string has a \/ slash character.)"sv },
			{ R"(backslash)"sv, R"(This string has a \\ backslash character.)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, right_curly_brace_after_boolean, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(black)"sv, toml::table{{
					{ R"(allow_prereleases)"sv, true },
					{ R"(python)"sv, R"(>3.6)"sv },
					{ R"(version)"sv, R"(>=18.9b0)"sv },
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, string_empty, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(answer)"sv, R"()"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, string_nl, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(nl_mid)"sv, R"(val
ue)"sv },
			{ R"(nl_end)"sv, R"(value
)"sv },
			{ R"(lit_nl_end)"sv, R"(value\n)"sv },
			{ R"(lit_nl_mid)"sv, R"(val\nue)"sv },
			{ R"(lit_nl_uni)"sv, R"(val\ue)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, string_simple, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(answer)"sv, R"(You are not drinking enough whisky.)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, string_with_pound, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(pound)"sv, R"(We see no # comments here.)"sv },
			{ R"(poundcomment)"sv, R"(But there are # some comments here.)"sv },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_array_implicit, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(albums)"sv, toml::table{{
					{ 
						R"(songs)"sv, toml::array{
							toml::table{{
								{ R"(name)"sv, R"(Glory Days)"sv },
							}},
						}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_array_many, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(people)"sv, toml::array{
					toml::table{{
						{ R"(first_name)"sv, R"(Bruce)"sv },
						{ R"(last_name)"sv, R"(Springsteen)"sv },
					}},
					toml::table{{
						{ R"(first_name)"sv, R"(Eric)"sv },
						{ R"(last_name)"sv, R"(Clapton)"sv },
					}},
					toml::table{{
						{ R"(first_name)"sv, R"(Bob)"sv },
						{ R"(last_name)"sv, R"(Seger)"sv },
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_array_nest, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(albums)"sv, toml::array{
					toml::table{{
						{ R"(name)"sv, R"(Born to Run)"sv },
						{ 
							R"(songs)"sv, toml::array{
								toml::table{{
									{ R"(name)"sv, R"(Jungleland)"sv },
								}},
								toml::table{{
									{ R"(name)"sv, R"(Meeting Across the River)"sv },
								}},
							}
						},
					}},
					toml::table{{
						{ R"(name)"sv, R"(Born in the USA)"sv },
						{ 
							R"(songs)"sv, toml::array{
								toml::table{{
									{ R"(name)"sv, R"(Glory Days)"sv },
								}},
								toml::table{{
									{ R"(name)"sv, R"(Dancing in the Dark)"sv },
								}},
							}
						},
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_array_one, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(people)"sv, toml::array{
					toml::table{{
						{ R"(first_name)"sv, R"(Bruce)"sv },
						{ R"(last_name)"sv, R"(Springsteen)"sv },
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_array_table_array, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(a)"sv, toml::array{
					toml::table{{
						{ 
							R"(b)"sv, toml::array{
								toml::table{{
									{ 
										R"(c)"sv, toml::table{{
											{ R"(d)"sv, R"(val0)"sv },
										}}
									},
								}},
								toml::table{{
									{ 
										R"(c)"sv, toml::table{{
											{ R"(d)"sv, R"(val1)"sv },
										}}
									},
								}},
							}
						},
					}},
				}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_empty, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(a)"sv, toml::table{} },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_no_eol, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(table)"sv, toml::table{} },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_sub_empty, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(a)"sv, toml::table{{
					{ R"(b)"sv, toml::table{} },
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_whitespace, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(valid key)"sv, toml::table{} },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_with_literal_string, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(a)"sv, toml::table{{
					{ 
						R"("b")"sv, toml::table{{
							{ 
								R"(c)"sv, toml::table{{
									{ R"(answer)"sv, 42 },
								}}
							},
						}}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_with_pound, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(key#group)"sv, toml::table{{
					{ R"(answer)"sv, 42 },
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, table_with_single_quotes, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ 
				R"(a)"sv, toml::table{{
					{ 
						R"(b)"sv, toml::table{{
							{ 
								R"(c)"sv, toml::table{{
									{ R"(answer)"sv, 42 },
								}}
							},
						}}
					},
				}}
			},
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, underscored_float, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(electron_mass)"sv, 9.109109383e-31 },
		}};
		REQUIRE(tbl == expected);
	});

	parsing_should_succeed(FILE_LINE_ARGS, underscored_integer, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(million)"sv, 1000000 },
		}};
		REQUIRE(tbl == expected);
	});

	#if UNICODE_LITERALS_OK
	parsing_should_succeed(FILE_LINE_ARGS, unicode_escape, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(answer4)"sv, R"(δ)"sv },
			{ R"(answer8)"sv, R"(δ)"sv },
		}};
		REQUIRE(tbl == expected);
	});
	#endif // UNICODE_LITERALS_OK

	#if UNICODE_LITERALS_OK
	parsing_should_succeed(FILE_LINE_ARGS, unicode_literal, [](toml::table&& tbl)
	{
		auto expected = toml::table{{
			{ R"(answer)"sv, R"(δ)"sv },
		}};
		REQUIRE(tbl == expected);
	});
	#endif // UNICODE_LITERALS_OK

}
