#include <stdexcept>

#include "corge/corge.h"

namespace {
bool
test_construct()
{
    Corge corge;
    return true;
}

bool
test_corgeifier()
{
    Corge corge;
    return (corge.corgegate() == corge.get_version());
}
}

int
main(int argc, char* argv[])
{
    if (!test_construct()) {
        throw std::runtime_error("test_construct failed");
    }
    if (!test_corgeifier()) {
        throw std::runtime_error("test_corgeifier failed");
    }

    return 0;
}
