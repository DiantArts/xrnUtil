#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// Basic
//
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////
auto ::xrn::util::File::getContent(
    const ::std::string& filename
)
    -> ::std::string
{
    ::std::FILE* f = ::std::fopen(filename.c_str(), "r");

    // Determine file size
    ::std::fseek(f, 0, SEEK_END);
    auto size = static_cast<::std::size_t>(::std::ftell(f));

    char* str = new char[size];
    ::std::rewind(f);
    ::std::fread(str, sizeof(char), size, f);

    return ::std::string{ str, size };
}

///////////////////////////////////////////////////////////////////////////
/// \brief Get the content of a file
///
///////////////////////////////////////////////////////////////////////////
auto ::xrn::util::File::getContentAsVector(
    const ::std::string& filename
) -> ::std::vector<::std::string>
{
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(lines, line)) {
       myLines.push_back(line);
    }
    return lines
}
