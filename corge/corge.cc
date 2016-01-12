#include <iostream>
#include "corge.h"
#include "corge_version.h"
#include "quux/quux.h"

const int Corge::version_major = corge_version_major;
const int Corge::version_minor = corge_version_minor;

Corge::Corge()
{
}

int
Corge::get_version() const
{
    return 10 * version_major + version_minor;
}

int
Corge::corgegate() const
{
    int corge_version = get_version();
    std::cout << "Corge::corgeifier version " << corge_version
              << " invoked\n";

    Quux quux;
    int quux_version = quux.quuxify();

    if(quux_version != corge_version) {
        throw std::runtime_error("Corge found an incompatible version of Garply.");
    }

    return corge_version;
}
