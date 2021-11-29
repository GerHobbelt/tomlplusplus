// This file is a part of toml++ and is subject to the the terms of the MIT license.
// Copyright (c) Mark Gillard <mark.gillard@outlook.com.au>
// See https://github.com/marzer/tomlplusplus/blob/master/LICENSE for the full license text.
// SPDX-License-Identifier: MIT

// This example demonstrates how to parse TOML from a file or stdin and re-serialize it (print it out) to stdout.

#include "examples.h"

#define TOML_ENABLE_UNRELEASED_FEATURES 1
#include <toml++/toml.h>

using namespace std::string_view_literals;



#if defined(BUILD_MONOLITHIC)
#define main(cnt, arr)      toml_example_simplee_parser_main(cnt, arr)
#endif

int main(int argc, const char** argv)
{
	const auto path = argc > 1 ? std::string_view{ argv[1] } : "example.toml"sv;

	toml::table table;
	try
	{
		// read directly from stdin
		if (path == "-"sv || path.empty())
			table = toml::parse(std::cin, "stdin"sv);

		// read from a file
		else
			table = toml::parse_file(path);
	}
	catch (const toml::parse_error& err)
	{
		std::cerr << err << "\n";
		return 1;
	}

	std::cout << table << "\n";
	return 0;
}
